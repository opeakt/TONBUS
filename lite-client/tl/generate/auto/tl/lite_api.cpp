#include "lite_api.h"

#include "tl/tl_object_parse.h"
#include "tl/tl_object_store.h"
#include "td/utils/int_types.h"
#include "crypto/common/bitstring.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"

namespace ton {
namespace lite_api {

std::string to_string(const BaseObject &value) {
  td::TlStorerToString storer;
  value.store(storer, "");
  return storer.str();
}

object_ptr<Object> Object::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case adnl_message_query::ID:
      return adnl_message_query::fetch(p);
    case adnl_message_answer::ID:
      return adnl_message_answer::fetch(p);
    case liteServer_accountId::ID:
      return liteServer_accountId::fetch(p);
    case liteServer_accountState::ID:
      return liteServer_accountState::fetch(p);
    case liteServer_allShardsInfo::ID:
      return liteServer_allShardsInfo::fetch(p);
    case liteServer_blockData::ID:
      return liteServer_blockData::fetch(p);
    case liteServer_blockHeader::ID:
      return liteServer_blockHeader::fetch(p);
    case liteServer_blockState::ID:
      return liteServer_blockState::fetch(p);
    case liteServer_blockTransactions::ID:
      return liteServer_blockTransactions::fetch(p);
    case liteServer_currentTime::ID:
      return liteServer_currentTime::fetch(p);
    case liteServer_error::ID:
      return liteServer_error::fetch(p);
    case liteServer_masterchainInfo::ID:
      return liteServer_masterchainInfo::fetch(p);
    case liteServer_sendMsgStatus::ID:
      return liteServer_sendMsgStatus::fetch(p);
    case liteServer_shardInfo::ID:
      return liteServer_shardInfo::fetch(p);
    case liteServer_transactionId::ID:
      return liteServer_transactionId::fetch(p);
    case liteServer_transactionId3::ID:
      return liteServer_transactionId3::fetch(p);
    case liteServer_transactionInfo::ID:
      return liteServer_transactionInfo::fetch(p);
    case liteServer_transactionList::ID:
      return liteServer_transactionList::fetch(p);
    case liteServer_debug_verbosity::ID:
      return liteServer_debug_verbosity::fetch(p);
    case tonNode_blockId::ID:
      return tonNode_blockId::fetch(p);
    case tonNode_blockIdExt::ID:
      return tonNode_blockIdExt::fetch(p);
    case tonNode_zeroStateIdExt::ID:
      return tonNode_zeroStateIdExt::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << td::format::as_hex(constructor));
  }
#undef FAIL
}

object_ptr<Function> Function::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case liteServer_debug_setVerbosity::ID:
      return liteServer_debug_setVerbosity::fetch(p);
    case liteServer_getAccountState::ID:
      return liteServer_getAccountState::fetch(p);
    case liteServer_getAllShardsInfo::ID:
      return liteServer_getAllShardsInfo::fetch(p);
    case liteServer_getBlock::ID:
      return liteServer_getBlock::fetch(p);
    case liteServer_getBlockHeader::ID:
      return liteServer_getBlockHeader::fetch(p);
    case liteServer_getMasterchainInfo::ID:
      return liteServer_getMasterchainInfo::fetch(p);
    case liteServer_getOneTransaction::ID:
      return liteServer_getOneTransaction::fetch(p);
    case liteServer_getShardInfo::ID:
      return liteServer_getShardInfo::fetch(p);
    case liteServer_getState::ID:
      return liteServer_getState::fetch(p);
    case liteServer_getTime::ID:
      return liteServer_getTime::fetch(p);
    case liteServer_getTransactions::ID:
      return liteServer_getTransactions::fetch(p);
    case liteServer_listBlockTransactions::ID:
      return liteServer_listBlockTransactions::fetch(p);
    case liteServer_lookupBlock::ID:
      return liteServer_lookupBlock::fetch(p);
    case liteServer_query::ID:
      return liteServer_query::fetch(p);
    case liteServer_sendMessage::ID:
      return liteServer_sendMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << td::format::as_hex(constructor));
  }
#undef FAIL
}

object_ptr<adnl_Message> adnl_Message::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case adnl_message_query::ID:
      return adnl_message_query::fetch(p);
    case adnl_message_answer::ID:
      return adnl_message_answer::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << td::format::as_hex(constructor));
  }
#undef FAIL
}

adnl_message_query::adnl_message_query()
  : query_id_()
  , query_()
{}

adnl_message_query::adnl_message_query(td::Bits256 const &query_id_, td::BufferSlice &&query_)
  : query_id_(query_id_)
  , query_(std::move(query_))
{}

const std::int32_t adnl_message_query::ID;

object_ptr<adnl_Message> adnl_message_query::fetch(td::TlParser &p) {
  return make_object<adnl_message_query>(p);
}

adnl_message_query::adnl_message_query(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : query_id_(TlFetchInt256::parse(p))
  , query_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void adnl_message_query::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(query_, s);
}

void adnl_message_query::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(query_, s);
}

void adnl_message_query::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "adnl_message_query");
    s.store_field("query_id", query_id_);
    s.store_bytes_field("query", query_);
    s.store_class_end();
  }
}

adnl_message_answer::adnl_message_answer()
  : query_id_()
  , answer_()
{}

adnl_message_answer::adnl_message_answer(td::Bits256 const &query_id_, td::BufferSlice &&answer_)
  : query_id_(query_id_)
  , answer_(std::move(answer_))
{}

const std::int32_t adnl_message_answer::ID;

object_ptr<adnl_Message> adnl_message_answer::fetch(td::TlParser &p) {
  return make_object<adnl_message_answer>(p);
}

adnl_message_answer::adnl_message_answer(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : query_id_(TlFetchInt256::parse(p))
  , answer_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void adnl_message_answer::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(answer_, s);
}

void adnl_message_answer::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(answer_, s);
}

void adnl_message_answer::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "adnl_message_answer");
    s.store_field("query_id", query_id_);
    s.store_bytes_field("answer", answer_);
    s.store_class_end();
  }
}

