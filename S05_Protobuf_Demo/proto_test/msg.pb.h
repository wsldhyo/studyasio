// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: msg.proto
// Protobuf C++ Version: 5.29.0

#ifndef msg_2eproto_2epb_2eh
#define msg_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_msg_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_msg_2eproto;
class Book;
struct BookDefaultTypeInternal;
extern BookDefaultTypeInternal _Book_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Book final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Book) */ {
 public:
  inline Book() : Book(nullptr) {}
  ~Book() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Book* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Book));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Book(
      ::google::protobuf::internal::ConstantInitialized);

  inline Book(const Book& from) : Book(nullptr, from) {}
  inline Book(Book&& from) noexcept
      : Book(nullptr, std::move(from)) {}
  inline Book& operator=(const Book& from) {
    CopyFrom(from);
    return *this;
  }
  inline Book& operator=(Book&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Book& default_instance() {
    return *internal_default_instance();
  }
  static inline const Book* internal_default_instance() {
    return reinterpret_cast<const Book*>(
        &_Book_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Book& a, Book& b) { a.Swap(&b); }
  inline void Swap(Book* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Book* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Book* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Book>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Book& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Book& from) { Book::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(Book* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "Book"; }

 protected:
  explicit Book(::google::protobuf::Arena* arena);
  Book(::google::protobuf::Arena* arena, const Book& from);
  Book(::google::protobuf::Arena* arena, Book&& from) noexcept
      : Book(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kNameFieldNumber = 1,
    kPagesFieldNumber = 2,
    kPriceFieldNumber = 3,
  };
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // int32 pages = 2;
  void clear_pages() ;
  ::int32_t pages() const;
  void set_pages(::int32_t value);

  private:
  ::int32_t _internal_pages() const;
  void _internal_set_pages(::int32_t value);

  public:
  // float price = 3;
  void clear_price() ;
  float price() const;
  void set_price(float value);

  private:
  float _internal_price() const;
  void _internal_set_price(float value);

  public:
  // @@protoc_insertion_point(class_scope:Book)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 0,
      17, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Book& from_msg);
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::int32_t pages_;
    float price_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_msg_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Book

// string name = 1;
inline void Book::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Book::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Book.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Book::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Book.name)
}
inline std::string* Book::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Book.name)
  return _s;
}
inline const std::string& Book::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void Book::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Book::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Book::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Book.name)
  return _impl_.name_.Release();
}
inline void Book::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:Book.name)
}

// int32 pages = 2;
inline void Book::clear_pages() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.pages_ = 0;
}
inline ::int32_t Book::pages() const {
  // @@protoc_insertion_point(field_get:Book.pages)
  return _internal_pages();
}
inline void Book::set_pages(::int32_t value) {
  _internal_set_pages(value);
  // @@protoc_insertion_point(field_set:Book.pages)
}
inline ::int32_t Book::_internal_pages() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.pages_;
}
inline void Book::_internal_set_pages(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.pages_ = value;
}

// float price = 3;
inline void Book::clear_price() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.price_ = 0;
}
inline float Book::price() const {
  // @@protoc_insertion_point(field_get:Book.price)
  return _internal_price();
}
inline void Book::set_price(float value) {
  _internal_set_price(value);
  // @@protoc_insertion_point(field_set:Book.price)
}
inline float Book::_internal_price() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.price_;
}
inline void Book::_internal_set_price(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.price_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // msg_2eproto_2epb_2eh
