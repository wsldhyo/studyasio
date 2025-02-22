// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: msg.proto
// Protobuf C++ Version: 5.29.0

#include "msg.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr Book::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        pages_{0},
        price_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Book::Book(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct BookDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BookDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BookDefaultTypeInternal() {}
  union {
    Book _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BookDefaultTypeInternal _Book_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_msg_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_msg_2eproto = nullptr;
const ::uint32_t
    TableStruct_msg_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Book, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Book, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::Book, _impl_.pages_),
        PROTOBUF_FIELD_OFFSET(::Book, _impl_.price_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Book)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_Book_default_instance_._instance,
};
const char descriptor_table_protodef_msg_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\tmsg.proto\"2\n\004Book\022\014\n\004name\030\001 \001(\t\022\r\n\005pag"
    "es\030\002 \001(\005\022\r\n\005price\030\003 \001(\002b\006proto3"
};
static ::absl::once_flag descriptor_table_msg_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_msg_2eproto = {
    false,
    false,
    71,
    descriptor_table_protodef_msg_2eproto,
    "msg.proto",
    &descriptor_table_msg_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_msg_2eproto::offsets,
    file_level_enum_descriptors_msg_2eproto,
    file_level_service_descriptors_msg_2eproto,
};
// ===================================================================

class Book::_Internal {
 public:
};

Book::Book(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Book)
}
inline PROTOBUF_NDEBUG_INLINE Book::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::Book& from_msg)
      : name_(arena, from.name_),
        _cached_size_{0} {}

Book::Book(
    ::google::protobuf::Arena* arena,
    const Book& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Book* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, pages_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, pages_),
           offsetof(Impl_, price_) -
               offsetof(Impl_, pages_) +
               sizeof(Impl_::price_));

  // @@protoc_insertion_point(copy_constructor:Book)
}
inline PROTOBUF_NDEBUG_INLINE Book::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : name_(arena),
        _cached_size_{0} {}

inline void Book::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, pages_),
           0,
           offsetof(Impl_, price_) -
               offsetof(Impl_, pages_) +
               sizeof(Impl_::price_));
}
Book::~Book() {
  // @@protoc_insertion_point(destructor:Book)
  SharedDtor(*this);
}
inline void Book::SharedDtor(MessageLite& self) {
  Book& this_ = static_cast<Book&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.name_.Destroy();
  this_._impl_.~Impl_();
}

inline void* Book::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) Book(arena);
}
constexpr auto Book::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(Book),
                                            alignof(Book));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull Book::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_Book_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &Book::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<Book>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &Book::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<Book>(), &Book::ByteSizeLong,
            &Book::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(Book, _impl_._cached_size_),
        false,
    },
    &Book::kDescriptorMethods,
    &descriptor_table_msg_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* Book::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 0, 17, 2> Book::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Book>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string name = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Book, _impl_.name_)}},
    // int32 pages = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Book, _impl_.pages_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(Book, _impl_.pages_)}},
    // float price = 3;
    {::_pbi::TcParser::FastF32S1,
     {29, 63, 0, PROTOBUF_FIELD_OFFSET(Book, _impl_.price_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string name = 1;
    {PROTOBUF_FIELD_OFFSET(Book, _impl_.name_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // int32 pages = 2;
    {PROTOBUF_FIELD_OFFSET(Book, _impl_.pages_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // float price = 3;
    {PROTOBUF_FIELD_OFFSET(Book, _impl_.price_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
  }},
  // no aux_entries
  {{
    "\4\4\0\0\0\0\0\0"
    "Book"
    "name"
  }},
};

PROTOBUF_NOINLINE void Book::Clear() {
// @@protoc_insertion_point(message_clear_start:Book)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  ::memset(&_impl_.pages_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.price_) -
      reinterpret_cast<char*>(&_impl_.pages_)) + sizeof(_impl_.price_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* Book::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const Book& this_ = static_cast<const Book&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* Book::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const Book& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:Book)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string name = 1;
          if (!this_._internal_name().empty()) {
            const std::string& _s = this_._internal_name();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Book.name");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          // int32 pages = 2;
          if (this_._internal_pages() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<2>(
                    stream, this_._internal_pages(), target);
          }

          // float price = 3;
          if (::absl::bit_cast<::uint32_t>(this_._internal_price()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                3, this_._internal_price(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:Book)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t Book::ByteSizeLong(const MessageLite& base) {
          const Book& this_ = static_cast<const Book&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t Book::ByteSizeLong() const {
          const Book& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:Book)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // string name = 1;
            if (!this_._internal_name().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_name());
            }
            // int32 pages = 2;
            if (this_._internal_pages() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_pages());
            }
            // float price = 3;
            if (::absl::bit_cast<::uint32_t>(this_._internal_price()) != 0) {
              total_size += 5;
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void Book::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Book*>(&to_msg);
  auto& from = static_cast<const Book&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Book)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (from._internal_pages() != 0) {
    _this->_impl_.pages_ = from._impl_.pages_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_price()) != 0) {
    _this->_impl_.price_ = from._impl_.price_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Book::CopyFrom(const Book& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Book)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Book::InternalSwap(Book* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Book, _impl_.price_)
      + sizeof(Book::_impl_.price_)
      - PROTOBUF_FIELD_OFFSET(Book, _impl_.pages_)>(
          reinterpret_cast<char*>(&_impl_.pages_),
          reinterpret_cast<char*>(&other->_impl_.pages_));
}

::google::protobuf::Metadata Book::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_msg_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
