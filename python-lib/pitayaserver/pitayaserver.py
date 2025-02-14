from .route import Route
from google.protobuf import message
from ctypes import POINTER, byref, c_char, c_char_p, c_void_p, addressof, memmove, sizeof
from .gen.response_pb2 import Response
from .remote import BaseRemote
from .c_interop import SdConfig, NatsConfig, Server, Native, FREECB, MemoryBuffer, RPCReq, RPCCB, PitayaError

remotes_dict = dict()


def default_name_func(s): return s[:1].lower() + s[1:] if s else ''


LIB = None


def initialize_pitaya(
        sd_config: SdConfig,
        nats_config: NatsConfig,
        server: Server, logPath=b'/tmp/pitaya_cluster_log'):
    """ this method initializes pitaya cluster logic and should be called on start """
    global LIB
    LIB = Native().LIB
    res = LIB.tfg_pitc_Initialize(
        server, sd_config, nats_config, _rpc_cb, _free_cb, logPath)
    if not res:
        raise Exception("error initializing pitaya")


def get_server_by_id(server_id: str):
    """ gets a server by its id """
    # TODO needs free -- leak here!
    sv = Server()
    success = LIB.tfg_pitc_GetServerById(server_id.encode('utf-8'), sv)
    if success is False:
        raise Exception('failed to get server {}'.format(server_id))
    # LIB.tfg_pitc_FreeServer(byref(sv))
    return sv


def register_remote(remote: BaseRemote, name="", nameFunc=None):
    """ register a remote, the remote should be a class that inherits from BaseRemote """
    if name == "":
        name = remote.__class__.__name__.lower()
    if not issubclass(type(remote), BaseRemote):
        raise TypeError
    if not remote.is_valid_remote():
        raise Exception("the class %s contains no valid remote methods" %
                        remote.__class__.__name__)
    m_map = remote.get_remotes_map()
    for m in m_map.keys():
        rn = m
        if nameFunc is None:
            nameFunc = default_name_func
        rn = nameFunc(rn)
        name = "%s.%s" % (name, rn)
        if name in remotes_dict:
            raise Exception("tried to register same remote twice! %s" % name)
        # TODO better logger
        print("registered remote: %s" % name)
        remotes_dict[name] = m_map[m]


def shutdown():
    """ shutdown pitaya cluster, should be called on exit """
    LIB.tfg_pitc_Terminate()


@FREECB
def _free_cb(mem: c_void_p):
    """ free cb is called internally by the c module to free allocated memory """
    LIB.tfg_pitc_FreeMem(mem)


def _alloc_mem_buffer_ptr_with_response_data(res: Response):
    """ internal method, this allocs a memory buffer in the global heap for sending it to c code """
    if not isinstance(res, Response):
        raise TypeError
    res_bytes = res.SerializeToString()
    ret_len = len(res_bytes)
    ptrData = LIB.tfg_pitc_AllocMem(ret_len)
    ret_data = (c_char * ret_len)(*res_bytes)
    memmove(ptrData, ret_data, ret_len)
    ret = MemoryBuffer()
    ret.data = ptrData
    ret.size = ret_len
    # we alloc mem in c side because doing so from python causes it to be freed the moment we return
    ptrStruct = LIB.tfg_pitc_AllocMem(sizeof(ret))
    memmove(ptrStruct, addressof(ret), sizeof(ret))
    return ptrStruct


def _get_error_response_c_void_p(code, msg):
    """ gets an allocated buffer of an error response """
    res = Response()
    res.error.code = code
    res.error.msg = msg
    return _alloc_mem_buffer_ptr_with_response_data(res)


@RPCCB
def _rpc_cb(req: POINTER(RPCReq)) -> c_void_p:
    """ this method is called internally by c code for receiving rpcs """
    r = req.contents.route
    route = Route.from_str(r).str()
    if route not in remotes_dict:
        return _get_error_response_c_void_p("PIT-404", "remote %s not found!" % route)
    remote_method = remotes_dict[route]
    try:
        res = Response()
        req_data_ptr = req.contents.buffer.data
        req_data_sz = req.contents.buffer.size
        req_data = (c_char * req_data_sz).from_address(req_data_ptr)
        arg = remote_method.arg_type()
        arg.MergeFromString(req_data)
        ans = remote_method.method(remote_method.obj, arg)
        res.data = ans.SerializeToString()
        return _alloc_mem_buffer_ptr_with_response_data(res)
    except Exception as e:
        err_str = "exception: %s: %s" % (type(e).__name__, e)
        return _get_error_response_c_void_p("PIT-500", err_str)


def send_rpc(route: str, in_msg: message.Message, res_class: message.Message, server_id: str='') -> message.Message:
    """ sends a rpc to other pitaya server """
    if not issubclass(type(in_msg), message.Message) or not issubclass(res_class, message.Message):
        raise TypeError
    msg_bytes = in_msg.SerializeToString()
    msg_len = len(msg_bytes)
    c_bytes = (c_char * msg_len)(*msg_bytes)
    ret_ptr = POINTER(MemoryBuffer)()
    err = PitayaError()
    res = LIB.tfg_pitc_RPC(server_id.encode(
        'utf-8'), route.encode('utf-8'), addressof(c_bytes), msg_len, byref(ret_ptr), byref(err))
    if not res:
        exception_msg = "code: {} msg: {}".format(err.code, err.msg)
        LIB.tfg_pitc_FreePitayaError(err)
        raise Exception(exception_msg)
    ret_bytes = (
        c_char * ret_ptr.contents.size).from_address(ret_ptr.contents.data)
    response = Response()
    response.MergeFromString(ret_bytes)
    LIB.tfg_pitc_FreeMemoryBuffer(ret_ptr)
    out_msg = res_class()
    out_msg.MergeFromString(response.data)
    return out_msg

# MUST be called after get_server or else your code will leak
# TODO: can we prevent the user from not calling this?
# def free_server(server:Server):
#    LIB.tfg_pitc_FreeServer(server)
#
