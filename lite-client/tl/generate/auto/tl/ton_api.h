#pragma once

#include "tl/TlObject.h"

#include "td/utils/int_types.h"

#include <string>
#include "td/utils/buffer.h"
#include "crypto/common/bitstring.h"

#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

namespace td {
class TlStorerCalcLength;
}  // namespace td
namespace td {
class TlStorerUnsafe;
}  // namespace td
namespace td {
class TlStorerToString;
}  // namespace td
namespace td {
class TlParser;
}  // namespace td

namespace ton {
namespace ton_api{
using BaseObject = ::ton::TlObject;

template <class Type>
using object_ptr = ::ton::tl_object_ptr<Type>;

template <class Type, class... Args>
object_ptr<Type> make_object(Args &&... args) {
  return object_ptr<Type>(new Type(std::forward<Args>(args)...));
}

template <class ToType, class FromType>
object_ptr<ToType> move_object_as(FromType &&from) {
  return object_ptr<ToType>(static_cast<ToType *>(from.release()));
}

std::string to_string(const BaseObject &value);

template <class T>
std::string to_string(const object_ptr<T> &value) {
  if (value == nullptr) {
    return "null";
  }

  return to_string(*value);
}

class Hashable;

class PrivateKey;

class PublicKey;

class TestObject;

class adnl_Address;

class adnl_addressList;

class adnl_Message;

class adnl_node;

class adnl_nodes;

class adnl_packetContents;

class adnl_config_global;

class adnl_db_node_key;

class adnl_db_node_value;

class adnl_id_short;

class catchain_block;

class catchain_BlockResult;

class catchain_blocks;

class catchain_Difference;

class catchain_firstblock;

class catchain_sent;

class catchain_blockUpdate;

class catchain_block_data;

class catchain_block_dep;

class catchain_block_id;

class catchain_block_inner_Data;

class catchain_config_global;

class catchain_config_local;

class config_global;

class config_local;

class db_candidate;

class db_block_Info;

class db_blockdb_Key;

class db_blockdb_lru;

class db_blockdb_value;

class db_candidate_id;

class db_celldb_value;

class db_celldb_key_value;

class db_filedb_Key;

class db_filedb_value;

class db_lt_Key;

class db_lt_desc_value;

class db_lt_el_value;

class db_lt_shard_value;

class db_lt_status_value;

class db_root_config;

class db_root_dbDescription;

class db_root_Key;

class db_state_asyncSerializer;

class db_state_destroyedSessions;

class db_state_gcBlockId;

class db_state_initBlockId;

class db_state_Key;

class db_state_shardClient;

class dht_key;

class dht_keyDescription;

class dht_message;

class dht_node;

class dht_nodes;

class dht_pong;

class dht_stored;

class dht_UpdateRule;

class dht_value;

class dht_ValueResult;

class dht_config_global;

class dht_config_Local;

class dht_db_bucket;

class dht_db_key_bucket;

class dummyworkchain0_config_global;

class dummyworkchain0_config_local;

class fec_Type;

class id_config_local;

class liteclient_config_global;

class liteserver_config_local;

class overlay_Broadcast;

class overlay_broadcastList;

class overlay_Certificate;

class overlay_certificateId;

class overlay_message;

class overlay_node;

class overlay_nodes;

class overlay_broadcast_id;

class overlay_broadcast_toSign;

class overlay_broadcastFec_id;

class overlay_broadcastFec_partId;

class overlay_config_Local;

class overlay_db_key_nodes;

class overlay_db_nodes;

class overlay_node_toSign;

class rldp_Message;

class rldp_MessagePart;

class tcp_pong;

class test0_proof;

class test0_proofLink;

class test0_shardchain_block;

class test0_shardchain_state;

class test_validatorSession_block;

class test0_blockSignatures;

class test0_extMessage;

class test0_MasterchainBlockExtra;

class test0_MasterchainStateExtra;

class test0_topShardBlockDescription;

class test0_validatorSessionId;

class test0_validatorSet;

class test0_validatorSetItem;

class test0_masterchain_shardInfo;

class ton_blockId;

class tonNode_BlockDescription;

class tonNode_blockId;

class tonNode_blockIdExt;

class tonNode_blockSignature;

class tonNode_Broadcast;

class tonNode_data;

class tonNode_externalMessage;

class tonNode_ihrMessage;

class tonNode_keyBlocks;

class tonNode_newShardBlock;

class tonNode_Prepared;

class tonNode_PreparedProof;

class tonNode_PreparedState;

class tonNode_sessionId;

class tonNode_shardPublicOverlayId;

class tonNode_zeroStateIdExt;

class validator_config_global;

class validator_config_Local;

class validatorSession_blockUpdate;

class validatorSession_candidate;

class validatorSession_candidateId;

class validatorSession_id;

class validatorSession_Message;

class validatorSession_pong;

class validatorSession_round_id;

class validatorSession_round_Message;

class validatorSession_candidate_id;

class Object;

class Object: public TlObject {
 public:

  static object_ptr<Object> fetch(td::TlParser &p);
};

class Function: public TlObject {
 public:

  static object_ptr<Function> fetch(td::TlParser &p);
};

class Hashable: public Object {
 public:

  static object_ptr<Hashable> fetch(td::TlParser &p);
};

class hashable_bool final : public Hashable {
 public:
  bool value_;

  hashable_bool();

  explicit hashable_bool(bool value_);