liteServer_accountId::liteServer_accountId()
  : workchain_()
  , id_()
{}

liteServer_accountId::liteServer_accountId(std::int32_t workchain_, td::Bits256 const &id_)
  : workchain_(workchain_)
  , id_(id_)
{}

const std::int32_t liteServer_accountId::ID;

object_ptr<liteServer_accountId> liteServer_accountId::fetch(td::TlParser &p) {
  return make_object<liteServer_accountId>(p);
}

liteServer_accountId::liteServer_accountId(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : workchain_(TlFetchInt::parse(p))
  , id_(TlFetchInt256::parse(p))
#undef FAIL
{}

void liteServer_accountId::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(id_, s);
}

void liteServer_accountId::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(id_, s);
}

void liteServer_accountId::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_accountId");
    s.store_field("workchain", workchain_);
    s.store_field("id", id_);
    s.store_class_end();
  }
}

liteServer_accountState::liteServer_accountState()
  : id_()
  , shardblk_()
  , shard_proof_()
  , proof_()
  , state_()
{}

liteServer_accountState::liteServer_accountState(object_ptr<tonNode_blockIdExt> &&id_, object_ptr<tonNode_blockIdExt> &&shardblk_, td::BufferSlice &&shard_proof_, td::BufferSlice &&proof_, td::BufferSlice &&state_)
  : id_(std::move(id_))
  , shardblk_(std::move(shardblk_))
  , shard_proof_(std::move(shard_proof_))
  , proof_(std::move(proof_))
  , state_(std::move(state_))
{}

const std::int32_t liteServer_accountState::ID;

object_ptr<liteServer_accountState> liteServer_accountState::fetch(td::TlParser &p) {
  return make_object<liteServer_accountState>(p);
}

liteServer_accountState::liteServer_accountState(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , shardblk_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , shard_proof_(TlFetchBytes<td::BufferSlice>::parse(p))
  , proof_(TlFetchBytes<td::BufferSlice>::parse(p))
  , state_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_accountState::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(shardblk_, s);
  TlStoreString::store(shard_proof_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(state_, s);
}

void liteServer_accountState::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(shardblk_, s);
  TlStoreString::store(shard_proof_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(state_, s);
}

void liteServer_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_accountState");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (shardblk_ == nullptr) { s.store_field("shardblk", "null"); } else { shardblk_->store(s, "shardblk"); }
    s.store_bytes_field("shard_proof", shard_proof_);
    s.store_bytes_field("proof", proof_);
    s.store_bytes_field("state", state_);
    s.store_class_end();
  }
}

liteServer_allShardsInfo::liteServer_allShardsInfo()
  : id_()
  , proof_()
  , data_()
{}

liteServer_allShardsInfo::liteServer_allShardsInfo(object_ptr<tonNode_blockIdExt> &&id_, td::BufferSlice &&proof_, td::BufferSlice &&data_)
  : id_(std::move(id_))
  , proof_(std::move(proof_))
  , data_(std::move(data_))
{}

const std::int32_t liteServer_allShardsInfo::ID;

object_ptr<liteServer_allShardsInfo> liteServer_allShardsInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_allShardsInfo>(p);
}

liteServer_allShardsInfo::liteServer_allShardsInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , proof_(TlFetchBytes<td::BufferSlice>::parse(p))
  , data_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_allShardsInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(data_, s);
}

void liteServer_allShardsInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(data_, s);
}

void liteServer_allShardsInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_allShardsInfo");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_bytes_field("proof", proof_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

liteServer_blockData::liteServer_blockData()
  : id_()
  , data_()
{}

liteServer_blockData::liteServer_blockData(object_ptr<tonNode_blockIdExt> &&id_, td::BufferSlice &&data_)
  : id_(std::move(id_))
  , data_(std::move(data_))
{}

const std::int32_t liteServer_blockData::ID;

object_ptr<liteServer_blockData> liteServer_blockData::fetch(td::TlParser &p) {
  return make_object<liteServer_blockData>(p);
}

liteServer_blockData::liteServer_blockData(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , data_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_blockData::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(data_, s);
}

void liteServer_blockData::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(data_, s);
}

void liteServer_blockData::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_blockData");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

liteServer_blockHeader::liteServer_blockHeader()
  : id_()
  , mode_()
  , header_proof_()
{}

liteServer_blockHeader::liteServer_blockHeader(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t mode_, td::BufferSlice &&header_proof_)
  : id_(std::move(id_))
  , mode_(mode_)
  , header_proof_(std::move(header_proof_))
{}

const std::int32_t liteServer_blockHeader::ID;

object_ptr<liteServer_blockHeader> liteServer_blockHeader::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_blockHeader> res = make_object<liteServer_blockHeader>();
  std::int32_t var0;
  res->id_ = TlFetchObject<tonNode_blockIdExt>::parse(p);
  if ((var0 = res->mode_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->header_proof_ = TlFetchBytes<td::BufferSlice>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_blockHeader::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreString::store(header_proof_, s);
}

void liteServer_blockHeader::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreString::store(header_proof_, s);
}

void liteServer_blockHeader::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_blockHeader");
  std::int32_t var0;
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("mode", (var0 = mode_));
    s.store_bytes_field("header_proof", header_proof_);
    s.store_class_end();
  }
}

liteServer_blockState::liteServer_blockState()
  : id_()
  , root_hash_()
  , file_hash_()
  , data_()
{}

liteServer_blockState::liteServer_blockState(object_ptr<tonNode_blockIdExt> &&id_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_, td::BufferSlice &&data_)
  : id_(std::move(id_))
  , root_hash_(root_hash_)
  , file_hash_(file_hash_)
  , data_(std::move(data_))
{}

const std::int32_t liteServer_blockState::ID;

object_ptr<liteServer_blockState> liteServer_blockState::fetch(td::TlParser &p) {
  return make_object<liteServer_blockState>(p);
}

