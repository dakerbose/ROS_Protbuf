// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: superbai.proto

#include "superbai.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace superbai {
namespace sample {
class RosProtoTestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RosProtoTest> _instance;
} _RosProtoTest_default_instance_;
}  // namespace sample
}  // namespace superbai
static void InitDefaultsscc_info_RosProtoTest_superbai_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::superbai::sample::_RosProtoTest_default_instance_;
    new (ptr) ::superbai::sample::RosProtoTest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RosProtoTest_superbai_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RosProtoTest_superbai_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_superbai_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_superbai_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_superbai_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_superbai_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::RosProtoTest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::RosProtoTest, num_),
  PROTOBUF_FIELD_OFFSET(::superbai::sample::RosProtoTest, name_),
  PROTOBUF_FIELD_OFFSET(::superbai::sample::RosProtoTest, a_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::superbai::sample::RosProtoTest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::superbai::sample::_RosProtoTest_default_instance_),
};

const char descriptor_table_protodef_superbai_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016superbai.proto\022\017superbai.sample\"4\n\014Ros"
  "ProtoTest\022\013\n\003num\030\001 \001(\005\022\014\n\004name\030\002 \001(\t\022\t\n\001"
  "a\030\003 \001(\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_superbai_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_superbai_2eproto_sccs[1] = {
  &scc_info_RosProtoTest_superbai_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_superbai_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_superbai_2eproto = {
  false, false, descriptor_table_protodef_superbai_2eproto, "superbai.proto", 95,
  &descriptor_table_superbai_2eproto_once, descriptor_table_superbai_2eproto_sccs, descriptor_table_superbai_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_superbai_2eproto::offsets,
  file_level_metadata_superbai_2eproto, 1, file_level_enum_descriptors_superbai_2eproto, file_level_service_descriptors_superbai_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_superbai_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_superbai_2eproto)), true);
namespace superbai {
namespace sample {

// ===================================================================

class RosProtoTest::_Internal {
 public:
};

RosProtoTest::RosProtoTest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:superbai.sample.RosProtoTest)
}
RosProtoTest::RosProtoTest(const RosProtoTest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArena());
  }
  ::memcpy(&a_, &from.a_,
    static_cast<size_t>(reinterpret_cast<char*>(&num_) -
    reinterpret_cast<char*>(&a_)) + sizeof(num_));
  // @@protoc_insertion_point(copy_constructor:superbai.sample.RosProtoTest)
}

void RosProtoTest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RosProtoTest_superbai_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&a_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&num_) -
      reinterpret_cast<char*>(&a_)) + sizeof(num_));
}

RosProtoTest::~RosProtoTest() {
  // @@protoc_insertion_point(destructor:superbai.sample.RosProtoTest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RosProtoTest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RosProtoTest::ArenaDtor(void* object) {
  RosProtoTest* _this = reinterpret_cast< RosProtoTest* >(object);
  (void)_this;
}
void RosProtoTest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RosProtoTest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RosProtoTest& RosProtoTest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RosProtoTest_superbai_2eproto.base);
  return *internal_default_instance();
}


void RosProtoTest::Clear() {
// @@protoc_insertion_point(message_clear_start:superbai.sample.RosProtoTest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  ::memset(&a_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&num_) -
      reinterpret_cast<char*>(&a_)) + sizeof(num_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RosProtoTest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 num = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          num_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "superbai.sample.RosProtoTest.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double a = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          a_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RosProtoTest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:superbai.sample.RosProtoTest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 num = 1;
  if (this->num() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_num(), target);
  }

  // string name = 2;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "superbai.sample.RosProtoTest.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // double a = 3;
  if (!(this->a() <= 0 && this->a() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_a(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:superbai.sample.RosProtoTest)
  return target;
}

size_t RosProtoTest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:superbai.sample.RosProtoTest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // double a = 3;
  if (!(this->a() <= 0 && this->a() >= 0)) {
    total_size += 1 + 8;
  }

  // int32 num = 1;
  if (this->num() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_num());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RosProtoTest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:superbai.sample.RosProtoTest)
  GOOGLE_DCHECK_NE(&from, this);
  const RosProtoTest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RosProtoTest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:superbai.sample.RosProtoTest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:superbai.sample.RosProtoTest)
    MergeFrom(*source);
  }
}

void RosProtoTest::MergeFrom(const RosProtoTest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:superbai.sample.RosProtoTest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (!(from.a() <= 0 && from.a() >= 0)) {
    _internal_set_a(from._internal_a());
  }
  if (from.num() != 0) {
    _internal_set_num(from._internal_num());
  }
}

void RosProtoTest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:superbai.sample.RosProtoTest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RosProtoTest::CopyFrom(const RosProtoTest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:superbai.sample.RosProtoTest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RosProtoTest::IsInitialized() const {
  return true;
}

void RosProtoTest::InternalSwap(RosProtoTest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RosProtoTest, num_)
      + sizeof(RosProtoTest::num_)
      - PROTOBUF_FIELD_OFFSET(RosProtoTest, a_)>(
          reinterpret_cast<char*>(&a_),
          reinterpret_cast<char*>(&other->a_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RosProtoTest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sample
}  // namespace superbai
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::superbai::sample::RosProtoTest* Arena::CreateMaybeMessage< ::superbai::sample::RosProtoTest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::superbai::sample::RosProtoTest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