  static const std::int32_t ID = -815709156;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_bool(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_int32 final : public Hashable {
 public:
  std::int32_t value_;

  hashable_int32();

  explicit hashable_int32(std::int32_t value_);

  static const std::int32_t ID = -743074986;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_int32(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_int64 final : public Hashable {
 public:
  std::int64_t value_;

  hashable_int64();

  explicit hashable_int64(std::int64_t value_);

  static const std::int32_t ID = -405107134;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_int64(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_int256 final : public Hashable {
 public:
  td::Bits256 value_;

  hashable_int256();

  explicit hashable_int256(td::Bits256 const &value_);

  static const std::int32_t ID = 975377359;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_int256(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_bytes final : public Hashable {
 public:
  td::BufferSlice value_;

  hashable_bytes();

  explicit hashable_bytes(td::BufferSlice &&value_);

  static const std::int32_t ID = 118742546;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_bytes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_pair final : public Hashable {
 public:
  std::int32_t left_;
  std::int32_t right_;

  hashable_pair();

  hashable_pair(std::int32_t left_, std::int32_t right_);

  static const std::int32_t ID = -941266795;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_pair(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_vector final : public Hashable {
 public:
  std::vector<std::int32_t> value_;

  hashable_vector();

  explicit hashable_vector(std::vector<std::int32_t> &&value_);

  static const std::int32_t ID = -550190227;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_vector(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_validatorSessionOldRound final : public Hashable {
 public:
  std::int32_t seqno_;
  std::int32_t block_;
  std::int32_t signatures_;

  hashable_validatorSessionOldRound();

  hashable_validatorSessionOldRound(std::int32_t seqno_, std::int32_t block_, std::int32_t signatures_);

  static const std::int32_t ID = 1479622531;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_validatorSessionOldRound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_validatorSessionRoundAttempt final : public Hashable {
 public:
  std::int32_t seqno_;
  std::int32_t votes_;
  std::int32_t precommitted_;

  hashable_validatorSessionRoundAttempt();

  hashable_validatorSessionRoundAttempt(std::int32_t seqno_, std::int32_t votes_, std::int32_t precommitted_);

  static const std::int32_t ID = -555220893;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_validatorSessionRoundAttempt(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_validatorSessionRound final : public Hashable {
 public:
  std::int32_t locked_round_;
  std::int32_t locked_block_;
  std::int32_t seqno_;
  bool precommitted_;
  std::int32_t approved_blocks_;
  std::int32_t signatures_;
  std::int32_t attempts_;

  hashable_validatorSessionRound();

  hashable_validatorSessionRound(std::int32_t locked_round_, std::int32_t locked_block_, std::int32_t seqno_, bool precommitted_, std::int32_t approved_blocks_, std::int32_t signatures_, std::int32_t attempts_);

  static const std::int32_t ID = -522103108;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_validatorSessionRound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_blockSignature final : public Hashable {
 public:
  std::int32_t signature_;

  hashable_blockSignature();

  explicit hashable_blockSignature(std::int32_t signature_);

  static const std::int32_t ID = 937530018;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_blockSignature(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_sentBlock final : public Hashable {
 public:
  std::int32_t src_;
  std::int32_t root_hash_;
  std::int32_t file_hash_;
  std::int32_t collated_data_file_hash_;

  hashable_sentBlock();

  hashable_sentBlock(std::int32_t src_, std::int32_t root_hash_, std::int32_t file_hash_, std::int32_t collated_data_file_hash_);

  static const std::int32_t ID = -1111911125;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_sentBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_sentBlockEmpty final : public Hashable {
 public:

  hashable_sentBlockEmpty();

  static const std::int32_t ID = -1628289361;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_sentBlockEmpty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_vote final : public Hashable {
 public:
  std::int32_t block_;
  std::int32_t node_;

  hashable_vote();

  hashable_vote(std::int32_t block_, std::int32_t node_);

  static const std::int32_t ID = -1363203131;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_vote(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_blockCandidate final : public Hashable {
 public:
  std::int32_t block_;
  std::int32_t approved_;

  hashable_blockCandidate();

  hashable_blockCandidate(std::int32_t block_, std::int32_t approved_);

  static const std::int32_t ID = 195670285;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_blockCandidate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_blockCandidateAttempt final : public Hashable {
 public:
  std::int32_t block_;
  std::int32_t votes_;

  hashable_blockCandidateAttempt();

  hashable_blockCandidateAttempt(std::int32_t block_, std::int32_t votes_);

  static const std::int32_t ID = 1063025931;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_blockCandidateAttempt(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_cntVector final : public Hashable {
 public:
  std::int32_t data_;

  hashable_cntVector();

  explicit hashable_cntVector(std::int32_t data_);

  static const std::int32_t ID = 187199288;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_cntVector(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_cntSortedVector final : public Hashable {
 public:
  std::int32_t data_;

  hashable_cntSortedVector();

  explicit hashable_cntSortedVector(std::int32_t data_);

  static const std::int32_t ID = 2073445977;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_cntSortedVector(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class hashable_validatorSession final : public Hashable {
 public:
  std::int32_t ts_;
  std::int32_t old_rounds_;
  std::int32_t cur_round_;

  hashable_validatorSession();

  hashable_validatorSession(std::int32_t ts_, std::int32_t old_rounds_, std::int32_t cur_round_);

  static const std::int32_t ID = 1746035669;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Hashable> fetch(td::TlParser &p);

  explicit hashable_validatorSession(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class PrivateKey: public Object {
 public:

  static object_ptr<PrivateKey> fetch(td::TlParser &p);
};

class pk_unenc final : public PrivateKey {
 public:
  td::BufferSlice data_;

  pk_unenc();

  explicit pk_unenc(td::BufferSlice &&data_);

  static const std::int32_t ID = -1311007952;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PrivateKey> fetch(td::TlParser &p);

  explicit pk_unenc(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pk_ed25519 final : public PrivateKey {
 public:
  td::Bits256 key_;

  pk_ed25519();

  explicit pk_ed25519(td::Bits256 const &key_);

  static const std::int32_t ID = 1231561495;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PrivateKey> fetch(td::TlParser &p);

  explicit pk_ed25519(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pk_aes final : public PrivateKey {
 public:
  td::Bits256 key_;

  pk_aes();

  explicit pk_aes(td::Bits256 const &key_);

  static const std::int32_t ID = -1511501513;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PrivateKey> fetch(td::TlParser &p);

  explicit pk_aes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pk_overlay final : public PrivateKey {
 public:
  td::BufferSlice name_;

  pk_overlay();

  explicit pk_overlay(td::BufferSlice &&name_);

  static const std::int32_t ID = 933623387;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PrivateKey> fetch(td::TlParser &p);

  explicit pk_overlay(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class PublicKey: public Object {
 public:

  static object_ptr<PublicKey> fetch(td::TlParser &p);
};

class pub_unenc final : public PublicKey {
 public:
  td::BufferSlice data_;

  pub_unenc();

  explicit pub_unenc(td::BufferSlice &&data_);

  static const std::int32_t ID = -1239464694;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PublicKey> fetch(td::TlParser &p);

  explicit pub_unenc(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pub_ed25519 final : public PublicKey {
 public:
  td::Bits256 key_;

  pub_ed25519();

  explicit pub_ed25519(td::Bits256 const &key_);

  static const std::int32_t ID = 1209251014;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PublicKey> fetch(td::TlParser &p);

  explicit pub_ed25519(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pub_aes final : public PublicKey {
 public:
  td::Bits256 key_;

  pub_aes();

  explicit pub_aes(td::Bits256 const &key_);

  static const std::int32_t ID = 767339988;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PublicKey> fetch(td::TlParser &p);

  explicit pub_aes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class pub_overlay final : public PublicKey {
 public:
  td::BufferSlice name_;

  pub_overlay();

  explicit pub_overlay(td::BufferSlice &&name_);

  static const std::int32_t ID = 884622795;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<PublicKey> fetch(td::TlParser &p);

  explicit pub_overlay(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class TestObject: public Object {
 public:

  static object_ptr<TestObject> fetch(td::TlParser &p);
};

class testObject final : public TestObject {
 public:
  std::int32_t value_;
  object_ptr<Object> o_;
  object_ptr<Function> f_;

  testObject();

  testObject(std::int32_t value_, object_ptr<Object> &&o_, object_ptr<Function> &&f_);

  static const std::int32_t ID = -1521006198;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<TestObject> fetch(td::TlParser &p);

  explicit testObject(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class testString final : public TestObject {
 public:
  std::string value_;

  testString();

  explicit testString(std::string const &value_);

  static const std::int32_t ID = -934972983;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<TestObject> fetch(td::TlParser &p);

  explicit testString(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class testInt final : public TestObject {
 public:
  std::int32_t value_;

  testInt();

  explicit testInt(std::int32_t value_);

  static const std::int32_t ID = 731271633;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<TestObject> fetch(td::TlParser &p);

  explicit testInt(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class testVectorBytes final : public TestObject {
 public:
  std::vector<td::BufferSlice> value_;

  testVectorBytes();

  explicit testVectorBytes(std::vector<td::BufferSlice> &&value_);

  static const std::int32_t ID = 1267407827;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<TestObject> fetch(td::TlParser &p);

  explicit testVectorBytes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_Address: public Object {
 public:

  static object_ptr<adnl_Address> fetch(td::TlParser &p);
};

class adnl_address_udp final : public adnl_Address {
 public:
  std::int32_t ip_;
  std::int32_t port_;

  adnl_address_udp();

  adnl_address_udp(std::int32_t ip_, std::int32_t port_);

  static const std::int32_t ID = 1728947943;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Address> fetch(td::TlParser &p);

  explicit adnl_address_udp(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_address_udp6 final : public adnl_Address {
 public:
  td::Bits128 ip_;
  std::int32_t port_;

  adnl_address_udp6();

  adnl_address_udp6(td::Bits128 const &ip_, std::int32_t port_);

  static const std::int32_t ID = -484613126;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Address> fetch(td::TlParser &p);

  explicit adnl_address_udp6(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_addressList final : public Object {
 public:
  std::vector<object_ptr<adnl_Address>> addrs_;
  std::int32_t version_;
  std::int32_t reinit_date_;
  std::int32_t priority_;
  std::int32_t expire_at_;

  adnl_addressList();

  adnl_addressList(std::vector<object_ptr<adnl_Address>> &&addrs_, std::int32_t version_, std::int32_t reinit_date_, std::int32_t priority_, std::int32_t expire_at_);

  static const std::int32_t ID = 573040216;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_addressList> fetch(td::TlParser &p);

  explicit adnl_addressList(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_Message: public Object {
 public:

  static object_ptr<adnl_Message> fetch(td::TlParser &p);
};

class adnl_message_createChannel final : public adnl_Message {
 public:
  td::Bits256 key_;
  std::int32_t date_;

  adnl_message_createChannel();

  adnl_message_createChannel(td::Bits256 const &key_, std::int32_t date_);

  static const std::int32_t ID = -428620869;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_createChannel(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_confirmChannel final : public adnl_Message {
 public:
  td::Bits256 key_;
  td::Bits256 peer_key_;
  std::int32_t date_;

  adnl_message_confirmChannel();

  adnl_message_confirmChannel(td::Bits256 const &key_, td::Bits256 const &peer_key_, std::int32_t date_);

  static const std::int32_t ID = 1625103721;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_confirmChannel(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_custom final : public adnl_Message {
 public:
  td::BufferSlice data_;

  adnl_message_custom();

  explicit adnl_message_custom(td::BufferSlice &&data_);

  static const std::int32_t ID = 541595893;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_custom(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_nop final : public adnl_Message {
 public:

  adnl_message_nop();

  static const std::int32_t ID = 402186202;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_nop(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_reinit final : public adnl_Message {
 public:
  std::int32_t date_;

  adnl_message_reinit();

  explicit adnl_message_reinit(std::int32_t date_);

  static const std::int32_t ID = 281150752;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_reinit(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_query final : public adnl_Message {
 public:
  td::Bits256 query_id_;
  td::BufferSlice query_;

  adnl_message_query();

  adnl_message_query(td::Bits256 const &query_id_, td::BufferSlice &&query_);

  static const std::int32_t ID = -1265895046;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_query(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_answer final : public adnl_Message {
 public:
  td::Bits256 query_id_;
  td::BufferSlice answer_;

  adnl_message_answer();

  adnl_message_answer(td::Bits256 const &query_id_, td::BufferSlice &&answer_);

  static const std::int32_t ID = 262964246;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_answer(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_message_part final : public adnl_Message {
 public:
  td::Bits256 hash_;
  std::int32_t total_size_;
  std::int32_t offset_;
  td::BufferSlice data_;

  adnl_message_part();

  adnl_message_part(td::Bits256 const &hash_, std::int32_t total_size_, std::int32_t offset_, td::BufferSlice &&data_);

  static const std::int32_t ID = -45798087;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_Message> fetch(td::TlParser &p);

  explicit adnl_message_part(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_node final : public Object {
 public:
  object_ptr<PublicKey> id_;
  object_ptr<adnl_addressList> addr_list_;
  td::BufferSlice signature_;

  adnl_node();

  adnl_node(object_ptr<PublicKey> &&id_, object_ptr<adnl_addressList> &&addr_list_, td::BufferSlice &&signature_);

  static const std::int32_t ID = 1354234810;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_node> fetch(td::TlParser &p);

  explicit adnl_node(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_nodes final : public Object {
 public:
  std::vector<object_ptr<adnl_node>> nodes_;

  adnl_nodes();

  explicit adnl_nodes(std::vector<object_ptr<adnl_node>> &&nodes_);

  static const std::int32_t ID = -1576412330;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_nodes> fetch(td::TlParser &p);

  explicit adnl_nodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_packetContents final : public Object {
 public:
  td::BufferSlice rand1_;
  std::int32_t flags_;
  object_ptr<PublicKey> from_;
  object_ptr<adnl_id_short> from_short_;
  object_ptr<adnl_Message> message_;
  std::vector<object_ptr<adnl_Message>> messages_;
  object_ptr<adnl_addressList> address_;
  object_ptr<adnl_addressList> priority_address_;
  std::int64_t seqno_;
  std::int64_t confirm_seqno_;
  std::int32_t recv_addr_list_version_;
  std::int32_t recv_priority_addr_list_version_;
  std::int32_t reinit_date_;
  std::int32_t dst_reinit_date_;
  td::BufferSlice signature_;
  td::BufferSlice rand2_;
  enum Flags : std::int32_t {FROM_MASK = 1, FROM_SHORT_MASK = 2, MESSAGE_MASK = 4, MESSAGES_MASK = 8, ADDRESS_MASK = 16, PRIORITY_ADDRESS_MASK = 32, SEQNO_MASK = 64, CONFIRM_SEQNO_MASK = 128, RECV_ADDR_LIST_VERSION_MASK = 256, RECV_PRIORITY_ADDR_LIST_VERSION_MASK = 512, REINIT_DATE_MASK = 1024, DST_REINIT_DATE_MASK = 1024, SIGNATURE_MASK = 2048};

  adnl_packetContents();

  adnl_packetContents(td::BufferSlice &&rand1_, std::int32_t flags_, object_ptr<PublicKey> &&from_, object_ptr<adnl_id_short> &&from_short_, object_ptr<adnl_Message> &&message_, std::vector<object_ptr<adnl_Message>> &&messages_, object_ptr<adnl_addressList> &&address_, object_ptr<adnl_addressList> &&priority_address_, std::int64_t seqno_, std::int64_t confirm_seqno_, std::int32_t recv_addr_list_version_, std::int32_t recv_priority_addr_list_version_, std::int32_t reinit_date_, std::int32_t dst_reinit_date_, td::BufferSlice &&signature_, td::BufferSlice &&rand2_);

  static const std::int32_t ID = -784151159;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_packetContents> fetch(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_config_global final : public Object {
 public:
  object_ptr<adnl_nodes> static_nodes_;

  adnl_config_global();

  explicit adnl_config_global(object_ptr<adnl_nodes> &&static_nodes_);

  static const std::int32_t ID = -1099988784;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_config_global> fetch(td::TlParser &p);

  explicit adnl_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_db_node_key final : public Object {
 public:
  td::Bits256 local_id_;
  td::Bits256 peer_id_;

  adnl_db_node_key();

  adnl_db_node_key(td::Bits256 const &local_id_, td::Bits256 const &peer_id_);

  static const std::int32_t ID = -979114962;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_db_node_key> fetch(td::TlParser &p);

  explicit adnl_db_node_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_db_node_value final : public Object {
 public:
  std::int32_t date_;
  object_ptr<PublicKey> id_;
  object_ptr<adnl_addressList> addr_list_;
  object_ptr<adnl_addressList> priority_addr_list_;

  adnl_db_node_value();

  adnl_db_node_value(std::int32_t date_, object_ptr<PublicKey> &&id_, object_ptr<adnl_addressList> &&addr_list_, object_ptr<adnl_addressList> &&priority_addr_list_);

  static const std::int32_t ID = 1415390983;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_db_node_value> fetch(td::TlParser &p);

  explicit adnl_db_node_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class adnl_id_short final : public Object {
 public:
  td::Bits256 id_;

  adnl_id_short();

  explicit adnl_id_short(td::Bits256 const &id_);

  static const std::int32_t ID = 1044342095;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnl_id_short> fetch(td::TlParser &p);

  explicit adnl_id_short(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block final : public Object {
 public:
  td::Bits256 incarnation_;
  std::int32_t src_;
  std::int32_t height_;
  object_ptr<catchain_block_data> data_;
  td::BufferSlice signature_;

  catchain_block();

  catchain_block(td::Bits256 const &incarnation_, std::int32_t src_, std::int32_t height_, object_ptr<catchain_block_data> &&data_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -699055756;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block> fetch(td::TlParser &p);

  explicit catchain_block(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_BlockResult: public Object {
 public:

  static object_ptr<catchain_BlockResult> fetch(td::TlParser &p);
};

class catchain_blockNotFound final : public catchain_BlockResult {
 public:

  catchain_blockNotFound();

  static const std::int32_t ID = -1240397692;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_BlockResult> fetch(td::TlParser &p);

  explicit catchain_blockNotFound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_blockResult final : public catchain_BlockResult {
 public:
  object_ptr<catchain_block> block_;

  catchain_blockResult();

  explicit catchain_blockResult(object_ptr<catchain_block> &&block_);

  static const std::int32_t ID = -1658179513;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_BlockResult> fetch(td::TlParser &p);

  explicit catchain_blockResult(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_blocks final : public Object {
 public:
  std::vector<object_ptr<catchain_block>> blocks_;

  catchain_blocks();

  explicit catchain_blocks(std::vector<object_ptr<catchain_block>> &&blocks_);

  static const std::int32_t ID = 1357697473;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_blocks> fetch(td::TlParser &p);

  explicit catchain_blocks(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_Difference: public Object {
 public:

  static object_ptr<catchain_Difference> fetch(td::TlParser &p);
};

class catchain_difference final : public catchain_Difference {
 public:
  std::vector<std::int32_t> sent_upto_;

  catchain_difference();

  explicit catchain_difference(std::vector<std::int32_t> &&sent_upto_);

  static const std::int32_t ID = 336974282;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_Difference> fetch(td::TlParser &p);

  explicit catchain_difference(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_differenceFork final : public catchain_Difference {
 public:
  object_ptr<catchain_block_dep> left_;
  object_ptr<catchain_block_dep> right_;

  catchain_differenceFork();

  catchain_differenceFork(object_ptr<catchain_block_dep> &&left_, object_ptr<catchain_block_dep> &&right_);

  static const std::int32_t ID = 1227341935;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_Difference> fetch(td::TlParser &p);

  explicit catchain_differenceFork(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_firstblock final : public Object {
 public:
  td::Bits256 unique_hash_;
  std::vector<td::Bits256> nodes_;

  catchain_firstblock();

  catchain_firstblock(td::Bits256 const &unique_hash_, std::vector<td::Bits256> &&nodes_);

  static const std::int32_t ID = 281609467;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_firstblock> fetch(td::TlParser &p);

  explicit catchain_firstblock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_sent final : public Object {
 public:
  std::int32_t cnt_;

  catchain_sent();

  explicit catchain_sent(std::int32_t cnt_);

  static const std::int32_t ID = -84454993;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_sent> fetch(td::TlParser &p);

  explicit catchain_sent(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_blockUpdate final : public Object {
 public:
  object_ptr<catchain_block> block_;

  catchain_blockUpdate();

  explicit catchain_blockUpdate(object_ptr<catchain_block> &&block_);

  static const std::int32_t ID = 593975492;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_blockUpdate> fetch(td::TlParser &p);

  explicit catchain_blockUpdate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_data final : public Object {
 public:
  object_ptr<catchain_block_dep> prev_;
  std::vector<object_ptr<catchain_block_dep>> deps_;

  catchain_block_data();

  catchain_block_data(object_ptr<catchain_block_dep> &&prev_, std::vector<object_ptr<catchain_block_dep>> &&deps_);

  static const std::int32_t ID = -122903008;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_data> fetch(td::TlParser &p);

  explicit catchain_block_data(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_dep final : public Object {
 public:
  std::int32_t src_;
  std::int32_t height_;
  td::Bits256 data_hash_;
  td::BufferSlice signature_;

  catchain_block_dep();

  catchain_block_dep(std::int32_t src_, std::int32_t height_, td::Bits256 const &data_hash_, td::BufferSlice &&signature_);

  static const std::int32_t ID = 1511706959;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_dep> fetch(td::TlParser &p);

  explicit catchain_block_dep(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_id final : public Object {
 public:
  td::Bits256 incarnation_;
  td::Bits256 src_;
  std::int32_t height_;
  td::Bits256 data_hash_;

  catchain_block_id();

  catchain_block_id(td::Bits256 const &incarnation_, td::Bits256 const &src_, std::int32_t height_, td::Bits256 const &data_hash_);

  static const std::int32_t ID = 620665018;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_id> fetch(td::TlParser &p);

  explicit catchain_block_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_inner_Data: public Object {
 public:

  static object_ptr<catchain_block_inner_Data> fetch(td::TlParser &p);
};

class catchain_block_data_badBlock final : public catchain_block_inner_Data {
 public:
  object_ptr<catchain_block> block_;

  catchain_block_data_badBlock();

  explicit catchain_block_data_badBlock(object_ptr<catchain_block> &&block_);

  static const std::int32_t ID = -1241359786;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_inner_Data> fetch(td::TlParser &p);

  explicit catchain_block_data_badBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_data_fork final : public catchain_block_inner_Data {
 public:
  object_ptr<catchain_block_dep> left_;
  object_ptr<catchain_block_dep> right_;

  catchain_block_data_fork();

  catchain_block_data_fork(object_ptr<catchain_block_dep> &&left_, object_ptr<catchain_block_dep> &&right_);

  static const std::int32_t ID = 1685731922;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_inner_Data> fetch(td::TlParser &p);

  explicit catchain_block_data_fork(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_data_nop final : public catchain_block_inner_Data {
 public:

  catchain_block_data_nop();

  static const std::int32_t ID = 1417852112;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_inner_Data> fetch(td::TlParser &p);

  explicit catchain_block_data_nop(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_block_data_vector final : public catchain_block_inner_Data {
 public:
  std::vector<td::BufferSlice> msgs_;

  catchain_block_data_vector();

  explicit catchain_block_data_vector(std::vector<td::BufferSlice> &&msgs_);

  static const std::int32_t ID = 1688809258;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_block_inner_Data> fetch(td::TlParser &p);

  explicit catchain_block_data_vector(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_config_global final : public Object {
 public:
  td::Bits256 tag_;
  std::vector<object_ptr<PublicKey>> nodes_;

  catchain_config_global();

  catchain_config_global(td::Bits256 const &tag_, std::vector<object_ptr<PublicKey>> &&nodes_);

  static const std::int32_t ID = 1757918801;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_config_global> fetch(td::TlParser &p);

  explicit catchain_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_config_local final : public Object {
 public:
  td::Bits256 tag_;
  object_ptr<adnl_id_short> id_;

  catchain_config_local();

  catchain_config_local(td::Bits256 const &tag_, object_ptr<adnl_id_short> &&id_);

  static const std::int32_t ID = 1394037726;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<catchain_config_local> fetch(td::TlParser &p);

  explicit catchain_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class config_global final : public Object {
 public:
  object_ptr<adnl_config_global> adnl_;
  object_ptr<dht_config_global> dht_;
  std::vector<object_ptr<catchain_config_global>> catchains_;
  std::vector<object_ptr<dummyworkchain0_config_global>> dummy0_;
  std::vector<object_ptr<validator_config_global>> validators_;
  std::vector<object_ptr<liteclient_config_global>> liteclients_;

  config_global();

  config_global(object_ptr<adnl_config_global> &&adnl_, object_ptr<dht_config_global> &&dht_, std::vector<object_ptr<catchain_config_global>> &&catchains_, std::vector<object_ptr<dummyworkchain0_config_global>> &&dummy0_, std::vector<object_ptr<validator_config_global>> &&validators_, std::vector<object_ptr<liteclient_config_global>> &&liteclients_);

  static const std::int32_t ID = -1606514086;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<config_global> fetch(td::TlParser &p);

  explicit config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class config_local final : public Object {
 public:
  std::vector<std::int32_t> udp_ports_;
  std::vector<std::int32_t> tcp_ports_;
  std::vector<object_ptr<id_config_local>> local_ids_;
  std::vector<object_ptr<dht_config_Local>> dht_;
  std::vector<object_ptr<overlay_config_Local>> public_overlays_;
  std::vector<object_ptr<catchain_config_local>> catchains_;
  std::vector<object_ptr<dummyworkchain0_config_local>> dummy0_;
  std::vector<object_ptr<validator_config_Local>> validators_;
  std::vector<object_ptr<liteserver_config_local>> liteservers_;

  config_local();

  config_local(std::vector<std::int32_t> &&udp_ports_, std::vector<std::int32_t> &&tcp_ports_, std::vector<object_ptr<id_config_local>> &&local_ids_, std::vector<object_ptr<dht_config_Local>> &&dht_, std::vector<object_ptr<overlay_config_Local>> &&public_overlays_, std::vector<object_ptr<catchain_config_local>> &&catchains_, std::vector<object_ptr<dummyworkchain0_config_local>> &&dummy0_, std::vector<object_ptr<validator_config_Local>> &&validators_, std::vector<object_ptr<liteserver_config_local>> &&liteservers_);

  static const std::int32_t ID = 340000344;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<config_local> fetch(td::TlParser &p);

  explicit config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_candidate final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  td::BufferSlice data_;
  td::BufferSlice collated_data_;

  db_candidate();

  db_candidate(object_ptr<tonNode_blockIdExt> &&id_, td::BufferSlice &&data_, td::BufferSlice &&collated_data_);

  static const std::int32_t ID = 329181652;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_candidate> fetch(td::TlParser &p);

  explicit db_candidate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_block_Info: public Object {
 public:

  static object_ptr<db_block_Info> fetch(td::TlParser &p);
};

class db_block_info final : public db_block_Info {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  std::int32_t flags_;
  object_ptr<tonNode_blockIdExt> prev_left_;
  object_ptr<tonNode_blockIdExt> prev_right_;
  object_ptr<tonNode_blockIdExt> next_left_;
  object_ptr<tonNode_blockIdExt> next_right_;
  std::int64_t lt_;
  std::int32_t ts_;
  td::Bits256 state_;
  enum Flags : std::int32_t {PREV_LEFT_MASK = 2, PREV_RIGHT_MASK = 4, NEXT_LEFT_MASK = 8, NEXT_RIGHT_MASK = 16, LT_MASK = 8192, TS_MASK = 16384, STATE_MASK = 131072};

  db_block_info();

  db_block_info(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t flags_, object_ptr<tonNode_blockIdExt> &&prev_left_, object_ptr<tonNode_blockIdExt> &&prev_right_, object_ptr<tonNode_blockIdExt> &&next_left_, object_ptr<tonNode_blockIdExt> &&next_right_, std::int64_t lt_, std::int32_t ts_, td::Bits256 const &state_);

  static const std::int32_t ID = 1254549287;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_block_Info> fetch(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_block_archivedInfo final : public db_block_Info {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  std::int32_t flags_;
  object_ptr<tonNode_blockIdExt> next_;
  enum Flags : std::int32_t {NEXT_MASK = 1};

  db_block_archivedInfo();

  db_block_archivedInfo(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t flags_, object_ptr<tonNode_blockIdExt> &&next_);

  static const std::int32_t ID = 543128145;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_block_Info> fetch(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_blockdb_Key: public Object {
 public:

  static object_ptr<db_blockdb_Key> fetch(td::TlParser &p);
};

class db_blockdb_key_lru final : public db_blockdb_Key {
 public:
  object_ptr<tonNode_blockIdExt> id_;

  db_blockdb_key_lru();

  explicit db_blockdb_key_lru(object_ptr<tonNode_blockIdExt> &&id_);

  static const std::int32_t ID = 1354536506;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_blockdb_Key> fetch(td::TlParser &p);

  explicit db_blockdb_key_lru(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_blockdb_key_value final : public db_blockdb_Key {
 public:
  object_ptr<tonNode_blockIdExt> id_;

  db_blockdb_key_value();

  explicit db_blockdb_key_value(object_ptr<tonNode_blockIdExt> &&id_);

  static const std::int32_t ID = 2136461683;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_blockdb_Key> fetch(td::TlParser &p);

  explicit db_blockdb_key_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_blockdb_lru final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  td::Bits256 prev_;
  td::Bits256 next_;

  db_blockdb_lru();

  db_blockdb_lru(object_ptr<tonNode_blockIdExt> &&id_, td::Bits256 const &prev_, td::Bits256 const &next_);

  static const std::int32_t ID = -1055500877;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_blockdb_lru> fetch(td::TlParser &p);

  explicit db_blockdb_lru(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_blockdb_value final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> next_;
  td::BufferSlice data_;

  db_blockdb_value();

  db_blockdb_value(object_ptr<tonNode_blockIdExt> &&next_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1299266515;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_blockdb_value> fetch(td::TlParser &p);

  explicit db_blockdb_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_candidate_id final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  td::Bits256 collated_data_file_hash_;

  db_candidate_id();

  db_candidate_id(object_ptr<tonNode_blockIdExt> &&id_, td::Bits256 const &collated_data_file_hash_);

  static const std::int32_t ID = -562931756;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_candidate_id> fetch(td::TlParser &p);

  explicit db_candidate_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_celldb_value final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;
  td::Bits256 prev_;
  td::Bits256 next_;
  td::Bits256 root_hash_;

  db_celldb_value();

  db_celldb_value(object_ptr<tonNode_blockIdExt> &&block_id_, td::Bits256 const &prev_, td::Bits256 const &next_, td::Bits256 const &root_hash_);

  static const std::int32_t ID = -435153856;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_celldb_value> fetch(td::TlParser &p);

  explicit db_celldb_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_celldb_key_value final : public Object {
 public:
  td::Bits256 hash_;

  db_celldb_key_value();

  explicit db_celldb_key_value(td::Bits256 const &hash_);

  static const std::int32_t ID = 1538341155;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_celldb_key_value> fetch(td::TlParser &p);

  explicit db_celldb_key_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_Key: public Object {
 public:

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);
};

class db_filedb_key_empty final : public db_filedb_Key {
 public:

  db_filedb_key_empty();

  static const std::int32_t ID = 2080319307;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_empty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_blockFile final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;

  db_filedb_key_blockFile();

  explicit db_filedb_key_blockFile(object_ptr<tonNode_blockIdExt> &&block_id_);

  static const std::int32_t ID = -1326783375;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_blockFile(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_zeroStateFile final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;

  db_filedb_key_zeroStateFile();

  explicit db_filedb_key_zeroStateFile(object_ptr<tonNode_blockIdExt> &&block_id_);

  static const std::int32_t ID = 307398205;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_zeroStateFile(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_persistentStateFile final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;
  object_ptr<tonNode_blockIdExt> masterchain_block_id_;

  db_filedb_key_persistentStateFile();

  db_filedb_key_persistentStateFile(object_ptr<tonNode_blockIdExt> &&block_id_, object_ptr<tonNode_blockIdExt> &&masterchain_block_id_);

  static const std::int32_t ID = -1346996660;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_persistentStateFile(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_proof final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;

  db_filedb_key_proof();

  explicit db_filedb_key_proof(object_ptr<tonNode_blockIdExt> &&block_id_);

  static const std::int32_t ID = -627749396;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_proof(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_proofLink final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;

  db_filedb_key_proofLink();

  explicit db_filedb_key_proofLink(object_ptr<tonNode_blockIdExt> &&block_id_);

  static const std::int32_t ID = -1728330290;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_proofLink(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_signatures final : public db_filedb_Key {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;

  db_filedb_key_signatures();

  explicit db_filedb_key_signatures(object_ptr<tonNode_blockIdExt> &&block_id_);

  static const std::int32_t ID = -685175541;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_signatures(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_key_candidate final : public db_filedb_Key {
 public:
  object_ptr<db_candidate_id> id_;

  db_filedb_key_candidate();

  explicit db_filedb_key_candidate(object_ptr<db_candidate_id> &&id_);

  static const std::int32_t ID = -494269767;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_Key> fetch(td::TlParser &p);

  explicit db_filedb_key_candidate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_filedb_value final : public Object {
 public:
  object_ptr<db_filedb_Key> key_;
  td::Bits256 prev_;
  td::Bits256 next_;
  td::Bits256 file_hash_;

  db_filedb_value();

  db_filedb_value(object_ptr<db_filedb_Key> &&key_, td::Bits256 const &prev_, td::Bits256 const &next_, td::Bits256 const &file_hash_);

  static const std::int32_t ID = -220390867;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_filedb_value> fetch(td::TlParser &p);

  explicit db_filedb_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_Key: public Object {
 public:

  static object_ptr<db_lt_Key> fetch(td::TlParser &p);
};

class db_lt_el_key final : public db_lt_Key {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t idx_;

  db_lt_el_key();

  db_lt_el_key(std::int32_t workchain_, std::int64_t shard_, std::int32_t idx_);

  static const std::int32_t ID = -1523442974;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_Key> fetch(td::TlParser &p);

  explicit db_lt_el_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_desc_key final : public db_lt_Key {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;

  db_lt_desc_key();

  db_lt_desc_key(std::int32_t workchain_, std::int64_t shard_);

  static const std::int32_t ID = -236722287;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_Key> fetch(td::TlParser &p);

  explicit db_lt_desc_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_shard_key final : public db_lt_Key {
 public:
  std::int32_t idx_;

  db_lt_shard_key();

  explicit db_lt_shard_key(std::int32_t idx_);

  static const std::int32_t ID = 1353120015;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_Key> fetch(td::TlParser &p);

  explicit db_lt_shard_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_status_key final : public db_lt_Key {
 public:

  db_lt_status_key();

  static const std::int32_t ID = 2003591255;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_Key> fetch(td::TlParser &p);

  explicit db_lt_status_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_desc_value final : public Object {
 public:
  std::int32_t first_idx_;
  std::int32_t last_idx_;
  std::int32_t last_seqno_;
  std::int64_t last_lt_;
  std::int32_t last_ts_;

  db_lt_desc_value();

  db_lt_desc_value(std::int32_t first_idx_, std::int32_t last_idx_, std::int32_t last_seqno_, std::int64_t last_lt_, std::int32_t last_ts_);

  static const std::int32_t ID = 1907315124;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_desc_value> fetch(td::TlParser &p);

  explicit db_lt_desc_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_el_value final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  std::int64_t lt_;
  std::int32_t ts_;

  db_lt_el_value();

  db_lt_el_value(object_ptr<tonNode_blockIdExt> &&id_, std::int64_t lt_, std::int32_t ts_);

  static const std::int32_t ID = -1780064412;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_el_value> fetch(td::TlParser &p);

  explicit db_lt_el_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_shard_value final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;

  db_lt_shard_value();

  db_lt_shard_value(std::int32_t workchain_, std::int64_t shard_);

  static const std::int32_t ID = 1014209147;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_shard_value> fetch(td::TlParser &p);

  explicit db_lt_shard_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_lt_status_value final : public Object {
 public:
  std::int32_t total_shards_;

  db_lt_status_value();

  explicit db_lt_status_value(std::int32_t total_shards_);

  static const std::int32_t ID = -88150727;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_lt_status_value> fetch(td::TlParser &p);

  explicit db_lt_status_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_root_config final : public Object {
 public:
  std::int32_t celldb_version_;
  std::int32_t blockdb_version_;

  db_root_config();

  db_root_config(std::int32_t celldb_version_, std::int32_t blockdb_version_);

  static const std::int32_t ID = -703495519;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_root_config> fetch(td::TlParser &p);

  explicit db_root_config(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_root_dbDescription final : public Object {
 public:
  std::int32_t version_;
  object_ptr<tonNode_blockIdExt> first_masterchain_block_id_;
  std::int32_t flags_;

  db_root_dbDescription();

  db_root_dbDescription(std::int32_t version_, object_ptr<tonNode_blockIdExt> &&first_masterchain_block_id_, std::int32_t flags_);

  static const std::int32_t ID = -1273465869;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_root_dbDescription> fetch(td::TlParser &p);

  explicit db_root_dbDescription(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_root_Key: public Object {
 public:

  static object_ptr<db_root_Key> fetch(td::TlParser &p);
};

class db_root_key_cellDb final : public db_root_Key {
 public:
  std::int32_t version_;

  db_root_key_cellDb();

  explicit db_root_key_cellDb(std::int32_t version_);

  static const std::int32_t ID = 1928966974;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_root_Key> fetch(td::TlParser &p);

  explicit db_root_key_cellDb(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_root_key_blockDb final : public db_root_Key {
 public:
  std::int32_t version_;

  db_root_key_blockDb();

  explicit db_root_key_blockDb(std::int32_t version_);

  static const std::int32_t ID = 806534976;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_root_Key> fetch(td::TlParser &p);

  explicit db_root_key_blockDb(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_root_key_config final : public db_root_Key {
 public:

  db_root_key_config();

  static const std::int32_t ID = 331559556;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_root_Key> fetch(td::TlParser &p);

  explicit db_root_key_config(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_asyncSerializer final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  object_ptr<tonNode_blockIdExt> last_;
  std::int32_t last_ts_;

  db_state_asyncSerializer();

  db_state_asyncSerializer(object_ptr<tonNode_blockIdExt> &&block_, object_ptr<tonNode_blockIdExt> &&last_, std::int32_t last_ts_);

  static const std::int32_t ID = -751883871;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_asyncSerializer> fetch(td::TlParser &p);

  explicit db_state_asyncSerializer(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_destroyedSessions final : public Object {
 public:
  std::vector<td::Bits256> sessions_;

  db_state_destroyedSessions();

  explicit db_state_destroyedSessions(std::vector<td::Bits256> &&sessions_);

  static const std::int32_t ID = -1381443196;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_destroyedSessions> fetch(td::TlParser &p);

  explicit db_state_destroyedSessions(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_gcBlockId final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  db_state_gcBlockId();

  explicit db_state_gcBlockId(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = -550453937;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_gcBlockId> fetch(td::TlParser &p);

  explicit db_state_gcBlockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_initBlockId final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  db_state_initBlockId();

  explicit db_state_initBlockId(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 1932303605;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_initBlockId> fetch(td::TlParser &p);

  explicit db_state_initBlockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_Key: public Object {
 public:

  static object_ptr<db_state_Key> fetch(td::TlParser &p);
};

class db_state_key_destroyedSessions final : public db_state_Key {
 public:

  db_state_key_destroyedSessions();

  static const std::int32_t ID = -386404007;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_Key> fetch(td::TlParser &p);

  explicit db_state_key_destroyedSessions(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_key_initBlockId final : public db_state_Key {
 public:

  db_state_key_initBlockId();

  static const std::int32_t ID = 1971484899;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_Key> fetch(td::TlParser &p);

  explicit db_state_key_initBlockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_key_gcBlockId final : public db_state_Key {
 public:

  db_state_key_gcBlockId();

  static const std::int32_t ID = -1015417890;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_Key> fetch(td::TlParser &p);

  explicit db_state_key_gcBlockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_key_shardClient final : public db_state_Key {
 public:

  db_state_key_shardClient();

  static const std::int32_t ID = -912576121;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_Key> fetch(td::TlParser &p);

  explicit db_state_key_shardClient(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_key_asyncSerializer final : public db_state_Key {
 public:

  db_state_key_asyncSerializer();

  static const std::int32_t ID = 699304479;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_Key> fetch(td::TlParser &p);

  explicit db_state_key_asyncSerializer(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class db_state_shardClient final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  db_state_shardClient();

  explicit db_state_shardClient(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 186033821;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<db_state_shardClient> fetch(td::TlParser &p);

  explicit db_state_shardClient(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_key final : public Object {
 public:
  td::Bits256 id_;
  td::BufferSlice name_;
  std::int32_t idx_;

  dht_key();

  dht_key(td::Bits256 const &id_, td::BufferSlice &&name_, std::int32_t idx_);

  static const std::int32_t ID = -160964977;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_key> fetch(td::TlParser &p);

  explicit dht_key(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_keyDescription final : public Object {
 public:
  object_ptr<dht_key> key_;
  object_ptr<PublicKey> id_;
  object_ptr<dht_UpdateRule> update_rule_;
  td::BufferSlice signature_;

  dht_keyDescription();

  dht_keyDescription(object_ptr<dht_key> &&key_, object_ptr<PublicKey> &&id_, object_ptr<dht_UpdateRule> &&update_rule_, td::BufferSlice &&signature_);

  static const std::int32_t ID = 673009157;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_keyDescription> fetch(td::TlParser &p);

  explicit dht_keyDescription(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_message final : public Object {
 public:
  object_ptr<dht_node> node_;

  dht_message();

  explicit dht_message(object_ptr<dht_node> &&node_);

  static const std::int32_t ID = -1140008050;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_message> fetch(td::TlParser &p);

  explicit dht_message(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_node final : public Object {
 public:
  object_ptr<PublicKey> id_;
  object_ptr<adnl_addressList> addr_list_;
  std::int32_t version_;
  td::BufferSlice signature_;

  dht_node();

  dht_node(object_ptr<PublicKey> &&id_, object_ptr<adnl_addressList> &&addr_list_, std::int32_t version_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -2074922424;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_node> fetch(td::TlParser &p);

  explicit dht_node(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_nodes final : public Object {
 public:
  std::vector<object_ptr<dht_node>> nodes_;

  dht_nodes();

  explicit dht_nodes(std::vector<object_ptr<dht_node>> &&nodes_);

  static const std::int32_t ID = 2037686462;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_nodes> fetch(td::TlParser &p);

  explicit dht_nodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_pong final : public Object {
 public:
  std::int64_t random_id_;

  dht_pong();

  explicit dht_pong(std::int64_t random_id_);

  static const std::int32_t ID = 1519054721;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_pong> fetch(td::TlParser &p);

  explicit dht_pong(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_stored final : public Object {
 public:

  dht_stored();

  static const std::int32_t ID = 1881602824;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_stored> fetch(td::TlParser &p);

  explicit dht_stored(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_UpdateRule: public Object {
 public:

  static object_ptr<dht_UpdateRule> fetch(td::TlParser &p);
};

class dht_updateRule_signature final : public dht_UpdateRule {
 public:

  dht_updateRule_signature();

  static const std::int32_t ID = -861982217;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_UpdateRule> fetch(td::TlParser &p);

  explicit dht_updateRule_signature(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_updateRule_anybody final : public dht_UpdateRule {
 public:

  dht_updateRule_anybody();

  static const std::int32_t ID = 1633127956;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_UpdateRule> fetch(td::TlParser &p);

  explicit dht_updateRule_anybody(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_updateRule_overlayNodes final : public dht_UpdateRule {
 public:

  dht_updateRule_overlayNodes();

  static const std::int32_t ID = 645370755;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_UpdateRule> fetch(td::TlParser &p);

  explicit dht_updateRule_overlayNodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_value final : public Object {
 public:
  object_ptr<dht_keyDescription> key_;
  td::BufferSlice value_;
  std::int32_t ttl_;
  td::BufferSlice signature_;

  dht_value();

  dht_value(object_ptr<dht_keyDescription> &&key_, td::BufferSlice &&value_, std::int32_t ttl_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -1867700277;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_value> fetch(td::TlParser &p);

  explicit dht_value(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_ValueResult: public Object {
 public:

  static object_ptr<dht_ValueResult> fetch(td::TlParser &p);
};

class dht_valueNotFound final : public dht_ValueResult {
 public:
  object_ptr<dht_nodes> nodes_;

  dht_valueNotFound();

  explicit dht_valueNotFound(object_ptr<dht_nodes> &&nodes_);

  static const std::int32_t ID = -1570634392;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_ValueResult> fetch(td::TlParser &p);

  explicit dht_valueNotFound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_valueFound final : public dht_ValueResult {
 public:
  object_ptr<dht_value> value_;

  dht_valueFound();

  explicit dht_valueFound(object_ptr<dht_value> &&value_);

  static const std::int32_t ID = -468912268;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_ValueResult> fetch(td::TlParser &p);

  explicit dht_valueFound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_config_global final : public Object {
 public:
  object_ptr<dht_nodes> static_nodes_;
  std::int32_t k_;
  std::int32_t a_;

  dht_config_global();

  dht_config_global(object_ptr<dht_nodes> &&static_nodes_, std::int32_t k_, std::int32_t a_);

  static const std::int32_t ID = -2066822649;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_config_global> fetch(td::TlParser &p);

  explicit dht_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_config_Local: public Object {
 public:

  static object_ptr<dht_config_Local> fetch(td::TlParser &p);
};

class dht_config_local final : public dht_config_Local {
 public:
  object_ptr<adnl_id_short> id_;

  dht_config_local();

  explicit dht_config_local(object_ptr<adnl_id_short> &&id_);

  static const std::int32_t ID = 1981827695;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_config_Local> fetch(td::TlParser &p);

  explicit dht_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_config_random_local final : public dht_config_Local {
 public:
  std::int32_t cnt_;
  object_ptr<adnl_addressList> addr_list_;

  dht_config_random_local();

  dht_config_random_local(std::int32_t cnt_, object_ptr<adnl_addressList> &&addr_list_);

  static const std::int32_t ID = 1584494022;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_config_Local> fetch(td::TlParser &p);

  explicit dht_config_random_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_db_bucket final : public Object {
 public:
  object_ptr<dht_nodes> nodes_;

  dht_db_bucket();

  explicit dht_db_bucket(object_ptr<dht_nodes> &&nodes_);

  static const std::int32_t ID = -1281557908;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_db_bucket> fetch(td::TlParser &p);

  explicit dht_db_bucket(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dht_db_key_bucket final : public Object {
 public:
  std::int32_t id_;

  dht_db_key_bucket();

  explicit dht_db_key_bucket(std::int32_t id_);

  static const std::int32_t ID = -1553420724;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dht_db_key_bucket> fetch(td::TlParser &p);

  explicit dht_db_key_bucket(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dummyworkchain0_config_global final : public Object {
 public:
  td::Bits256 zero_state_hash_;

  dummyworkchain0_config_global();

  explicit dummyworkchain0_config_global(td::Bits256 const &zero_state_hash_);

  static const std::int32_t ID = -631148845;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dummyworkchain0_config_global> fetch(td::TlParser &p);

  explicit dummyworkchain0_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class dummyworkchain0_config_local final : public Object {
 public:
  object_ptr<adnl_id_short> id_;

  dummyworkchain0_config_local();

  explicit dummyworkchain0_config_local(object_ptr<adnl_id_short> &&id_);

  static const std::int32_t ID = -1220354201;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dummyworkchain0_config_local> fetch(td::TlParser &p);

  explicit dummyworkchain0_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class fec_Type: public Object {
 public:

  static object_ptr<fec_Type> fetch(td::TlParser &p);
};

class fec_raptorQ final : public fec_Type {
 public:
  std::int32_t data_size_;
  std::int32_t symbol_size_;
  std::int32_t symbols_count_;

  fec_raptorQ();

  fec_raptorQ(std::int32_t data_size_, std::int32_t symbol_size_, std::int32_t symbols_count_);

  static const std::int32_t ID = -1953257504;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<fec_Type> fetch(td::TlParser &p);

  explicit fec_raptorQ(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class fec_roundRobin final : public fec_Type {
 public:
  std::int32_t data_size_;
  std::int32_t symbol_size_;
  std::int32_t symbols_count_;

  fec_roundRobin();

  fec_roundRobin(std::int32_t data_size_, std::int32_t symbol_size_, std::int32_t symbols_count_);

  static const std::int32_t ID = 854927588;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<fec_Type> fetch(td::TlParser &p);

  explicit fec_roundRobin(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class fec_online final : public fec_Type {
 public:
  std::int32_t data_size_;
  std::int32_t symbol_size_;
  std::int32_t symbols_count_;

  fec_online();

  fec_online(std::int32_t data_size_, std::int32_t symbol_size_, std::int32_t symbols_count_);

  static const std::int32_t ID = 19359244;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<fec_Type> fetch(td::TlParser &p);

  explicit fec_online(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class id_config_local final : public Object {
 public:
  object_ptr<PrivateKey> id_;
  object_ptr<adnl_addressList> addr_list_;

  id_config_local();

  id_config_local(object_ptr<PrivateKey> &&id_, object_ptr<adnl_addressList> &&addr_list_);

  static const std::int32_t ID = 488427039;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<id_config_local> fetch(td::TlParser &p);

  explicit id_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class liteclient_config_global final : public Object {
 public:
  object_ptr<PublicKey> id_;
  std::int32_t ip_;
  std::int32_t port_;

  liteclient_config_global();

  liteclient_config_global(object_ptr<PublicKey> &&id_, std::int32_t ip_, std::int32_t port_);

  static const std::int32_t ID = 1100678618;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<liteclient_config_global> fetch(td::TlParser &p);

  explicit liteclient_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class liteserver_config_local final : public Object {
 public:
  object_ptr<PrivateKey> id_;
  std::int32_t port_;

  liteserver_config_local();

  liteserver_config_local(object_ptr<PrivateKey> &&id_, std::int32_t port_);

  static const std::int32_t ID = 1182002063;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<liteserver_config_local> fetch(td::TlParser &p);

  explicit liteserver_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_Broadcast: public Object {
 public:

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);
};

class overlay_fec_received final : public overlay_Broadcast {
 public:
  td::Bits256 hash_;

  overlay_fec_received();

  explicit overlay_fec_received(td::Bits256 const &hash_);

  static const std::int32_t ID = -715385620;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_fec_received(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_fec_completed final : public overlay_Broadcast {
 public:
  td::Bits256 hash_;

  overlay_fec_completed();

  explicit overlay_fec_completed(td::Bits256 const &hash_);

  static const std::int32_t ID = 165112084;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_fec_completed(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_unicast final : public overlay_Broadcast {
 public:
  td::BufferSlice data_;

  overlay_unicast();

  explicit overlay_unicast(td::BufferSlice &&data_);

  static const std::int32_t ID = 861097508;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_unicast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcast final : public overlay_Broadcast {
 public:
  object_ptr<PublicKey> src_;
  object_ptr<overlay_Certificate> certificate_;
  std::int32_t flags_;
  td::BufferSlice data_;
  std::int32_t date_;
  td::BufferSlice signature_;

  overlay_broadcast();

  overlay_broadcast(object_ptr<PublicKey> &&src_, object_ptr<overlay_Certificate> &&certificate_, std::int32_t flags_, td::BufferSlice &&data_, std::int32_t date_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -1319490709;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_broadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastFec final : public overlay_Broadcast {
 public:
  object_ptr<PublicKey> src_;
  object_ptr<overlay_Certificate> certificate_;
  td::Bits256 data_hash_;
  std::int32_t data_size_;
  std::int32_t flags_;
  td::BufferSlice data_;
  std::int32_t seqno_;
  object_ptr<fec_Type> fec_;
  std::int32_t date_;
  td::BufferSlice signature_;

  overlay_broadcastFec();

  overlay_broadcastFec(object_ptr<PublicKey> &&src_, object_ptr<overlay_Certificate> &&certificate_, td::Bits256 const &data_hash_, std::int32_t data_size_, std::int32_t flags_, td::BufferSlice &&data_, std::int32_t seqno_, object_ptr<fec_Type> &&fec_, std::int32_t date_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -1160264854;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_broadcastFec(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastFecShort final : public overlay_Broadcast {
 public:
  object_ptr<PublicKey> src_;
  object_ptr<overlay_Certificate> certificate_;
  td::Bits256 broadcast_hash_;
  td::Bits256 part_data_hash_;
  std::int32_t seqno_;
  td::BufferSlice signature_;

  overlay_broadcastFecShort();

  overlay_broadcastFecShort(object_ptr<PublicKey> &&src_, object_ptr<overlay_Certificate> &&certificate_, td::Bits256 const &broadcast_hash_, td::Bits256 const &part_data_hash_, std::int32_t seqno_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -242740414;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_broadcastFecShort(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastNotFound final : public overlay_Broadcast {
 public:

  overlay_broadcastNotFound();

  static const std::int32_t ID = -1786366428;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Broadcast> fetch(td::TlParser &p);

  explicit overlay_broadcastNotFound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastList final : public Object {
 public:
  std::vector<td::Bits256> hashes_;

  overlay_broadcastList();

  explicit overlay_broadcastList(std::vector<td::Bits256> &&hashes_);

  static const std::int32_t ID = 416407263;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_broadcastList> fetch(td::TlParser &p);

  explicit overlay_broadcastList(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_Certificate: public Object {
 public:

  static object_ptr<overlay_Certificate> fetch(td::TlParser &p);
};

class overlay_certificate final : public overlay_Certificate {
 public:
  object_ptr<PublicKey> issued_by_;
  std::int32_t expire_at_;
  std::int32_t max_size_;
  td::BufferSlice signature_;

  overlay_certificate();

  overlay_certificate(object_ptr<PublicKey> &&issued_by_, std::int32_t expire_at_, std::int32_t max_size_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -526461135;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Certificate> fetch(td::TlParser &p);

  explicit overlay_certificate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_emptyCertificate final : public overlay_Certificate {
 public:

  overlay_emptyCertificate();

  static const std::int32_t ID = 853195983;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_Certificate> fetch(td::TlParser &p);

  explicit overlay_emptyCertificate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_certificateId final : public Object {
 public:
  td::Bits256 overlay_id_;
  td::Bits256 node_;
  std::int32_t expire_at_;
  std::int32_t max_size_;

  overlay_certificateId();

  overlay_certificateId(td::Bits256 const &overlay_id_, td::Bits256 const &node_, std::int32_t expire_at_, std::int32_t max_size_);

  static const std::int32_t ID = -1884397383;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_certificateId> fetch(td::TlParser &p);

  explicit overlay_certificateId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_message final : public Object {
 public:
  td::Bits256 overlay_;

  overlay_message();

  explicit overlay_message(td::Bits256 const &overlay_);

  static const std::int32_t ID = 1965368352;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_message> fetch(td::TlParser &p);

  explicit overlay_message(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_node final : public Object {
 public:
  object_ptr<PublicKey> id_;
  td::Bits256 overlay_;
  std::int32_t version_;
  td::BufferSlice signature_;

  overlay_node();

  overlay_node(object_ptr<PublicKey> &&id_, td::Bits256 const &overlay_, std::int32_t version_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -1200911741;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_node> fetch(td::TlParser &p);

  explicit overlay_node(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_nodes final : public Object {
 public:
  std::vector<object_ptr<overlay_node>> nodes_;

  overlay_nodes();

  explicit overlay_nodes(std::vector<object_ptr<overlay_node>> &&nodes_);

  static const std::int32_t ID = -460904178;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_nodes> fetch(td::TlParser &p);

  explicit overlay_nodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcast_id final : public Object {
 public:
  td::Bits256 src_;
  td::Bits256 data_hash_;
  std::int32_t flags_;

  overlay_broadcast_id();

  overlay_broadcast_id(td::Bits256 const &src_, td::Bits256 const &data_hash_, std::int32_t flags_);

  static const std::int32_t ID = 1375565978;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_broadcast_id> fetch(td::TlParser &p);

  explicit overlay_broadcast_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcast_toSign final : public Object {
 public:
  td::Bits256 hash_;
  std::int32_t date_;

  overlay_broadcast_toSign();

  overlay_broadcast_toSign(td::Bits256 const &hash_, std::int32_t date_);

  static const std::int32_t ID = -97038724;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_broadcast_toSign> fetch(td::TlParser &p);

  explicit overlay_broadcast_toSign(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastFec_id final : public Object {
 public:
  td::Bits256 src_;
  td::Bits256 type_;
  td::Bits256 data_hash_;
  std::int32_t size_;
  std::int32_t flags_;

  overlay_broadcastFec_id();

  overlay_broadcastFec_id(td::Bits256 const &src_, td::Bits256 const &type_, td::Bits256 const &data_hash_, std::int32_t size_, std::int32_t flags_);

  static const std::int32_t ID = -80652890;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_broadcastFec_id> fetch(td::TlParser &p);

  explicit overlay_broadcastFec_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_broadcastFec_partId final : public Object {
 public:
  td::Bits256 broadcast_hash_;
  td::Bits256 data_hash_;
  std::int32_t seqno_;

  overlay_broadcastFec_partId();

  overlay_broadcastFec_partId(td::Bits256 const &broadcast_hash_, td::Bits256 const &data_hash_, std::int32_t seqno_);

  static const std::int32_t ID = -1536597296;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_broadcastFec_partId> fetch(td::TlParser &p);

  explicit overlay_broadcastFec_partId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_config_Local: public Object {
 public:

  static object_ptr<overlay_config_Local> fetch(td::TlParser &p);
};

class overlay_config_local final : public overlay_config_Local {
 public:
  td::BufferSlice name_;
  object_ptr<adnl_id_short> id_;

  overlay_config_local();

  overlay_config_local(td::BufferSlice &&name_, object_ptr<adnl_id_short> &&id_);

  static const std::int32_t ID = 784541096;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_config_Local> fetch(td::TlParser &p);

  explicit overlay_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_config_random_local final : public overlay_config_Local {
 public:
  std::int32_t cnt_;
  td::BufferSlice name_;
  object_ptr<adnl_addressList> addr_list_;

  overlay_config_random_local();

  overlay_config_random_local(std::int32_t cnt_, td::BufferSlice &&name_, object_ptr<adnl_addressList> &&addr_list_);

  static const std::int32_t ID = 688042922;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_config_Local> fetch(td::TlParser &p);

  explicit overlay_config_random_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_db_key_nodes final : public Object {
 public:
  td::Bits256 local_id_;
  td::Bits256 overlay_;

  overlay_db_key_nodes();

  overlay_db_key_nodes(td::Bits256 const &local_id_, td::Bits256 const &overlay_);

  static const std::int32_t ID = -992972010;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_db_key_nodes> fetch(td::TlParser &p);

  explicit overlay_db_key_nodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_db_nodes final : public Object {
 public:
  object_ptr<overlay_nodes> nodes_;

  overlay_db_nodes();

  explicit overlay_db_nodes(object_ptr<overlay_nodes> &&nodes_);

  static const std::int32_t ID = -712454630;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_db_nodes> fetch(td::TlParser &p);

  explicit overlay_db_nodes(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class overlay_node_toSign final : public Object {
 public:
  object_ptr<adnl_id_short> id_;
  td::Bits256 overlay_;
  std::int32_t version_;

  overlay_node_toSign();

  overlay_node_toSign(object_ptr<adnl_id_short> &&id_, td::Bits256 const &overlay_, std::int32_t version_);

  static const std::int32_t ID = 64530657;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<overlay_node_toSign> fetch(td::TlParser &p);

  explicit overlay_node_toSign(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_Message: public Object {
 public:

  static object_ptr<rldp_Message> fetch(td::TlParser &p);
};

class rldp_message final : public rldp_Message {
 public:
  td::Bits256 id_;
  td::BufferSlice data_;

  rldp_message();

  rldp_message(td::Bits256 const &id_, td::BufferSlice &&data_);

  static const std::int32_t ID = 2098973982;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_Message> fetch(td::TlParser &p);

  explicit rldp_message(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_query final : public rldp_Message {
 public:
  td::Bits256 query_id_;
  std::int32_t timeout_;
  td::BufferSlice data_;

  rldp_query();

  rldp_query(td::Bits256 const &query_id_, std::int32_t timeout_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1478977815;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_Message> fetch(td::TlParser &p);

  explicit rldp_query(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_answer final : public rldp_Message {
 public:
  td::Bits256 query_id_;
  td::BufferSlice data_;

  rldp_answer();

  rldp_answer(td::Bits256 const &query_id_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1543742461;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_Message> fetch(td::TlParser &p);

  explicit rldp_answer(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_MessagePart: public Object {
 public:

  static object_ptr<rldp_MessagePart> fetch(td::TlParser &p);
};

class rldp_messagePart final : public rldp_MessagePart {
 public:
  td::Bits256 transfer_id_;
  object_ptr<fec_Type> fec_type_;
  std::int32_t part_;
  std::int64_t total_size_;
  std::int32_t seqno_;
  td::BufferSlice data_;

  rldp_messagePart();

  rldp_messagePart(td::Bits256 const &transfer_id_, object_ptr<fec_Type> &&fec_type_, std::int32_t part_, std::int64_t total_size_, std::int32_t seqno_, td::BufferSlice &&data_);

  static const std::int32_t ID = 408691404;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_MessagePart> fetch(td::TlParser &p);

  explicit rldp_messagePart(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_confirm final : public rldp_MessagePart {
 public:
  td::Bits256 transfer_id_;
  std::int32_t part_;
  std::int32_t seqno_;

  rldp_confirm();

  rldp_confirm(td::Bits256 const &transfer_id_, std::int32_t part_, std::int32_t seqno_);

  static const std::int32_t ID = -175973288;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_MessagePart> fetch(td::TlParser &p);

  explicit rldp_confirm(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class rldp_complete final : public rldp_MessagePart {
 public:
  td::Bits256 transfer_id_;
  std::int32_t part_;

  rldp_complete();

  rldp_complete(td::Bits256 const &transfer_id_, std::int32_t part_);

  static const std::int32_t ID = -1140018497;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<rldp_MessagePart> fetch(td::TlParser &p);

  explicit rldp_complete(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tcp_pong final : public Object {
 public:
  std::int64_t random_id_;

  tcp_pong();

  explicit tcp_pong(std::int64_t random_id_);

  static const std::int32_t ID = -597034237;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tcp_pong> fetch(td::TlParser &p);

  explicit tcp_pong(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_proof final : public Object {
 public:
  object_ptr<test0_proofLink> link_;
  std::int32_t catchain_seqno_;
  std::int32_t validator_set_hash_;
  object_ptr<test0_blockSignatures> signatures_;

  test0_proof();

  test0_proof(object_ptr<test0_proofLink> &&link_, std::int32_t catchain_seqno_, std::int32_t validator_set_hash_, object_ptr<test0_blockSignatures> &&signatures_);

  static const std::int32_t ID = 240739136;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_proof> fetch(td::TlParser &p);

  explicit test0_proof(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_proofLink final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  std::vector<object_ptr<tonNode_blockIdExt>> prev_;
  td::Bits256 state_;
  bool split_;

  test0_proofLink();

  test0_proofLink(object_ptr<tonNode_blockIdExt> &&id_, std::vector<object_ptr<tonNode_blockIdExt>> &&prev_, td::Bits256 const &state_, bool split_);

  static const std::int32_t ID = 198411810;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_proofLink> fetch(td::TlParser &p);

  explicit test0_proofLink(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_shardchain_block final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t seqno_;
  std::vector<object_ptr<tonNode_blockIdExt>> prev_;
  bool split_;
  std::int32_t ts_;
  td::Bits256 state_;
  std::int32_t catchain_seqno_;
  std::int32_t validator_set_hash_;
  td::BufferSlice pad_;
  object_ptr<test0_MasterchainBlockExtra> extra_;

  test0_shardchain_block();

  test0_shardchain_block(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, std::vector<object_ptr<tonNode_blockIdExt>> &&prev_, bool split_, std::int32_t ts_, td::Bits256 const &state_, std::int32_t catchain_seqno_, std::int32_t validator_set_hash_, td::BufferSlice &&pad_, object_ptr<test0_MasterchainBlockExtra> &&extra_);

  static const std::int32_t ID = 168970719;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_shardchain_block> fetch(td::TlParser &p);

  explicit test0_shardchain_block(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_shardchain_state final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t seqno_;
  std::int32_t ts_;
  bool split_;
  object_ptr<test0_MasterchainStateExtra> extra_;

  test0_shardchain_state();

  test0_shardchain_state(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, std::int32_t ts_, bool split_, object_ptr<test0_MasterchainStateExtra> &&extra_);

  static const std::int32_t ID = -1819502437;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_shardchain_state> fetch(td::TlParser &p);

  explicit test0_shardchain_state(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test_validatorSession_block final : public Object {
 public:
  td::Bits256 root_hash_;
  std::int64_t height_;
  td::BufferSlice data_;

  test_validatorSession_block();

  test_validatorSession_block(td::Bits256 const &root_hash_, std::int64_t height_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1418990707;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test_validatorSession_block> fetch(td::TlParser &p);

  explicit test_validatorSession_block(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_blockSignatures final : public Object {
 public:
  std::vector<object_ptr<tonNode_blockSignature>> signatures_;

  test0_blockSignatures();

  explicit test0_blockSignatures(std::vector<object_ptr<tonNode_blockSignature>> &&signatures_);

  static const std::int32_t ID = -1512447916;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_blockSignatures> fetch(td::TlParser &p);

  explicit test0_blockSignatures(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_extMessage final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  td::BufferSlice data_;

  test0_extMessage();

  test0_extMessage(std::int32_t workchain_, std::int64_t shard_, td::BufferSlice &&data_);

  static const std::int32_t ID = -424680397;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_extMessage> fetch(td::TlParser &p);

  explicit test0_extMessage(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_MasterchainBlockExtra: public Object {
 public:

  static object_ptr<test0_MasterchainBlockExtra> fetch(td::TlParser &p);
};

class test0_masterchainBlockExtra_empty final : public test0_MasterchainBlockExtra {
 public:

  test0_masterchainBlockExtra_empty();

  static const std::int32_t ID = -1793623372;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_MasterchainBlockExtra> fetch(td::TlParser &p);

  explicit test0_masterchainBlockExtra_empty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_masterchainBlockExtra_extra final : public test0_MasterchainBlockExtra {
 public:
  std::int32_t randseed_;
  bool rotate_;
  std::vector<object_ptr<test0_masterchain_shardInfo>> shards_;

  test0_masterchainBlockExtra_extra();

  test0_masterchainBlockExtra_extra(std::int32_t randseed_, bool rotate_, std::vector<object_ptr<test0_masterchain_shardInfo>> &&shards_);

  static const std::int32_t ID = -2070859848;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_MasterchainBlockExtra> fetch(td::TlParser &p);

  explicit test0_masterchainBlockExtra_extra(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_MasterchainStateExtra: public Object {
 public:

  static object_ptr<test0_MasterchainStateExtra> fetch(td::TlParser &p);
};

class test0_masterchainStateExtra_empty final : public test0_MasterchainStateExtra {
 public:

  test0_masterchainStateExtra_empty();

  static const std::int32_t ID = -1491361123;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_MasterchainStateExtra> fetch(td::TlParser &p);

  explicit test0_masterchainStateExtra_empty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_masterchainStateExtra_extra final : public test0_MasterchainStateExtra {
 public:
  std::int32_t validator_ts_;
  std::int32_t validator_randseed_;
  std::int32_t next_randseed_;
  std::int32_t next_rotate_at_;
  std::vector<object_ptr<tonNode_blockIdExt>> prev_blocks_;
  std::vector<object_ptr<test0_masterchain_shardInfo>> shards_;
  std::vector<object_ptr<PublicKey>> pool_;

  test0_masterchainStateExtra_extra();

  test0_masterchainStateExtra_extra(std::int32_t validator_ts_, std::int32_t validator_randseed_, std::int32_t next_randseed_, std::int32_t next_rotate_at_, std::vector<object_ptr<tonNode_blockIdExt>> &&prev_blocks_, std::vector<object_ptr<test0_masterchain_shardInfo>> &&shards_, std::vector<object_ptr<PublicKey>> &&pool_);

  static const std::int32_t ID = -1205072155;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_MasterchainStateExtra> fetch(td::TlParser &p);

  explicit test0_masterchainStateExtra_extra(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_topShardBlockDescription final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_id_;
  bool after_split_;
  bool after_merge_;
  bool before_split_;
  std::int32_t catchain_seqno_;
  std::int32_t validator_set_hash_;
  td::BufferSlice signatures_;

  test0_topShardBlockDescription();

  test0_topShardBlockDescription(object_ptr<tonNode_blockIdExt> &&block_id_, bool after_split_, bool after_merge_, bool before_split_, std::int32_t catchain_seqno_, std::int32_t validator_set_hash_, td::BufferSlice &&signatures_);

  static const std::int32_t ID = 723951200;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_topShardBlockDescription> fetch(td::TlParser &p);

  explicit test0_topShardBlockDescription(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_validatorSessionId final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int64_t shard_from_;
  std::int32_t ts_;

  test0_validatorSessionId();

  test0_validatorSessionId(std::int32_t workchain_, std::int64_t shard_, std::int64_t shard_from_, std::int32_t ts_);

  static const std::int32_t ID = -1695860169;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_validatorSessionId> fetch(td::TlParser &p);

  explicit test0_validatorSessionId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_validatorSet final : public Object {
 public:
  std::int32_t ts_;
  std::vector<object_ptr<test0_validatorSetItem>> validators_;

  test0_validatorSet();

  test0_validatorSet(std::int32_t ts_, std::vector<object_ptr<test0_validatorSetItem>> &&validators_);

  static const std::int32_t ID = -1877581587;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_validatorSet> fetch(td::TlParser &p);

  explicit test0_validatorSet(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_validatorSetItem final : public Object {
 public:
  td::Bits256 id_;
  std::int64_t weight_;

  test0_validatorSetItem();

  test0_validatorSetItem(td::Bits256 const &id_, std::int64_t weight_);

  static const std::int32_t ID = 408501132;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_validatorSetItem> fetch(td::TlParser &p);

  explicit test0_validatorSetItem(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class test0_masterchain_shardInfo final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> last_block_;
  bool before_merge_;
  bool before_split_;
  bool after_merge_;
  bool after_split_;

  test0_masterchain_shardInfo();

  test0_masterchain_shardInfo(object_ptr<tonNode_blockIdExt> &&last_block_, bool before_merge_, bool before_split_, bool after_merge_, bool after_split_);

  static const std::int32_t ID = 262681349;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<test0_masterchain_shardInfo> fetch(td::TlParser &p);

  explicit test0_masterchain_shardInfo(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class ton_blockId final : public Object {
 public:
  td::Bits256 root_cell_hash_;
  td::Bits256 file_hash_;

  ton_blockId();

  ton_blockId(td::Bits256 const &root_cell_hash_, td::Bits256 const &file_hash_);

  static const std::int32_t ID = -989106576;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<ton_blockId> fetch(td::TlParser &p);

  explicit ton_blockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_BlockDescription: public Object {
 public:

  static object_ptr<tonNode_BlockDescription> fetch(td::TlParser &p);
};

class tonNode_blockDescriptionEmpty final : public tonNode_BlockDescription {
 public:

  tonNode_blockDescriptionEmpty();

  static const std::int32_t ID = -2088456555;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_BlockDescription> fetch(td::TlParser &p);

  explicit tonNode_blockDescriptionEmpty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_blockDescription final : public tonNode_BlockDescription {
 public:
  object_ptr<tonNode_blockIdExt> id_;

  tonNode_blockDescription();

  explicit tonNode_blockDescription(object_ptr<tonNode_blockIdExt> &&id_);

  static const std::int32_t ID = 1185009800;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_BlockDescription> fetch(td::TlParser &p);

  explicit tonNode_blockDescription(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_blockId final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t seqno_;

  tonNode_blockId();

  tonNode_blockId(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_);

  static const std::int32_t ID = -1211256473;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_blockId> fetch(td::TlParser &p);

  explicit tonNode_blockId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_blockIdExt final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t seqno_;
  td::Bits256 root_hash_;
  td::Bits256 file_hash_;

  tonNode_blockIdExt();

  tonNode_blockIdExt(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_);

  static const std::int32_t ID = 1733487480;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_blockIdExt> fetch(td::TlParser &p);

  explicit tonNode_blockIdExt(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_blockSignature final : public Object {
 public:
  td::Bits256 who_;
  td::BufferSlice signature_;

  tonNode_blockSignature();

  tonNode_blockSignature(td::Bits256 const &who_, td::BufferSlice &&signature_);

  static const std::int32_t ID = 1357921331;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_blockSignature> fetch(td::TlParser &p);

  explicit tonNode_blockSignature(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_Broadcast: public Object {
 public:

  static object_ptr<tonNode_Broadcast> fetch(td::TlParser &p);
};

class tonNode_blockBroadcast final : public tonNode_Broadcast {
 public:
  object_ptr<tonNode_blockIdExt> id_;
  std::int32_t catchain_seqno_;
  std::int32_t validator_set_hash_;
  std::vector<object_ptr<tonNode_blockSignature>> signatures_;
  td::BufferSlice proof_;
  td::BufferSlice data_;

  tonNode_blockBroadcast();

  tonNode_blockBroadcast(object_ptr<tonNode_blockIdExt> &&id_, std::int32_t catchain_seqno_, std::int32_t validator_set_hash_, std::vector<object_ptr<tonNode_blockSignature>> &&signatures_, td::BufferSlice &&proof_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1372712699;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Broadcast> fetch(td::TlParser &p);

  explicit tonNode_blockBroadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_ihrMessageBroadcast final : public tonNode_Broadcast {
 public:
  object_ptr<tonNode_ihrMessage> message_;

  tonNode_ihrMessageBroadcast();

  explicit tonNode_ihrMessageBroadcast(object_ptr<tonNode_ihrMessage> &&message_);

  static const std::int32_t ID = 1381868723;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Broadcast> fetch(td::TlParser &p);

  explicit tonNode_ihrMessageBroadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_externalMessageBroadcast final : public tonNode_Broadcast {
 public:
  object_ptr<tonNode_externalMessage> message_;

  tonNode_externalMessageBroadcast();

  explicit tonNode_externalMessageBroadcast(object_ptr<tonNode_externalMessage> &&message_);

  static const std::int32_t ID = 1025185895;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Broadcast> fetch(td::TlParser &p);

  explicit tonNode_externalMessageBroadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_newShardBlockBroadcast final : public tonNode_Broadcast {
 public:
  object_ptr<tonNode_newShardBlock> block_;

  tonNode_newShardBlockBroadcast();

  explicit tonNode_newShardBlockBroadcast(object_ptr<tonNode_newShardBlock> &&block_);

  static const std::int32_t ID = 183696060;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Broadcast> fetch(td::TlParser &p);

  explicit tonNode_newShardBlockBroadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_data final : public Object {
 public:
  td::BufferSlice data_;

  tonNode_data();

  explicit tonNode_data(td::BufferSlice &&data_);

  static const std::int32_t ID = 1443505284;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_data> fetch(td::TlParser &p);

  explicit tonNode_data(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_externalMessage final : public Object {
 public:
  td::BufferSlice data_;

  tonNode_externalMessage();

  explicit tonNode_externalMessage(td::BufferSlice &&data_);

  static const std::int32_t ID = -596270583;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_externalMessage> fetch(td::TlParser &p);

  explicit tonNode_externalMessage(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_ihrMessage final : public Object {
 public:
  td::BufferSlice data_;

  tonNode_ihrMessage();

  explicit tonNode_ihrMessage(td::BufferSlice &&data_);

  static const std::int32_t ID = 1161085703;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_ihrMessage> fetch(td::TlParser &p);

  explicit tonNode_ihrMessage(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_keyBlocks final : public Object {
 public:
  std::vector<object_ptr<tonNode_blockIdExt>> blocks_;
  bool incomplete_;
  bool error_;

  tonNode_keyBlocks();

  tonNode_keyBlocks(std::vector<object_ptr<tonNode_blockIdExt>> &&blocks_, bool incomplete_, bool error_);

  static const std::int32_t ID = 124144985;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_keyBlocks> fetch(td::TlParser &p);

  explicit tonNode_keyBlocks(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_newShardBlock final : public Object {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  std::int32_t cc_seqno_;
  td::BufferSlice data_;

  tonNode_newShardBlock();

  tonNode_newShardBlock(object_ptr<tonNode_blockIdExt> &&block_, std::int32_t cc_seqno_, td::BufferSlice &&data_);

  static const std::int32_t ID = -1533165015;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_newShardBlock> fetch(td::TlParser &p);

  explicit tonNode_newShardBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_Prepared: public Object {
 public:

  static object_ptr<tonNode_Prepared> fetch(td::TlParser &p);
};

class tonNode_prepared final : public tonNode_Prepared {
 public:

  tonNode_prepared();

  static const std::int32_t ID = -356205619;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Prepared> fetch(td::TlParser &p);

  explicit tonNode_prepared(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_notFound final : public tonNode_Prepared {
 public:

  tonNode_notFound();

  static const std::int32_t ID = -490521178;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_Prepared> fetch(td::TlParser &p);

  explicit tonNode_notFound(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_PreparedProof: public Object {
 public:

  static object_ptr<tonNode_PreparedProof> fetch(td::TlParser &p);
};

class tonNode_preparedProofEmpty final : public tonNode_PreparedProof {
 public:

  tonNode_preparedProofEmpty();

  static const std::int32_t ID = -949370502;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_PreparedProof> fetch(td::TlParser &p);

  explicit tonNode_preparedProofEmpty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_preparedProof final : public tonNode_PreparedProof {
 public:

  tonNode_preparedProof();

  static const std::int32_t ID = -1986028981;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_PreparedProof> fetch(td::TlParser &p);

  explicit tonNode_preparedProof(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_preparedProofLink final : public tonNode_PreparedProof {
 public:

  tonNode_preparedProofLink();

  static const std::int32_t ID = 1040134797;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_PreparedProof> fetch(td::TlParser &p);

  explicit tonNode_preparedProofLink(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_PreparedState: public Object {
 public:

  static object_ptr<tonNode_PreparedState> fetch(td::TlParser &p);
};

class tonNode_preparedState final : public tonNode_PreparedState {
 public:

  tonNode_preparedState();

  static const std::int32_t ID = 928762733;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_PreparedState> fetch(td::TlParser &p);

  explicit tonNode_preparedState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_notFoundState final : public tonNode_PreparedState {
 public:

  tonNode_notFoundState();

  static const std::int32_t ID = 842598993;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_PreparedState> fetch(td::TlParser &p);

  explicit tonNode_notFoundState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_sessionId final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  std::int32_t utime_from_;
  std::int32_t utime_to_;

  tonNode_sessionId();

  tonNode_sessionId(std::int32_t workchain_, std::int64_t shard_, std::int32_t utime_from_, std::int32_t utime_to_);

  static const std::int32_t ID = -880136334;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_sessionId> fetch(td::TlParser &p);

  explicit tonNode_sessionId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_shardPublicOverlayId final : public Object {
 public:
  std::int32_t workchain_;
  std::int64_t shard_;
  td::Bits256 zero_state_file_hash_;

  tonNode_shardPublicOverlayId();

  tonNode_shardPublicOverlayId(std::int32_t workchain_, std::int64_t shard_, td::Bits256 const &zero_state_file_hash_);

  static const std::int32_t ID = 1302254377;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_shardPublicOverlayId> fetch(td::TlParser &p);

  explicit tonNode_shardPublicOverlayId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class tonNode_zeroStateIdExt final : public Object {
 public:
  std::int32_t workchain_;
  td::Bits256 root_hash_;
  td::Bits256 file_hash_;

  tonNode_zeroStateIdExt();

  tonNode_zeroStateIdExt(std::int32_t workchain_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_);

  static const std::int32_t ID = 494024110;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tonNode_zeroStateIdExt> fetch(td::TlParser &p);

  explicit tonNode_zeroStateIdExt(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validator_config_global final : public Object {
 public:
  td::Bits256 zero_state_root_hash_;
  td::Bits256 zero_state_file_hash_;

  validator_config_global();

  validator_config_global(td::Bits256 const &zero_state_root_hash_, td::Bits256 const &zero_state_file_hash_);

  static const std::int32_t ID = -1525645549;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validator_config_global> fetch(td::TlParser &p);

  explicit validator_config_global(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validator_config_Local: public Object {
 public:

  static object_ptr<validator_config_Local> fetch(td::TlParser &p);
};

class validator_config_local final : public validator_config_Local {
 public:
  object_ptr<adnl_id_short> id_;

  validator_config_local();

  explicit validator_config_local(object_ptr<adnl_id_short> &&id_);

  static const std::int32_t ID = 1716256616;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validator_config_Local> fetch(td::TlParser &p);

  explicit validator_config_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validator_config_random_local final : public validator_config_Local {
 public:
  object_ptr<adnl_addressList> addr_list_;

  validator_config_random_local();

  explicit validator_config_random_local(object_ptr<adnl_addressList> &&addr_list_);

  static const std::int32_t ID = 1501795426;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validator_config_Local> fetch(td::TlParser &p);

  explicit validator_config_random_local(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_blockUpdate final : public Object {
 public:
  std::int64_t ts_;
  std::vector<object_ptr<validatorSession_round_Message>> actions_;
  std::int32_t state_;

  validatorSession_blockUpdate();

  validatorSession_blockUpdate(std::int64_t ts_, std::vector<object_ptr<validatorSession_round_Message>> &&actions_, std::int32_t state_);

  static const std::int32_t ID = -1836855753;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_blockUpdate> fetch(td::TlParser &p);

  explicit validatorSession_blockUpdate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_candidate final : public Object {
 public:
  td::Bits256 src_;
  std::int32_t round_;
  td::Bits256 root_hash_;
  td::BufferSlice data_;
  td::BufferSlice collated_data_;

  validatorSession_candidate();

  validatorSession_candidate(td::Bits256 const &src_, std::int32_t round_, td::Bits256 const &root_hash_, td::BufferSlice &&data_, td::BufferSlice &&collated_data_);

  static const std::int32_t ID = 2100525125;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_candidate> fetch(td::TlParser &p);

  explicit validatorSession_candidate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_candidateId final : public Object {
 public:
  td::Bits256 src_;
  td::Bits256 root_hash_;
  td::Bits256 file_hash_;
  td::Bits256 collated_data_file_hash_;

  validatorSession_candidateId();

  validatorSession_candidateId(td::Bits256 const &src_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_, td::Bits256 const &collated_data_file_hash_);

  static const std::int32_t ID = 436135276;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_candidateId> fetch(td::TlParser &p);

  explicit validatorSession_candidateId(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_id final : public Object {
 public:
  td::Bits256 slice_;
  std::int32_t start_time_;
  std::int32_t end_time_;
  std::vector<td::Bits256> participants_;

  validatorSession_id();

  validatorSession_id(td::Bits256 const &slice_, std::int32_t start_time_, std::int32_t end_time_, std::vector<td::Bits256> &&participants_);

  static const std::int32_t ID = -22534276;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_id> fetch(td::TlParser &p);

  explicit validatorSession_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_Message: public Object {
 public:

  static object_ptr<validatorSession_Message> fetch(td::TlParser &p);
};

class validatorSession_message_startSession final : public validatorSession_Message {
 public:

  validatorSession_message_startSession();

  static const std::int32_t ID = -1767807279;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_startSession(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_finishSession final : public validatorSession_Message {
 public:

  validatorSession_message_finishSession();

  static const std::int32_t ID = -879025437;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_finishSession(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_pong final : public Object {
 public:
  std::int64_t hash_;

  validatorSession_pong();

  explicit validatorSession_pong(std::int64_t hash_);

  static const std::int32_t ID = -590989459;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_pong> fetch(td::TlParser &p);

  explicit validatorSession_pong(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_round_id final : public Object {
 public:
  td::Bits256 session_;
  std::int64_t height_;
  td::Bits256 prev_block_;
  std::int32_t seqno_;

  validatorSession_round_id();

  validatorSession_round_id(td::Bits256 const &session_, std::int64_t height_, td::Bits256 const &prev_block_, std::int32_t seqno_);

  static const std::int32_t ID = 2477989;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_id> fetch(td::TlParser &p);

  explicit validatorSession_round_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_round_Message: public Object {
 public:

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);
};

class validatorSession_message_submittedBlock final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  td::Bits256 root_hash_;
  td::Bits256 file_hash_;
  td::Bits256 collated_data_file_hash_;

  validatorSession_message_submittedBlock();

  validatorSession_message_submittedBlock(std::int32_t round_, td::Bits256 const &root_hash_, td::Bits256 const &file_hash_, td::Bits256 const &collated_data_file_hash_);

  static const std::int32_t ID = 309732534;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_submittedBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_approvedBlock final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  td::Bits256 candidate_;

  validatorSession_message_approvedBlock();

  validatorSession_message_approvedBlock(std::int32_t round_, td::Bits256 const &candidate_);

  static const std::int32_t ID = 1571844585;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_approvedBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_rejectedBlock final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  td::Bits256 candidate_;
  td::BufferSlice reason_;

  validatorSession_message_rejectedBlock();

  validatorSession_message_rejectedBlock(std::int32_t round_, td::Bits256 const &candidate_, td::BufferSlice &&reason_);

  static const std::int32_t ID = -1786229141;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_rejectedBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_commit final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  td::Bits256 candidate_;
  td::BufferSlice signature_;

  validatorSession_message_commit();

  validatorSession_message_commit(std::int32_t round_, td::Bits256 const &candidate_, td::BufferSlice &&signature_);

  static const std::int32_t ID = -1408065803;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_commit(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_vote final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  std::int32_t attempt_;
  td::Bits256 candidate_;

  validatorSession_message_vote();

  validatorSession_message_vote(std::int32_t round_, std::int32_t attempt_, td::Bits256 const &candidate_);

  static const std::int32_t ID = -1707978297;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_vote(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_precommit final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  std::int32_t attempt_;
  td::Bits256 candidate_;

  validatorSession_message_precommit();

  validatorSession_message_precommit(std::int32_t round_, std::int32_t attempt_, td::Bits256 const &candidate_);

  static const std::int32_t ID = -1470843566;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_precommit(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_message_empty final : public validatorSession_round_Message {
 public:
  std::int32_t round_;
  std::int32_t attempt_;

  validatorSession_message_empty();

  validatorSession_message_empty(std::int32_t round_, std::int32_t attempt_);

  static const std::int32_t ID = 1243619241;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_round_Message> fetch(td::TlParser &p);

  explicit validatorSession_message_empty(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class validatorSession_candidate_id final : public Object {
 public:
  td::Bits256 round_;
  td::Bits256 block_hash_;

  validatorSession_candidate_id();

  validatorSession_candidate_id(td::Bits256 const &round_, td::Bits256 const &block_hash_);

  static const std::int32_t ID = -1126743751;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<validatorSession_candidate_id> fetch(td::TlParser &p);

  explicit validatorSession_candidate_id(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;
};

class catchain_getBlock final : public Function {
 public:
  td::Bits256 block_;

  catchain_getBlock();

  explicit catchain_getBlock(td::Bits256 const &block_);

  static const std::int32_t ID = 155049336;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<catchain_BlockResult>;

  static object_ptr<catchain_getBlock> fetch(td::TlParser &p);

  explicit catchain_getBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class catchain_getBlockHistory final : public Function {
 public:
  td::Bits256 block_;
  std::int64_t height_;
  std::vector<td::Bits256> stop_if_;

  catchain_getBlockHistory();

  catchain_getBlockHistory(td::Bits256 const &block_, std::int64_t height_, std::vector<td::Bits256> &&stop_if_);

  static const std::int32_t ID = -1470730762;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<catchain_sent>;

  static object_ptr<catchain_getBlockHistory> fetch(td::TlParser &p);

  explicit catchain_getBlockHistory(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class catchain_getBlocks final : public Function {
 public:
  std::vector<td::Bits256> blocks_;

  catchain_getBlocks();

  explicit catchain_getBlocks(std::vector<td::Bits256> &&blocks_);

  static const std::int32_t ID = 53062594;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<catchain_sent>;

  static object_ptr<catchain_getBlocks> fetch(td::TlParser &p);

  explicit catchain_getBlocks(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class catchain_getDifference final : public Function {
 public:
  std::vector<std::int32_t> rt_;

  catchain_getDifference();

  explicit catchain_getDifference(std::vector<std::int32_t> &&rt_);

  static const std::int32_t ID = -798175528;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<catchain_Difference>;

  static object_ptr<catchain_getDifference> fetch(td::TlParser &p);

  explicit catchain_getDifference(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_findNode final : public Function {
 public:
  td::Bits256 key_;
  std::int32_t k_;

  dht_findNode();

  dht_findNode(td::Bits256 const &key_, std::int32_t k_);

  static const std::int32_t ID = 1826803307;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<dht_nodes>;

  static object_ptr<dht_findNode> fetch(td::TlParser &p);

  explicit dht_findNode(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_findValue final : public Function {
 public:
  td::Bits256 key_;
  std::int32_t k_;

  dht_findValue();

  dht_findValue(td::Bits256 const &key_, std::int32_t k_);

  static const std::int32_t ID = -1370791919;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<dht_ValueResult>;

  static object_ptr<dht_findValue> fetch(td::TlParser &p);

  explicit dht_findValue(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_getSignedAddressList final : public Function {
 public:

  dht_getSignedAddressList();

  static const std::int32_t ID = 960283782;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<adnl_node>;

  static object_ptr<dht_getSignedAddressList> fetch(td::TlParser &p);

  explicit dht_getSignedAddressList(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_ping final : public Function {
 public:
  std::int64_t random_id_;

  dht_ping();

  explicit dht_ping(std::int64_t random_id_);

  static const std::int32_t ID = -873775336;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<dht_pong>;

  static object_ptr<dht_ping> fetch(td::TlParser &p);

  explicit dht_ping(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_query final : public Function {
 public:
  object_ptr<dht_node> node_;

  dht_query();

  explicit dht_query(object_ptr<dht_node> &&node_);

  static const std::int32_t ID = 2102593385;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = bool;

  static object_ptr<dht_query> fetch(td::TlParser &p);

  explicit dht_query(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class dht_store final : public Function {
 public:
  object_ptr<dht_value> value_;

  dht_store();

  explicit dht_store(object_ptr<dht_value> &&value_);

  static const std::int32_t ID = 882065938;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<dht_stored>;

  static object_ptr<dht_store> fetch(td::TlParser &p);

  explicit dht_store(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class getTestObject final : public Function {
 public:

  getTestObject();

  static const std::int32_t ID = 197109379;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<TestObject>;

  static object_ptr<getTestObject> fetch(td::TlParser &p);

  explicit getTestObject(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class overlay_getBroadcast final : public Function {
 public:
  td::Bits256 hash_;

  overlay_getBroadcast();

  explicit overlay_getBroadcast(td::Bits256 const &hash_);

  static const std::int32_t ID = 758510240;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<overlay_Broadcast>;

  static object_ptr<overlay_getBroadcast> fetch(td::TlParser &p);

  explicit overlay_getBroadcast(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class overlay_getBroadcastList final : public Function {
 public:
  object_ptr<overlay_broadcastList> list_;

  overlay_getBroadcastList();

  explicit overlay_getBroadcastList(object_ptr<overlay_broadcastList> &&list_);

  static const std::int32_t ID = 1109141562;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<overlay_broadcastList>;

  static object_ptr<overlay_getBroadcastList> fetch(td::TlParser &p);

  explicit overlay_getBroadcastList(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class overlay_getRandomPeers final : public Function {
 public:
  object_ptr<overlay_nodes> peers_;

  overlay_getRandomPeers();

  explicit overlay_getRandomPeers(object_ptr<overlay_nodes> &&peers_);

  static const std::int32_t ID = 1223582891;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<overlay_nodes>;

  static object_ptr<overlay_getRandomPeers> fetch(td::TlParser &p);

  explicit overlay_getRandomPeers(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class overlay_query final : public Function {
 public:
  td::Bits256 overlay_;

  overlay_query();

  explicit overlay_query(td::Bits256 const &overlay_);

  static const std::int32_t ID = -855800765;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = bool;

  static object_ptr<overlay_query> fetch(td::TlParser &p);

  explicit overlay_query(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tcp_ping final : public Function {
 public:
  std::int64_t random_id_;

  tcp_ping();

  explicit tcp_ping(std::int64_t random_id_);

  static const std::int32_t ID = 1292381082;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tcp_pong>;

  static object_ptr<tcp_ping> fetch(td::TlParser &p);

  explicit tcp_ping(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_downloadBlock final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_downloadBlock();

  explicit tonNode_downloadBlock(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = -495814205;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_data>;

  static object_ptr<tonNode_downloadBlock> fetch(td::TlParser &p);

  explicit tonNode_downloadBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_downloadBlockProof final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_downloadBlockProof();

  explicit tonNode_downloadBlockProof(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 1272334218;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_data>;

  static object_ptr<tonNode_downloadBlockProof> fetch(td::TlParser &p);

  explicit tonNode_downloadBlockProof(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_downloadBlockProofLink final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_downloadBlockProofLink();

  explicit tonNode_downloadBlockProofLink(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 632488134;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_data>;

  static object_ptr<tonNode_downloadBlockProofLink> fetch(td::TlParser &p);

  explicit tonNode_downloadBlockProofLink(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_downloadPersistentState final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  object_ptr<tonNode_blockIdExt> masterchain_block_;

  tonNode_downloadPersistentState();

  tonNode_downloadPersistentState(object_ptr<tonNode_blockIdExt> &&block_, object_ptr<tonNode_blockIdExt> &&masterchain_block_);

  static const std::int32_t ID = 2140791736;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_data>;

  static object_ptr<tonNode_downloadPersistentState> fetch(td::TlParser &p);

  explicit tonNode_downloadPersistentState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_downloadZeroState final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_downloadZeroState();

  explicit tonNode_downloadZeroState(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = -1379131814;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_data>;

  static object_ptr<tonNode_downloadZeroState> fetch(td::TlParser &p);

  explicit tonNode_downloadZeroState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_getNextBlockDescription final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> prev_block_;

  tonNode_getNextBlockDescription();

  explicit tonNode_getNextBlockDescription(object_ptr<tonNode_blockIdExt> &&prev_block_);

  static const std::int32_t ID = 341160179;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_BlockDescription>;

  static object_ptr<tonNode_getNextBlockDescription> fetch(td::TlParser &p);

  explicit tonNode_getNextBlockDescription(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_getNextKeyBlockIds final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  std::int32_t max_size_;

  tonNode_getNextKeyBlockIds();

  tonNode_getNextKeyBlockIds(object_ptr<tonNode_blockIdExt> &&block_, std::int32_t max_size_);

  static const std::int32_t ID = -219689029;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_keyBlocks>;

  static object_ptr<tonNode_getNextKeyBlockIds> fetch(td::TlParser &p);

  explicit tonNode_getNextKeyBlockIds(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_prepareBlock final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_prepareBlock();

  explicit tonNode_prepareBlock(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 1973649230;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_Prepared>;

  static object_ptr<tonNode_prepareBlock> fetch(td::TlParser &p);

  explicit tonNode_prepareBlock(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_prepareBlockProof final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  bool allow_partial_;

  tonNode_prepareBlockProof();

  tonNode_prepareBlockProof(object_ptr<tonNode_blockIdExt> &&block_, bool allow_partial_);

  static const std::int32_t ID = -2024000760;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_PreparedProof>;

  static object_ptr<tonNode_prepareBlockProof> fetch(td::TlParser &p);

  explicit tonNode_prepareBlockProof(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_preparePersistentState final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;
  object_ptr<tonNode_blockIdExt> masterchain_block_;

  tonNode_preparePersistentState();

  tonNode_preparePersistentState(object_ptr<tonNode_blockIdExt> &&block_, object_ptr<tonNode_blockIdExt> &&masterchain_block_);

  static const std::int32_t ID = -18209122;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_PreparedState>;

  static object_ptr<tonNode_preparePersistentState> fetch(td::TlParser &p);

  explicit tonNode_preparePersistentState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class tonNode_prepareZeroState final : public Function {
 public:
  object_ptr<tonNode_blockIdExt> block_;

  tonNode_prepareZeroState();

  explicit tonNode_prepareZeroState(object_ptr<tonNode_blockIdExt> &&block_);

  static const std::int32_t ID = 1104021541;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tonNode_PreparedState>;

  static object_ptr<tonNode_prepareZeroState> fetch(td::TlParser &p);

  explicit tonNode_prepareZeroState(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class validatorSession_downloadCandidate final : public Function {
 public:
  std::int32_t round_;
  object_ptr<validatorSession_candidateId> id_;

  validatorSession_downloadCandidate();

  validatorSession_downloadCandidate(std::int32_t round_, object_ptr<validatorSession_candidateId> &&id_);

  static const std::int32_t ID = -520274443;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<validatorSession_candidate>;

  static object_ptr<validatorSession_downloadCandidate> fetch(td::TlParser &p);

  explicit validatorSession_downloadCandidate(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

class validatorSession_ping final : public Function {
 public:
  std::int64_t hash_;

  validatorSession_ping();

  explicit validatorSession_ping(std::int64_t hash_);

  static const std::int32_t ID = 1745111469;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<validatorSession_pong>;

  static object_ptr<validatorSession_ping> fetch(td::TlParser &p);

  explicit validatorSession_ping(td::TlParser &p);

  void store(td::TlStorerCalcLength &s) const final;

  void store(td::TlStorerUnsafe &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(td::TlParser &p);
};

}  // namespace ton_api
}  // namespace ton