liteServer_blockState::liteServer_blockState(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , root_hash_(TlFetchInt256::parse(p))
  , file_hash_(TlFetchInt256::parse(p))
  , data_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_blockState::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
  TlStoreString::store(data_, s);
}

void liteServer_blockState::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
  TlStoreString::store(data_, s);
}

void liteServer_blockState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_blockState");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("root_hash", root_hash_);
    s.store_field("file_hash", file_hash_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

liteServer_blockTransactions::liteServer_blockTransactions()
  : id_()
  , req_count_()
  , incomplete_()
  , ids_()
  , proof_()
{}

liteServer_blockTransactions::liteServer_blockTransactions(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t req_count_, bool incomplete_, std::vector<object_ptr<liteServer_transactionId>> &&ids_, td::BufferSlice &&proof_)
  : id_(std::move(id_))
  , req_count_(req_count_)
  , incomplete_(incomplete_)
  , ids_(std::move(ids_))
  , proof_(std::move(proof_))
{}

const std::int32_t liteServer_blockTransactions::ID;

object_ptr<liteServer_blockTransactions> liteServer_blockTransactions::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_blockTransactions> res = make_object<liteServer_blockTransactions>();
  std::int32_t var0;
  res->id_ = TlFetchObject<tonNode_blockIdExt>::parse(p);
  if ((var0 = res->req_count_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->incomplete_ = TlFetchBool::parse(p);
  res->ids_ = TlFetchVector<TlFetchObject<liteServer_transactionId>>::parse(p);
  res->proof_ = TlFetchBytes<td::BufferSlice>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_blockTransactions::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = req_count_), s);
  TlStoreBool::store(incomplete_, s);
  TlStoreVector<TlStoreObject>::store(ids_, s);
  TlStoreString::store(proof_, s);
}

void liteServer_blockTransactions::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = req_count_), s);
  TlStoreBool::store(incomplete_, s);
  TlStoreVector<TlStoreObject>::store(ids_, s);
  TlStoreString::store(proof_, s);
}

void liteServer_blockTransactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_blockTransactions");
  std::int32_t var0;
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("req_count", (var0 = req_count_));
    s.store_field("incomplete", incomplete_);
    { const std::vector<object_ptr<liteServer_transactionId>> &v = ids_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "vector[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("ids", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_bytes_field("proof", proof_);
    s.store_class_end();
  }
}

liteServer_currentTime::liteServer_currentTime()
  : now_()
{}

liteServer_currentTime::liteServer_currentTime(std::int32_t now_)
  : now_(now_)
{}

const std::int32_t liteServer_currentTime::ID;

object_ptr<liteServer_currentTime> liteServer_currentTime::fetch(td::TlParser &p) {
  return make_object<liteServer_currentTime>(p);
}

liteServer_currentTime::liteServer_currentTime(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : now_(TlFetchInt::parse(p))
#undef FAIL
{}

void liteServer_currentTime::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(now_, s);
}

void liteServer_currentTime::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(now_, s);
}

void liteServer_currentTime::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_currentTime");
    s.store_field("now", now_);
    s.store_class_end();
  }
}

liteServer_error::liteServer_error()
  : code_()
  , message_()
{}

liteServer_error::liteServer_error(std::int32_t code_, std::string const &message_)
  : code_(code_)
  , message_(std::move(message_))
{}

const std::int32_t liteServer_error::ID;

object_ptr<liteServer_error> liteServer_error::fetch(td::TlParser &p) {
  return make_object<liteServer_error>(p);
}

liteServer_error::liteServer_error(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : code_(TlFetchInt::parse(p))
  , message_(TlFetchString<std::string>::parse(p))
#undef FAIL
{}

void liteServer_error::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(code_, s);
  TlStoreString::store(message_, s);
}

void liteServer_error::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(code_, s);
  TlStoreString::store(message_, s);
}

void liteServer_error::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

liteServer_masterchainInfo::liteServer_masterchainInfo()
  : last_()
  , state_root_hash_()
  , init_()
{}

liteServer_masterchainInfo::liteServer_masterchainInfo(object_ptr<tonNode_blockIdExt> &&last_, td::Bits256 const &state_root_hash_, object_ptr<tonNode_zeroStateIdExt> &&init_)
  : last_(std::move(last_))
  , state_root_hash_(state_root_hash_)
  , init_(std::move(init_))
{}

const std::int32_t liteServer_masterchainInfo::ID;

object_ptr<liteServer_masterchainInfo> liteServer_masterchainInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_masterchainInfo>(p);
}

liteServer_masterchainInfo::liteServer_masterchainInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : last_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , state_root_hash_(TlFetchInt256::parse(p))
  , init_(TlFetchObject<tonNode_zeroStateIdExt>::parse(p))
#undef FAIL
{}

void liteServer_masterchainInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(last_, s);
  TlStoreBinary::store(state_root_hash_, s);
  TlStoreObject::store(init_, s);
}

void liteServer_masterchainInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(last_, s);
  TlStoreBinary::store(state_root_hash_, s);
  TlStoreObject::store(init_, s);
}

void liteServer_masterchainInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_masterchainInfo");
    if (last_ == nullptr) { s.store_field("last", "null"); } else { last_->store(s, "last"); }
    s.store_field("state_root_hash", state_root_hash_);
    if (init_ == nullptr) { s.store_field("init", "null"); } else { init_->store(s, "init"); }
    s.store_class_end();
  }
}

liteServer_sendMsgStatus::liteServer_sendMsgStatus()
  : status_()
{}

liteServer_sendMsgStatus::liteServer_sendMsgStatus(std::int32_t status_)
  : status_(status_)
{}

const std::int32_t liteServer_sendMsgStatus::ID;

object_ptr<liteServer_sendMsgStatus> liteServer_sendMsgStatus::fetch(td::TlParser &p) {
  return make_object<liteServer_sendMsgStatus>(p);
}

liteServer_sendMsgStatus::liteServer_sendMsgStatus(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : status_(TlFetchInt::parse(p))
#undef FAIL
{}

void liteServer_sendMsgStatus::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(status_, s);
}

