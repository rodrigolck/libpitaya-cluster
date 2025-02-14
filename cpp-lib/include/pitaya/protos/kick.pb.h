// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kick.proto

#ifndef PROTOBUF_INCLUDED_kick_2eproto
#define PROTOBUF_INCLUDED_kick_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_kick_2eproto 

namespace protobuf_kick_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_kick_2eproto
namespace protos {
class KickAnswer;
class KickAnswerDefaultTypeInternal;
extern KickAnswerDefaultTypeInternal _KickAnswer_default_instance_;
class KickMsg;
class KickMsgDefaultTypeInternal;
extern KickMsgDefaultTypeInternal _KickMsg_default_instance_;
}  // namespace protos
namespace google {
namespace protobuf {
template<> ::protos::KickAnswer* Arena::CreateMaybeMessage<::protos::KickAnswer>(Arena*);
template<> ::protos::KickMsg* Arena::CreateMaybeMessage<::protos::KickMsg>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protos {

// ===================================================================

class KickMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protos.KickMsg) */ {
 public:
  KickMsg();
  virtual ~KickMsg();

  KickMsg(const KickMsg& from);

  inline KickMsg& operator=(const KickMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  KickMsg(KickMsg&& from) noexcept
    : KickMsg() {
    *this = ::std::move(from);
  }

  inline KickMsg& operator=(KickMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const KickMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const KickMsg* internal_default_instance() {
    return reinterpret_cast<const KickMsg*>(
               &_KickMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(KickMsg* other);
  friend void swap(KickMsg& a, KickMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline KickMsg* New() const final {
    return CreateMaybeMessage<KickMsg>(NULL);
  }

  KickMsg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<KickMsg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const KickMsg& from);
  void MergeFrom(const KickMsg& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(KickMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string userId = 1;
  void clear_userid();
  static const int kUserIdFieldNumber = 1;
  const ::std::string& userid() const;
  void set_userid(const ::std::string& value);
  #if LANG_CXX11
  void set_userid(::std::string&& value);
  #endif
  void set_userid(const char* value);
  void set_userid(const char* value, size_t size);
  ::std::string* mutable_userid();
  ::std::string* release_userid();
  void set_allocated_userid(::std::string* userid);

  // @@protoc_insertion_point(class_scope:protos.KickMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr userid_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_kick_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class KickAnswer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protos.KickAnswer) */ {
 public:
  KickAnswer();
  virtual ~KickAnswer();

  KickAnswer(const KickAnswer& from);

  inline KickAnswer& operator=(const KickAnswer& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  KickAnswer(KickAnswer&& from) noexcept
    : KickAnswer() {
    *this = ::std::move(from);
  }

  inline KickAnswer& operator=(KickAnswer&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const KickAnswer& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const KickAnswer* internal_default_instance() {
    return reinterpret_cast<const KickAnswer*>(
               &_KickAnswer_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(KickAnswer* other);
  friend void swap(KickAnswer& a, KickAnswer& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline KickAnswer* New() const final {
    return CreateMaybeMessage<KickAnswer>(NULL);
  }

  KickAnswer* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<KickAnswer>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const KickAnswer& from);
  void MergeFrom(const KickAnswer& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(KickAnswer* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool kicked = 1;
  void clear_kicked();
  static const int kKickedFieldNumber = 1;
  bool kicked() const;
  void set_kicked(bool value);

  // @@protoc_insertion_point(class_scope:protos.KickAnswer)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool kicked_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_kick_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// KickMsg

// string userId = 1;
inline void KickMsg::clear_userid() {
  userid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& KickMsg::userid() const {
  // @@protoc_insertion_point(field_get:protos.KickMsg.userId)
  return userid_.GetNoArena();
}
inline void KickMsg::set_userid(const ::std::string& value) {
  
  userid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protos.KickMsg.userId)
}
#if LANG_CXX11
inline void KickMsg::set_userid(::std::string&& value) {
  
  userid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protos.KickMsg.userId)
}
#endif
inline void KickMsg::set_userid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  userid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protos.KickMsg.userId)
}
inline void KickMsg::set_userid(const char* value, size_t size) {
  
  userid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protos.KickMsg.userId)
}
inline ::std::string* KickMsg::mutable_userid() {
  
  // @@protoc_insertion_point(field_mutable:protos.KickMsg.userId)
  return userid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* KickMsg::release_userid() {
  // @@protoc_insertion_point(field_release:protos.KickMsg.userId)
  
  return userid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void KickMsg::set_allocated_userid(::std::string* userid) {
  if (userid != NULL) {
    
  } else {
    
  }
  userid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), userid);
  // @@protoc_insertion_point(field_set_allocated:protos.KickMsg.userId)
}

// -------------------------------------------------------------------

// KickAnswer

// bool kicked = 1;
inline void KickAnswer::clear_kicked() {
  kicked_ = false;
}
inline bool KickAnswer::kicked() const {
  // @@protoc_insertion_point(field_get:protos.KickAnswer.kicked)
  return kicked_;
}
inline void KickAnswer::set_kicked(bool value) {
  
  kicked_ = value;
  // @@protoc_insertion_point(field_set:protos.KickAnswer.kicked)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protos

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_kick_2eproto