void liteServer_sendMsgStatus::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(status_, s);
}

void liteServer_sendMsgStatus::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_sendMsgStatus");
    s.store_field("status", status_);
    s.store_class_end();
  }
}

liteServer_shardInfo::liteServer_shardInfo()
  : id_()
  , shardblk_()
  , shard_proof_()
  , shard_descr_()
{}

liteServer_shardInfo::liteServer_shardInfo(object_ptr<tonNode_blockIdExt> &&id_, object_ptr<tonNode_blockIdExt> &&shardblk_, td::BufferSlice &&shard_proof_, td::BufferSlice &&shard_descr_)
  : id_(std::move(id_))
  , shardblk_(std::move(shardblk_))
  , shard_proof_(std::move(shard_proof_))
  , shard_descr_(std::move(shard_descr_))
{}

const std::int32_t liteServer_shardInfo::ID;

object_ptr<liteServer_shardInfo> liteServer_shardInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_shardInfo>(p);
}

liteServer_shardInfo::liteServer_shardInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , shardblk_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , shard_proof_(TlFetchBytes<td::BufferSlice>::parse(p))
  , shard_descr_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_shardInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(shardblk_, s);
  TlStoreString::store(shard_proof_, s);
  TlStoreString::store(shard_descr_, s);
}

void liteServer_shardInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(shardblk_, s);
  TlStoreString::store(shard_proof_, s);
  TlStoreString::store(shard_descr_, s);
}

void liteServer_shardInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_shardInfo");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (shardblk_ == nullptr) { s.store_field("shardblk", "null"); } else { shardblk_->store(s, "shardblk"); }
    s.store_bytes_field("shard_proof", shard_proof_);
    s.store_bytes_field("shard_descr", shard_descr_);
    s.store_class_end();
  }
}

liteServer_transactionId::liteServer_transactionId()
  : mode_()
  , account_()
  , lt_()
  , hash_()
{}

liteServer_transactionId::liteServer_transactionId(std::int32_t mode_, td::Bits256 const &account_, std::int64_t lt_, td::Bits256 const &hash_)
  : mode_(mode_)
  , account_(account_)
  , lt_(lt_)
  , hash_(hash_)
{}

const std::int32_t liteServer_transactionId::ID;

object_ptr<liteServer_transactionId> liteServer_transactionId::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_transactionId> res = make_object<liteServer_transactionId>();
  std::int32_t var0;
  if ((var0 = res->mode_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->account_ = TlFetchInt256::parse(p); }
  if (var0 & 2) { res->lt_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->hash_ = TlFetchInt256::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_transactionId::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreBinary::store((var0 = mode_), s);
  if (var0 & 1) { TlStoreBinary::store(account_, s); }
  if (var0 & 2) { TlStoreBinary::store(lt_, s); }
  if (var0 & 4) { TlStoreBinary::store(hash_, s); }
}

void liteServer_transactionId::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  std::int32_t var0;
  TlStoreBinary::store((var0 = mode_), s);
  if (var0 & 1) { TlStoreBinary::store(account_, s); }
  if (var0 & 2) { TlStoreBinary::store(lt_, s); }
  if (var0 & 4) { TlStoreBinary::store(hash_, s); }
}

void liteServer_transactionId::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_transactionId");
  std::int32_t var0;
    s.store_field("mode", (var0 = mode_));
    if (var0 & 1) { s.store_field("account", account_); }
    if (var0 & 2) { s.store_field("lt", lt_); }
    if (var0 & 4) { s.store_field("hash", hash_); }
    s.store_class_end();
  }
}

liteServer_transactionId3::liteServer_transactionId3()
  : account_()
  , lt_()
{}

liteServer_transactionId3::liteServer_transactionId3(td::Bits256 const &account_, std::int64_t lt_)
  : account_(account_)
  , lt_(lt_)
{}

const std::int32_t liteServer_transactionId3::ID;

object_ptr<liteServer_transactionId3> liteServer_transactionId3::fetch(td::TlParser &p) {
  return make_object<liteServer_transactionId3>(p);
}

liteServer_transactionId3::liteServer_transactionId3(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : account_(TlFetchInt256::parse(p))
  , lt_(TlFetchLong::parse(p))
#undef FAIL
{}

void liteServer_transactionId3::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(account_, s);
  TlStoreBinary::store(lt_, s);
}

void liteServer_transactionId3::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(account_, s);
  TlStoreBinary::store(lt_, s);
}

void liteServer_transactionId3::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_transactionId3");
    s.store_field("account", account_);
    s.store_field("lt", lt_);
    s.store_class_end();
  }
}

liteServer_transactionInfo::liteServer_transactionInfo()
  : id_()
  , proof_()
  , transaction_()
{}

liteServer_transactionInfo::liteServer_transactionInfo(object_ptr<tonNode_blockIdExt> &&id_, td::BufferSlice &&proof_, td::BufferSlice &&transaction_)
  : id_(std::move(id_))
  , proof_(std::move(proof_))
  , transaction_(std::move(transaction_))
{}

const std::int32_t liteServer_transactionInfo::ID;

object_ptr<liteServer_transactionInfo> liteServer_transactionInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_transactionInfo>(p);
}

liteServer_transactionInfo::liteServer_transactionInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , proof_(TlFetchBytes<td::BufferSlice>::parse(p))
  , transaction_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_transactionInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(transaction_, s);
}

void liteServer_transactionInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreObject::store(id_, s);
  TlStoreString::store(proof_, s);
  TlStoreString::store(transaction_, s);
}

void liteServer_transactionInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_transactionInfo");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_bytes_field("proof", proof_);
    s.store_bytes_field("transaction", transaction_);
    s.store_class_end();
  }
}

liteServer_transactionList::liteServer_transactionList()
  : ids_()
  , transactions_()
{}

liteServer_transactionList::liteServer_transactionList(std::vector<object_ptr<tonNode_blockIdExt>> &&ids_, td::BufferSlice &&transactions_)
  : ids_(std::move(ids_))
  , transactions_(std::move(transactions_))
{}

const std::int32_t liteServer_transactionList::ID;

object_ptr<liteServer_transactionList> liteServer_transactionList::fetch(td::TlParser &p) {
  return make_object<liteServer_transactionList>(p);
}

liteServer_transactionList::liteServer_transactionList(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : ids_(TlFetchVector<TlFetchObject<tonNode_blockIdExt>>::parse(p))
  , transactions_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_transactionList::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreVector<TlStoreObject>::store(ids_, s);
  TlStoreString::store(transactions_, s);
}

void liteServer_transactionList::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreVector<TlStoreObject>::store(ids_, s);
  TlStoreString::store(transactions_, s);
}

void liteServer_transactionList::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_transactionList");
    { const std::vector<object_ptr<tonNode_blockIdExt>> &v = ids_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "vector[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("ids", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_bytes_field("transactions", transactions_);
    s.store_class_end();
  }
}

liteServer_debug_verbosity::liteServer_debug_verbosity()
  : value_()
{}

liteServer_debug_verbosity::liteServer_debug_verbosity(std::int32_t value_)
  : value_(value_)
{}

const std::int32_t liteServer_debug_verbosity::ID;

object_ptr<liteServer_debug_verbosity> liteServer_debug_verbosity::fetch(td::TlParser &p) {
  return make_object<liteServer_debug_verbosity>(p);
}

liteServer_debug_verbosity::liteServer_debug_verbosity(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : value_(TlFetchInt::parse(p))
#undef FAIL
{}

void liteServer_debug_verbosity::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void liteServer_debug_verbosity::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void liteServer_debug_verbosity::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_debug_verbosity");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

tonNode_blockId::tonNode_blockId()
  : workchain_()
  , shard_()
  , seqno_()
{}

tonNode_blockId::tonNode_blockId(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_)
  : workchain_(workchain_)
  , shard_(shard_)
  , seqno_(seqno_)
{}

const std::int32_t tonNode_blockId::ID;

object_ptr<tonNode_blockId> tonNode_blockId::fetch(td::TlParser &p) {
  return make_object<tonNode_blockId>(p);
}

tonNode_blockId::tonNode_blockId(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : workchain_(TlFetchInt::parse(p))
  , shard_(TlFetchLong::parse(p))
  , seqno_(TlFetchInt::parse(p))
#undef FAIL
{}

void tonNode_blockId::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBinary::store(seqno_, s);
}

void tonNode_blockId::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBinary::store(seqno_, s);
}

void tonNode_blockId::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNode_blockId");
    s.store_field("workchain", workchain_);
    s.store_field("shard", shard_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

tonNode_blockIdExt::tonNode_blockIdExt()
  : workchain_()
  , shard_()
  , seqno_()
  , root_hash_()
  , file_hash_()
{}

tonNode_blockIdExt::tonNode_blockIdExt(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_)
  : workchain_(workchain_)
  , shard_(shard_)
  , seqno_(seqno_)
  , root_hash_(root_hash_)
  , file_hash_(file_hash_)
{}

const std::int32_t tonNode_blockIdExt::ID;

object_ptr<tonNode_blockIdExt> tonNode_blockIdExt::fetch(td::TlParser &p) {
  return make_object<tonNode_blockIdExt>(p);
}

tonNode_blockIdExt::tonNode_blockIdExt(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : workchain_(TlFetchInt::parse(p))
  , shard_(TlFetchLong::parse(p))
  , seqno_(TlFetchInt::parse(p))
  , root_hash_(TlFetchInt256::parse(p))
  , file_hash_(TlFetchInt256::parse(p))
#undef FAIL
{}

void tonNode_blockIdExt::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBinary::store(seqno_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
}

void tonNode_blockIdExt::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBinary::store(seqno_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
}

void tonNode_blockIdExt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNode_blockIdExt");
    s.store_field("workchain", workchain_);
    s.store_field("shard", shard_);
    s.store_field("seqno", seqno_);
    s.store_field("root_hash", root_hash_);
    s.store_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

tonNode_zeroStateIdExt::tonNode_zeroStateIdExt()
  : workchain_()
  , root_hash_()
  , file_hash_()
{}

tonNode_zeroStateIdExt::tonNode_zeroStateIdExt(std::int32_t workchain_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_)
  : workchain_(workchain_)
  , root_hash_(root_hash_)
  , file_hash_(file_hash_)
{}

const std::int32_t tonNode_zeroStateIdExt::ID;

object_ptr<tonNode_zeroStateIdExt> tonNode_zeroStateIdExt::fetch(td::TlParser &p) {
  return make_object<tonNode_zeroStateIdExt>(p);
}

tonNode_zeroStateIdExt::tonNode_zeroStateIdExt(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : workchain_(TlFetchInt::parse(p))
  , root_hash_(TlFetchInt256::parse(p))
  , file_hash_(TlFetchInt256::parse(p))
#undef FAIL
{}

void tonNode_zeroStateIdExt::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
}

void tonNode_zeroStateIdExt::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(root_hash_, s);
  TlStoreBinary::store(file_hash_, s);
}

void tonNode_zeroStateIdExt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNode_zeroStateIdExt");
    s.store_field("workchain", workchain_);
    s.store_field("root_hash", root_hash_);
    s.store_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

liteServer_debug_setVerbosity::liteServer_debug_setVerbosity()
  : verbosity_()
{}

liteServer_debug_setVerbosity::liteServer_debug_setVerbosity(object_ptr<liteServer_debug_verbosity> &&verbosity_)
  : verbosity_(std::move(verbosity_))
{}

const std::int32_t liteServer_debug_setVerbosity::ID;

object_ptr<liteServer_debug_setVerbosity> liteServer_debug_setVerbosity::fetch(td::TlParser &p) {
  return make_object<liteServer_debug_setVerbosity>(p);
}

liteServer_debug_setVerbosity::liteServer_debug_setVerbosity(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : verbosity_(TlFetchObject<liteServer_debug_verbosity>::parse(p))
#undef FAIL
{}

void liteServer_debug_setVerbosity::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(462775286);
  TlStoreObject::store(verbosity_, s);
}

void liteServer_debug_setVerbosity::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(462775286);
  TlStoreObject::store(verbosity_, s);
}

void liteServer_debug_setVerbosity::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_debug_setVerbosity");
    if (verbosity_ == nullptr) { s.store_field("verbosity", "null"); } else { verbosity_->store(s, "verbosity"); }
    s.store_class_end();
  }
}

liteServer_debug_setVerbosity::ReturnType liteServer_debug_setVerbosity::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_debug_verbosity>, 1564493619>::parse(p);
#undef FAIL
}

liteServer_getAccountState::liteServer_getAccountState()
  : id_()
  , account_()
{}

liteServer_getAccountState::liteServer_getAccountState(object_ptr<tonNode_blockIdExt> &&id_, object_ptr<liteServer_accountId> &&account_)
  : id_(std::move(id_))
  , account_(std::move(account_))
{}

const std::int32_t liteServer_getAccountState::ID;

object_ptr<liteServer_getAccountState> liteServer_getAccountState::fetch(td::TlParser &p) {
  return make_object<liteServer_getAccountState>(p);
}

liteServer_getAccountState::liteServer_getAccountState(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , account_(TlFetchObject<liteServer_accountId>::parse(p))
#undef FAIL
{}

void liteServer_getAccountState::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1804144165);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(account_, s);
}

void liteServer_getAccountState::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1804144165);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(account_, s);
}

void liteServer_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getAccountState");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (account_ == nullptr) { s.store_field("account", "null"); } else { account_->store(s, "account"); }
    s.store_class_end();
  }
}

liteServer_getAccountState::ReturnType liteServer_getAccountState::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_accountState>, 1887029073>::parse(p);
#undef FAIL
}

liteServer_getAllShardsInfo::liteServer_getAllShardsInfo()
  : id_()
{}

liteServer_getAllShardsInfo::liteServer_getAllShardsInfo(object_ptr<tonNode_blockIdExt> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t liteServer_getAllShardsInfo::ID;

object_ptr<liteServer_getAllShardsInfo> liteServer_getAllShardsInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_getAllShardsInfo>(p);
}

liteServer_getAllShardsInfo::liteServer_getAllShardsInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
#undef FAIL
{}

void liteServer_getAllShardsInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1960050027);
  TlStoreObject::store(id_, s);
}

void liteServer_getAllShardsInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1960050027);
  TlStoreObject::store(id_, s);
}

void liteServer_getAllShardsInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getAllShardsInfo");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_class_end();
  }
}

liteServer_getAllShardsInfo::ReturnType liteServer_getAllShardsInfo::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_allShardsInfo>, 160425773>::parse(p);
#undef FAIL
}

liteServer_getBlock::liteServer_getBlock()
  : id_()
{}

liteServer_getBlock::liteServer_getBlock(object_ptr<tonNode_blockIdExt> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t liteServer_getBlock::ID;

object_ptr<liteServer_getBlock> liteServer_getBlock::fetch(td::TlParser &p) {
  return make_object<liteServer_getBlock>(p);
}

liteServer_getBlock::liteServer_getBlock(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
#undef FAIL
{}

void liteServer_getBlock::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1668796173);
  TlStoreObject::store(id_, s);
}

void liteServer_getBlock::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1668796173);
  TlStoreObject::store(id_, s);
}

void liteServer_getBlock::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getBlock");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_class_end();
  }
}

liteServer_getBlock::ReturnType liteServer_getBlock::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_blockData>, -1519063700>::parse(p);
#undef FAIL
}

liteServer_getBlockHeader::liteServer_getBlockHeader()
  : id_()
  , mode_()
{}

liteServer_getBlockHeader::liteServer_getBlockHeader(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t mode_)
  : id_(std::move(id_))
  , mode_(mode_)
{}

const std::int32_t liteServer_getBlockHeader::ID;

object_ptr<liteServer_getBlockHeader> liteServer_getBlockHeader::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_getBlockHeader> res = make_object<liteServer_getBlockHeader>();
  std::int32_t var0;
  res->id_ = TlFetchObject<tonNode_blockIdExt>::parse(p);
  if ((var0 = res->mode_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_getBlockHeader::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(569116318);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
}

void liteServer_getBlockHeader::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(569116318);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
}

void liteServer_getBlockHeader::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getBlockHeader");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("mode", (var0 = mode_));
    s.store_class_end();
  }
}

liteServer_getBlockHeader::ReturnType liteServer_getBlockHeader::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_blockHeader>, 1965916697>::parse(p);
#undef FAIL
}

liteServer_getMasterchainInfo::liteServer_getMasterchainInfo() {
}

const std::int32_t liteServer_getMasterchainInfo::ID;

object_ptr<liteServer_getMasterchainInfo> liteServer_getMasterchainInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_getMasterchainInfo>(p);
}

liteServer_getMasterchainInfo::liteServer_getMasterchainInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
#undef FAIL
{
  (void)p;
}

void liteServer_getMasterchainInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1984567762);
}

void liteServer_getMasterchainInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1984567762);
}

void liteServer_getMasterchainInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getMasterchainInfo");
    s.store_class_end();
  }
}

liteServer_getMasterchainInfo::ReturnType liteServer_getMasterchainInfo::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_masterchainInfo>, -2055001983>::parse(p);
#undef FAIL
}

liteServer_getOneTransaction::liteServer_getOneTransaction()
  : id_()
  , account_()
  , lt_()
{}

liteServer_getOneTransaction::liteServer_getOneTransaction(object_ptr<tonNode_blockIdExt> &&id_, object_ptr<liteServer_accountId> &&account_, std::int64_t lt_)
  : id_(std::move(id_))
  , account_(std::move(account_))
  , lt_(lt_)
{}

const std::int32_t liteServer_getOneTransaction::ID;

object_ptr<liteServer_getOneTransaction> liteServer_getOneTransaction::fetch(td::TlParser &p) {
  return make_object<liteServer_getOneTransaction>(p);
}

liteServer_getOneTransaction::liteServer_getOneTransaction(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , account_(TlFetchObject<liteServer_accountId>::parse(p))
  , lt_(TlFetchLong::parse(p))
#undef FAIL
{}

void liteServer_getOneTransaction::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-737205014);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(account_, s);
  TlStoreBinary::store(lt_, s);
}

void liteServer_getOneTransaction::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-737205014);
  TlStoreObject::store(id_, s);
  TlStoreObject::store(account_, s);
  TlStoreBinary::store(lt_, s);
}

void liteServer_getOneTransaction::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getOneTransaction");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (account_ == nullptr) { s.store_field("account", "null"); } else { account_->store(s, "account"); }
    s.store_field("lt", lt_);
    s.store_class_end();
  }
}

liteServer_getOneTransaction::ReturnType liteServer_getOneTransaction::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_transactionInfo>, 249490759>::parse(p);
#undef FAIL
}

liteServer_getShardInfo::liteServer_getShardInfo()
  : id_()
  , workchain_()
  , shard_()
  , exact_()
{}

liteServer_getShardInfo::liteServer_getShardInfo(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t workchain_, std::int64_t shard_, bool exact_)
  : id_(std::move(id_))
  , workchain_(workchain_)
  , shard_(shard_)
  , exact_(exact_)
{}

const std::int32_t liteServer_getShardInfo::ID;

object_ptr<liteServer_getShardInfo> liteServer_getShardInfo::fetch(td::TlParser &p) {
  return make_object<liteServer_getShardInfo>(p);
}

liteServer_getShardInfo::liteServer_getShardInfo(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
  , workchain_(TlFetchInt::parse(p))
  , shard_(TlFetchLong::parse(p))
  , exact_(TlFetchBool::parse(p))
#undef FAIL
{}

void liteServer_getShardInfo::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1185084453);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBool::store(exact_, s);
}

void liteServer_getShardInfo::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1185084453);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store(workchain_, s);
  TlStoreBinary::store(shard_, s);
  TlStoreBool::store(exact_, s);
}

void liteServer_getShardInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getShardInfo");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("workchain", workchain_);
    s.store_field("shard", shard_);
    s.store_field("exact", exact_);
    s.store_class_end();
  }
}

liteServer_getShardInfo::ReturnType liteServer_getShardInfo::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_shardInfo>, -1612264060>::parse(p);
#undef FAIL
}

liteServer_getState::liteServer_getState()
  : id_()
{}

liteServer_getState::liteServer_getState(object_ptr<tonNode_blockIdExt> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t liteServer_getState::ID;

object_ptr<liteServer_getState> liteServer_getState::fetch(td::TlParser &p) {
  return make_object<liteServer_getState>(p);
}

liteServer_getState::liteServer_getState(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : id_(TlFetchObject<tonNode_blockIdExt>::parse(p))
#undef FAIL
{}

void liteServer_getState::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1167184202);
  TlStoreObject::store(id_, s);
}

void liteServer_getState::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1167184202);
  TlStoreObject::store(id_, s);
}

void liteServer_getState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getState");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_class_end();
  }
}

liteServer_getState::ReturnType liteServer_getState::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_blockState>, -1414669300>::parse(p);
#undef FAIL
}

liteServer_getTime::liteServer_getTime() {
}

const std::int32_t liteServer_getTime::ID;

object_ptr<liteServer_getTime> liteServer_getTime::fetch(td::TlParser &p) {
  return make_object<liteServer_getTime>(p);
}

liteServer_getTime::liteServer_getTime(td::TlParser &p)
#define FAIL(error) p.set_error(error)
#undef FAIL
{
  (void)p;
}

void liteServer_getTime::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(380459572);
}

void liteServer_getTime::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(380459572);
}

void liteServer_getTime::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getTime");
    s.store_class_end();
  }
}

liteServer_getTime::ReturnType liteServer_getTime::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_currentTime>, -380436467>::parse(p);
#undef FAIL
}

liteServer_getTransactions::liteServer_getTransactions()
  : count_()
  , account_()
  , lt_()
  , hash_()
{}

liteServer_getTransactions::liteServer_getTransactions(std::int32_t count_, object_ptr<liteServer_accountId> &&account_, std::int64_t lt_, td::Bits256 const &hash_)
  : count_(count_)
  , account_(std::move(account_))
  , lt_(lt_)
  , hash_(hash_)
{}

const std::int32_t liteServer_getTransactions::ID;

object_ptr<liteServer_getTransactions> liteServer_getTransactions::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_getTransactions> res = make_object<liteServer_getTransactions>();
  std::int32_t var0;
  if ((var0 = res->count_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->account_ = TlFetchObject<liteServer_accountId>::parse(p);
  res->lt_ = TlFetchLong::parse(p);
  res->hash_ = TlFetchInt256::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_getTransactions::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(474015649);
  TlStoreBinary::store((var0 = count_), s);
  TlStoreObject::store(account_, s);
  TlStoreBinary::store(lt_, s);
  TlStoreBinary::store(hash_, s);
}

void liteServer_getTransactions::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(474015649);
  TlStoreBinary::store((var0 = count_), s);
  TlStoreObject::store(account_, s);
  TlStoreBinary::store(lt_, s);
  TlStoreBinary::store(hash_, s);
}

void liteServer_getTransactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_getTransactions");
    s.store_field("count", (var0 = count_));
    if (account_ == nullptr) { s.store_field("account", "null"); } else { account_->store(s, "account"); }
    s.store_field("lt", lt_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

liteServer_getTransactions::ReturnType liteServer_getTransactions::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_transactionList>, 1864812043>::parse(p);
#undef FAIL
}

liteServer_listBlockTransactions::liteServer_listBlockTransactions()
  : id_()
  , mode_()
  , count_()
  , after_()
  , reverse_order_()
  , want_proof_()
{}

liteServer_listBlockTransactions::liteServer_listBlockTransactions(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t mode_, std::int32_t count_, object_ptr<liteServer_transactionId3> &&after_, bool reverse_order_, bool want_proof_)
  : id_(std::move(id_))
  , mode_(mode_)
  , count_(count_)
  , after_(std::move(after_))
  , reverse_order_(reverse_order_)
  , want_proof_(want_proof_)
{}

const std::int32_t liteServer_listBlockTransactions::ID;

object_ptr<liteServer_listBlockTransactions> liteServer_listBlockTransactions::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_listBlockTransactions> res = make_object<liteServer_listBlockTransactions>();
  std::int32_t var0;
  std::int32_t var1;
  res->id_ = TlFetchObject<tonNode_blockIdExt>::parse(p);
  if ((var0 = res->mode_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if ((var1 = res->count_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 128) { res->after_ = TlFetchObject<liteServer_transactionId3>::parse(p); }
  if (var0 & 64) { res->reverse_order_ = TlFetchTrue::parse(p); }
  if (var0 & 32) { res->want_proof_ = TlFetchTrue::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_listBlockTransactions::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1375942694);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreBinary::store((var1 = count_), s);
  if (var0 & 128) { TlStoreObject::store(after_, s); }
  if (var0 & 64) { TlStoreTrue::store(reverse_order_, s); }
  if (var0 & 32) { TlStoreTrue::store(want_proof_, s); }
}

void liteServer_listBlockTransactions::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1375942694);
  TlStoreObject::store(id_, s);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreBinary::store((var1 = count_), s);
  if (var0 & 128) { TlStoreObject::store(after_, s); }
  if (var0 & 64) { TlStoreTrue::store(reverse_order_, s); }
  if (var0 & 32) { TlStoreTrue::store(want_proof_, s); }
}

void liteServer_listBlockTransactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_listBlockTransactions");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    s.store_field("mode", (var0 = mode_));
    s.store_field("count", (var1 = count_));
    if (var0 & 128) { if (after_ == nullptr) { s.store_field("after", "null"); } else { after_->store(s, "after"); } }
    if (var0 & 64) {  }
    if (var0 & 32) {  }
    s.store_class_end();
  }
}

liteServer_listBlockTransactions::ReturnType liteServer_listBlockTransactions::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_blockTransactions>, -1114854101>::parse(p);
#undef FAIL
}

liteServer_lookupBlock::liteServer_lookupBlock()
  : mode_()
  , id_()
  , lt_()
  , utime_()
{}

liteServer_lookupBlock::liteServer_lookupBlock(std::int32_t mode_, object_ptr<tonNode_blockId> &&id_, std::int64_t lt_, std::int32_t utime_)
  : mode_(mode_)
  , id_(std::move(id_))
  , lt_(lt_)
  , utime_(utime_)
{}

const std::int32_t liteServer_lookupBlock::ID;

object_ptr<liteServer_lookupBlock> liteServer_lookupBlock::fetch(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<liteServer_lookupBlock> res = make_object<liteServer_lookupBlock>();
  std::int32_t var0;
  if ((var0 = res->mode_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchObject<tonNode_blockId>::parse(p);
  if (var0 & 2) { res->lt_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->utime_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void liteServer_lookupBlock::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-87492834);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreObject::store(id_, s);
  if (var0 & 2) { TlStoreBinary::store(lt_, s); }
  if (var0 & 4) { TlStoreBinary::store(utime_, s); }
}

void liteServer_lookupBlock::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-87492834);
  TlStoreBinary::store((var0 = mode_), s);
  TlStoreObject::store(id_, s);
  if (var0 & 2) { TlStoreBinary::store(lt_, s); }
  if (var0 & 4) { TlStoreBinary::store(utime_, s); }
}

void liteServer_lookupBlock::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_lookupBlock");
    s.store_field("mode", (var0 = mode_));
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (var0 & 2) { s.store_field("lt", lt_); }
    if (var0 & 4) { s.store_field("utime", utime_); }
    s.store_class_end();
  }
}

liteServer_lookupBlock::ReturnType liteServer_lookupBlock::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_blockHeader>, 1965916697>::parse(p);
#undef FAIL
}

liteServer_query::liteServer_query()
  : data_()
{}

liteServer_query::liteServer_query(td::BufferSlice &&data_)
  : data_(std::move(data_))
{}

const std::int32_t liteServer_query::ID;

object_ptr<liteServer_query> liteServer_query::fetch(td::TlParser &p) {
  return make_object<liteServer_query>(p);
}

liteServer_query::liteServer_query(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : data_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_query::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2039219935);
  TlStoreString::store(data_, s);
}

void liteServer_query::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2039219935);
  TlStoreString::store(data_, s);
}

void liteServer_query::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_query");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

liteServer_query::ReturnType liteServer_query::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<Object>, 695225504>::parse(p);
#undef FAIL
}

liteServer_sendMessage::liteServer_sendMessage()
  : body_()
{}

liteServer_sendMessage::liteServer_sendMessage(td::BufferSlice &&body_)
  : body_(std::move(body_))
{}

const std::int32_t liteServer_sendMessage::ID;

object_ptr<liteServer_sendMessage> liteServer_sendMessage::fetch(td::TlParser &p) {
  return make_object<liteServer_sendMessage>(p);
}

liteServer_sendMessage::liteServer_sendMessage(td::TlParser &p)
#define FAIL(error) p.set_error(error)
  : body_(TlFetchBytes<td::BufferSlice>::parse(p))
#undef FAIL
{}

void liteServer_sendMessage::store(td::TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1762317442);
  TlStoreString::store(body_, s);
}

void liteServer_sendMessage::store(td::TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1762317442);
  TlStoreString::store(body_, s);
}

void liteServer_sendMessage::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liteServer_sendMessage");
    s.store_bytes_field("body", body_);
    s.store_class_end();
  }
}

liteServer_sendMessage::ReturnType liteServer_sendMessage::fetch_result(td::TlParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<liteServer_sendMsgStatus>, 961602967>::parse(p);
#undef FAIL
}
}  // namespace lite_api
}  // namespace ton
