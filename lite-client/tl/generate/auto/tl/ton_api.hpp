#pragma once

#include "ton_api.h"

namespace ton {
namespace ton_api {

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(Object &obj, const T &func) {
  switch (obj.get_id()) {
    case hashable_bool::ID:
      func(static_cast<hashable_bool &>(obj));
      return true;
    case hashable_int32::ID:
      func(static_cast<hashable_int32 &>(obj));
      return true;
    case hashable_int64::ID:
      func(static_cast<hashable_int64 &>(obj));
      return true;
    case hashable_int256::ID:
      func(static_cast<hashable_int256 &>(obj));
      return true;
    case hashable_bytes::ID:
      func(static_cast<hashable_bytes &>(obj));
      return true;
    case hashable_pair::ID:
      func(static_cast<hashable_pair &>(obj));
      return true;
    case hashable_vector::ID:
      func(static_cast<hashable_vector &>(obj));
      return true;
    case hashable_validatorSessionOldRound::ID:
      func(static_cast<hashable_validatorSessionOldRound &>(obj));
      return true;
    case hashable_validatorSessionRoundAttempt::ID:
      func(static_cast<hashable_validatorSessionRoundAttempt &>(obj));
      return true;
    case hashable_validatorSessionRound::ID:
      func(static_cast<hashable_validatorSessionRound &>(obj));
      return true;
    case hashable_blockSignature::ID:
      func(static_cast<hashable_blockSignature &>(obj));
      return true;
    case hashable_sentBlock::ID:
      func(static_cast<hashable_sentBlock &>(obj));
      return true;
    case hashable_sentBlockEmpty::ID:
      func(static_cast<hashable_sentBlockEmpty &>(obj));
      return true;
    case hashable_vote::ID:
      func(static_cast<hashable_vote &>(obj));
      return true;
    case hashable_blockCandidate::ID:
      func(static_cast<hashable_blockCandidate &>(obj));
      return true;
    case hashable_blockCandidateAttempt::ID:
      func(static_cast<hashable_blockCandidateAttempt &>(obj));
      return true;
    case hashable_cntVector::ID:
      func(static_cast<hashable_cntVector &>(obj));
      return true;
    case hashable_cntSortedVector::ID:
      func(static_cast<hashable_cntSortedVector &>(obj));
      return true;
    case hashable_validatorSession::ID:
      func(static_cast<hashable_validatorSession &>(obj));
      return true;
    case pk_unenc::ID:
      func(static_cast<pk_unenc &>(obj));
      return true;
    case pk_ed25519::ID:
      func(static_cast<pk_ed25519 &>(obj));
      return true;
    case pk_aes::ID:
      func(static_cast<pk_aes &>(obj));
      return true;
    case pk_overlay::ID:
      func(static_cast<pk_overlay &>(obj));
      return true;
    case pub_unenc::ID:
      func(static_cast<pub_unenc &>(obj));
      return true;
    case pub_ed25519::ID:
      func(static_cast<pub_ed25519 &>(obj));
      return true;
    case pub_aes::ID:
      func(static_cast<pub_aes &>(obj));
      return true;
    case pub_overlay::ID:
      func(static_cast<pub_overlay &>(obj));
      return true;
    case testObject::ID:
      func(static_cast<testObject &>(obj));
      return true;
    case testString::ID:
      func(static_cast<testString &>(obj));
      return true;
    case testInt::ID:
      func(static_cast<testInt &>(obj));
      return true;
    case testVectorBytes::ID:
      func(static_cast<testVectorBytes &>(obj));
      return true;
    case adnl_address_udp::ID:
      func(static_cast<adnl_address_udp &>(obj));
      return true;
    case adnl_address_udp6::ID:
      func(static_cast<adnl_address_udp6 &>(obj));
      return true;
    case adnl_addressList::ID:
      func(static_cast<adnl_addressList &>(obj));
      return true;
    case adnl_message_createChannel::ID:
      func(static_cast<adnl_message_createChannel &>(obj));
      return true;
    case adnl_message_confirmChannel::ID:
      func(static_cast<adnl_message_confirmChannel &>(obj));
      return true;
    case adnl_message_custom::ID:
      func(static_cast<adnl_message_custom &>(obj));
      return true;
    case adnl_message_nop::ID:
      func(static_cast<adnl_message_nop &>(obj));
      return true;
    case adnl_message_reinit::ID:
      func(static_cast<adnl_message_reinit &>(obj));
      return true;
    case adnl_message_query::ID:
      func(static_cast<adnl_message_query &>(obj));
      return true;
    case adnl_message_answer::ID:
      func(static_cast<adnl_message_answer &>(obj));
      return true;
    case adnl_message_part::ID:
      func(static_cast<adnl_message_part &>(obj));
      return true;
    case adnl_node::ID:
      func(static_cast<adnl_node &>(obj));
      return true;
    case adnl_nodes::ID:
      func(static_cast<adnl_nodes &>(obj));
      return true;
    case adnl_packetContents::ID:
      func(static_cast<adnl_packetContents &>(obj));
      return true;
    case adnl_config_global::ID:
      func(static_cast<adnl_config_global &>(obj));
      return true;
    case adnl_db_node_key::ID:
      func(static_cast<adnl_db_node_key &>(obj));
      return true;
    case adnl_db_node_value::ID:
      func(static_cast<adnl_db_node_value &>(obj));
      return true;
    case adnl_id_short::ID:
      func(static_cast<adnl_id_short &>(obj));
      return true;
    case catchain_block::ID:
      func(static_cast<catchain_block &>(obj));
      return true;
    case catchain_blockNotFound::ID:
      func(static_cast<catchain_blockNotFound &>(obj));
      return true;
    case catchain_blockResult::ID:
      func(static_cast<catchain_blockResult &>(obj));
      return true;
    case catchain_blocks::ID:
      func(static_cast<catchain_blocks &>(obj));
      return true;
    case catchain_difference::ID:
      func(static_cast<catchain_difference &>(obj));
      return true;
    case catchain_differenceFork::ID:
      func(static_cast<catchain_differenceFork &>(obj));
      return true;
    case catchain_firstblock::ID:
      func(static_cast<catchain_firstblock &>(obj));
      return true;
    case catchain_sent::ID:
      func(static_cast<catchain_sent &>(obj));
      return true;
    case catchain_blockUpdate::ID:
      func(static_cast<catchain_blockUpdate &>(obj));
      return true;
    case catchain_block_data::ID:
      func(static_cast<catchain_block_data &>(obj));
      return true;
    case catchain_block_dep::ID:
      func(static_cast<catchain_block_dep &>(obj));
      return true;
    case catchain_block_id::ID:
      func(static_cast<catchain_block_id &>(obj));
      return true;
    case catchain_block_data_badBlock::ID:
      func(static_cast<catchain_block_data_badBlock &>(obj));
      return true;
    case catchain_block_data_fork::ID:
      func(static_cast<catchain_block_data_fork &>(obj));
      return true;
    case catchain_block_data_nop::ID:
      func(static_cast<catchain_block_data_nop &>(obj));
      return true;
    case catchain_block_data_vector::ID:
      func(static_cast<catchain_block_data_vector &>(obj));
      return true;
    case catchain_config_global::ID:
      func(static_cast<catchain_config_global &>(obj));
      return true;
    case catchain_config_local::ID:
      func(static_cast<catchain_config_local &>(obj));
      return true;
    case config_global::ID:
      func(static_cast<config_global &>(obj));
      return true;
    case config_local::ID:
      func(static_cast<config_local &>(obj));
      return true;
    case db_candidate::ID:
      func(static_cast<db_candidate &>(obj));
      return true;
    case db_block_info::ID:
      func(static_cast<db_block_info &>(obj));
      return true;
    case db_block_archivedInfo::ID:
      func(static_cast<db_block_archivedInfo &>(obj));
      return true;
    case db_blockdb_key_lru::ID:
      func(static_cast<db_blockdb_key_lru &>(obj));
      return true;
    case db_blockdb_key_value::ID:
      func(static_cast<db_blockdb_key_value &>(obj));
      return true;
    case db_blockdb_lru::ID:
      func(static_cast<db_blockdb_lru &>(obj));
      return true;
    case db_blockdb_value::ID:
      func(static_cast<db_blockdb_value &>(obj));
      return true;
    case db_candidate_id::ID:
      func(static_cast<db_candidate_id &>(obj));
      return true;
    case db_celldb_value::ID:
      func(static_cast<db_celldb_value &>(obj));
      return true;
    case db_celldb_key_value::ID:
      func(static_cast<db_celldb_key_value &>(obj));
      return true;
    case db_filedb_key_empty::ID:
      func(static_cast<db_filedb_key_empty &>(obj));
      return true;
    case db_filedb_key_blockFile::ID:
      func(static_cast<db_filedb_key_blockFile &>(obj));
      return true;
    case db_filedb_key_zeroStateFile::ID:
      func(static_cast<db_filedb_key_zeroStateFile &>(obj));
      return true;
    case db_filedb_key_persistentStateFile::ID:
      func(static_cast<db_filedb_key_persistentStateFile &>(obj));
      return true;
    case db_filedb_key_proof::ID:
      func(static_cast<db_filedb_key_proof &>(obj));
      return true;
    case db_filedb_key_proofLink::ID:
      func(static_cast<db_filedb_key_proofLink &>(obj));
      return true;
    case db_filedb_key_signatures::ID:
      func(static_cast<db_filedb_key_signatures &>(obj));
      return true;
    case db_filedb_key_candidate::ID:
      func(static_cast<db_filedb_key_candidate &>(obj));
      return true;
    case db_filedb_value::ID:
      func(static_cast<db_filedb_value &>(obj));
      return true;
    case db_lt_el_key::ID:
      func(static_cast<db_lt_el_key &>(obj));
      return true;
    case db_lt_desc_key::ID:
      func(static_cast<db_lt_desc_key &>(obj));
      return true;
    case db_lt_shard_key::ID:
      func(static_cast<db_lt_shard_key &>(obj));
      return true;
    case db_lt_status_key::ID:
      func(static_cast<db_lt_status_key &>(obj));
      return true;
    case db_lt_desc_value::ID:
      func(static_cast<db_lt_desc_value &>(obj));
      return true;
    case db_lt_el_value::ID:
      func(static_cast<db_lt_el_value &>(obj));
      return true;
    case db_lt_shard_value::ID:
      func(static_cast<db_lt_shard_value &>(obj));
      return true;
    case db_lt_status_value::ID:
      func(static_cast<db_lt_status_value &>(obj));
      return true;
    case db_root_config::ID:
      func(static_cast<db_root_config &>(obj));
      return true;
    case db_root_dbDescription::ID:
      func(static_cast<db_root_dbDescription &>(obj));
      return true;
    case db_root_key_cellDb::ID:
      func(static_cast<db_root_key_cellDb &>(obj));
      return true;
    case db_root_key_blockDb::ID:
      func(static_cast<db_root_key_blockDb &>(obj));
      return true;
    case db_root_key_config::ID:
      func(static_cast<db_root_key_config &>(obj));
      return true;
    case db_state_asyncSerializer::ID:
      func(static_cast<db_state_asyncSerializer &>(obj));
      return true;
    case db_state_destroyedSessions::ID:
      func(static_cast<db_state_destroyedSessions &>(obj));
      return true;
    case db_state_gcBlockId::ID:
      func(static_cast<db_state_gcBlockId &>(obj));
      return true;
    case db_state_initBlockId::ID:
      func(static_cast<db_state_initBlockId &>(obj));
      return true;
    case db_state_key_destroyedSessions::ID:
      func(static_cast<db_state_key_destroyedSessions &>(obj));
      return true;
    case db_state_key_initBlockId::ID:
      func(static_cast<db_state_key_initBlockId &>(obj));
      return true;
    case db_state_key_gcBlockId::ID:
      func(static_cast<db_state_key_gcBlockId &>(obj));
      return true;
    case db_state_key_shardClient::ID:
      func(static_cast<db_state_key_shardClient &>(obj));
      return true;
    case db_state_key_asyncSerializer::ID:
      func(static_cast<db_state_key_asyncSerializer &>(obj));
      return true;
    case db_state_shardClient::ID:
      func(static_cast<db_state_shardClient &>(obj));
      return true;
    case dht_key::ID:
      func(static_cast<dht_key &>(obj));
      return true;
    case dht_keyDescription::ID:
      func(static_cast<dht_keyDescription &>(obj));
      return true;
    case dht_message::ID:
      func(static_cast<dht_message &>(obj));
      return true;
    case dht_node::ID:
      func(static_cast<dht_node &>(obj));
      return true;
    case dht_nodes::ID:
      func(static_cast<dht_nodes &>(obj));
      return true;
    case dht_pong::ID:
      func(static_cast<dht_pong &>(obj));
      return true;
    case dht_stored::ID:
      func(static_cast<dht_stored &>(obj));
      return true;
    case dht_updateRule_signature::ID:
      func(static_cast<dht_updateRule_signature &>(obj));
      return true;
    case dht_updateRule_anybody::ID:
      func(static_cast<dht_updateRule_anybody &>(obj));
      return true;
    case dht_updateRule_overlayNodes::ID:
      func(static_cast<dht_updateRule_overlayNodes &>(obj));
      return true;
    case dht_value::ID:
      func(static_cast<dht_value &>(obj));
      return true;
    case dht_valueNotFound::ID:
      func(static_cast<dht_valueNotFound &>(obj));
      return true;
    case dht_valueFound::ID:
      func(static_cast<dht_valueFound &>(obj));
      return true;
    case dht_config_global::ID:
      func(static_cast<dht_config_global &>(obj));
      return true;
    case dht_config_local::ID:
      func(static_cast<dht_config_local &>(obj));
      return true;
    case dht_config_random_local::ID:
      func(static_cast<dht_config_random_local &>(obj));
      return true;
    case dht_db_bucket::ID:
      func(static_cast<dht_db_bucket &>(obj));
      return true;
    case dht_db_key_bucket::ID:
      func(static_cast<dht_db_key_bucket &>(obj));
      return true;
    case dummyworkchain0_config_global::ID:
      func(static_cast<dummyworkchain0_config_global &>(obj));
      return true;
    case dummyworkchain0_config_local::ID:
      func(static_cast<dummyworkchain0_config_local &>(obj));
      return true;
    case fec_raptorQ::ID:
      func(static_cast<fec_raptorQ &>(obj));
      return true;
    case fec_roundRobin::ID:
      func(static_cast<fec_roundRobin &>(obj));
      return true;
    case fec_online::ID:
      func(static_cast<fec_online &>(obj));
      return true;
    case id_config_local::ID:
      func(static_cast<id_config_local &>(obj));
      return true;
    case liteclient_config_global::ID:
      func(static_cast<liteclient_config_global &>(obj));
      return true;
    case liteserver_config_local::ID:
      func(static_cast<liteserver_config_local &>(obj));
      return true;
    case overlay_fec_received::ID:
      func(static_cast<overlay_fec_received &>(obj));
      return true;
    case overlay_fec_completed::ID:
      func(static_cast<overlay_fec_completed &>(obj));
      return true;
    case overlay_unicast::ID:
      func(static_cast<overlay_unicast &>(obj));
      return true;
    case overlay_broadcast::ID:
      func(static_cast<overlay_broadcast &>(obj));
      return true;
    case overlay_broadcastFec::ID:
      func(static_cast<overlay_broadcastFec &>(obj));
      return true;
    case overlay_broadcastFecShort::ID:
      func(static_cast<overlay_broadcastFecShort &>(obj));
      return true;
    case overlay_broadcastNotFound::ID:
      func(static_cast<overlay_broadcastNotFound &>(obj));
      return true;
    case overlay_broadcastList::ID:
      func(static_cast<overlay_broadcastList &>(obj));
      return true;
    case overlay_certificate::ID:
      func(static_cast<overlay_certificate &>(obj));
      return true;
    case overlay_emptyCertificate::ID:
      func(static_cast<overlay_emptyCertificate &>(obj));
      return true;
    case overlay_certificateId::ID:
      func(static_cast<overlay_certificateId &>(obj));
      return true;
    case overlay_message::ID:
      func(static_cast<overlay_message &>(obj));
      return true;
    case overlay_node::ID:
      func(static_cast<overlay_node &>(obj));
      return true;
    case overlay_nodes::ID:
      func(static_cast<overlay_nodes &>(obj));
      return true;
    case overlay_broadcast_id::ID:
      func(static_cast<overlay_broadcast_id &>(obj));
      return true;
    case overlay_broadcast_toSign::ID:
      func(static_cast<overlay_broadcast_toSign &>(obj));
      return true;
    case overlay_broadcastFec_id::ID:
      func(static_cast<overlay_broadcastFec_id &>(obj));
      return true;
    case overlay_broadcastFec_partId::ID:
      func(static_cast<overlay_broadcastFec_partId &>(obj));
      return true;
    case overlay_config_local::ID:
      func(static_cast<overlay_config_local &>(obj));
      return true;
    case overlay_config_random_local::ID:
      func(static_cast<overlay_config_random_local &>(obj));
      return true;
    case overlay_db_key_nodes::ID:
      func(static_cast<overlay_db_key_nodes &>(obj));
      return true;
    case overlay_db_nodes::ID:
      func(static_cast<overlay_db_nodes &>(obj));
      return true;
    case overlay_node_toSign::ID:
      func(static_cast<overlay_node_toSign &>(obj));
      return true;
    case rldp_message::ID:
      func(static_cast<rldp_message &>(obj));
      return true;
    case rldp_query::ID:
      func(static_cast<rldp_query &>(obj));
      return true;
    case rldp_answer::ID:
      func(static_cast<rldp_answer &>(obj));
      return true;
    case rldp_messagePart::ID:
      func(static_cast<rldp_messagePart &>(obj));
      return true;
    case rldp_confirm::ID:
      func(static_cast<rldp_confirm &>(obj));
      return true;
    case rldp_complete::ID:
      func(static_cast<rldp_complete &>(obj));
      return true;
    case tcp_pong::ID:
      func(static_cast<tcp_pong &>(obj));
      return true;
    case test0_proof::ID:
      func(static_cast<test0_proof &>(obj));
      return true;
    case test0_proofLink::ID:
      func(static_cast<test0_proofLink &>(obj));
      return true;
    case test0_shardchain_block::ID:
      func(static_cast<test0_shardchain_block &>(obj));
      return true;
    case test0_shardchain_state::ID:
      func(static_cast<test0_shardchain_state &>(obj));
      return true;
    case test_validatorSession_block::ID:
      func(static_cast<test_validatorSession_block &>(obj));
      return true;
    case test0_blockSignatures::ID:
      func(static_cast<test0_blockSignatures &>(obj));
      return true;
    case test0_extMessage::ID:
      func(static_cast<test0_extMessage &>(obj));
      return true;
    case test0_masterchainBlockExtra_empty::ID:
      func(static_cast<test0_masterchainBlockExtra_empty &>(obj));
      return true;
    case test0_masterchainBlockExtra_extra::ID:
      func(static_cast<test0_masterchainBlockExtra_extra &>(obj));
      return true;
    case test0_masterchainStateExtra_empty::ID:
      func(static_cast<test0_masterchainStateExtra_empty &>(obj));
      return true;
    case test0_masterchainStateExtra_extra::ID:
      func(static_cast<test0_masterchainStateExtra_extra &>(obj));
      return true;
    case test0_topShardBlockDescription::ID:
      func(static_cast<test0_topShardBlockDescription &>(obj));
      return true;
    case test0_validatorSessionId::ID:
      func(static_cast<test0_validatorSessionId &>(obj));
      return true;
    case test0_validatorSet::ID:
      func(static_cast<test0_validatorSet &>(obj));
      return true;
    case test0_validatorSetItem::ID:
      func(static_cast<test0_validatorSetItem &>(obj));
      return true;
    case test0_masterchain_shardInfo::ID:
      func(static_cast<test0_masterchain_shardInfo &>(obj));
      return true;
    case ton_blockId::ID:
      func(static_cast<ton_blockId &>(obj));
      return true;
    case tonNode_blockDescriptionEmpty::ID:
      func(static_cast<tonNode_blockDescriptionEmpty &>(obj));
      return true;
    case tonNode_blockDescription::ID:
      func(static_cast<tonNode_blockDescription &>(obj));
      return true;
    case tonNode_blockId::ID:
      func(static_cast<tonNode_blockId &>(obj));
      return true;
    case tonNode_blockIdExt::ID:
      func(static_cast<tonNode_blockIdExt &>(obj));
      return true;
    case tonNode_blockSignature::ID:
      func(static_cast<tonNode_blockSignature &>(obj));
      return true;
    case tonNode_blockBroadcast::ID:
      func(static_cast<tonNode_blockBroadcast &>(obj));
      return true;
    case tonNode_ihrMessageBroadcast::ID:
      func(static_cast<tonNode_ihrMessageBroadcast &>(obj));
      return true;
    case tonNode_externalMessageBroadcast::ID:
      func(static_cast<tonNode_externalMessageBroadcast &>(obj));
      return true;
    case tonNode_newShardBlockBroadcast::ID:
      func(static_cast<tonNode_newShardBlockBroadcast &>(obj));
      return true;
    case tonNode_data::ID:
      func(static_cast<tonNode_data &>(obj));
      return true;
    case tonNode_externalMessage::ID:
      func(static_cast<tonNode_externalMessage &>(obj));
      return true;
    case tonNode_ihrMessage::ID:
      func(static_cast<tonNode_ihrMessage &>(obj));
      return true;
    case tonNode_keyBlocks::ID:
      func(static_cast<tonNode_keyBlocks &>(obj));
      return true;
    case tonNode_newShardBlock::ID:
      func(static_cast<tonNode_newShardBlock &>(obj));
      return true;
    case tonNode_prepared::ID:
      func(static_cast<tonNode_prepared &>(obj));
      return true;
    case tonNode_notFound::ID:
      func(static_cast<tonNode_notFound &>(obj));
      return true;
    case tonNode_preparedProofEmpty::ID:
      func(static_cast<tonNode_preparedProofEmpty &>(obj));
      return true;
    case tonNode_preparedProof::ID:
      func(static_cast<tonNode_preparedProof &>(obj));
      return true;
    case tonNode_preparedProofLink::ID:
      func(static_cast<tonNode_preparedProofLink &>(obj));
      return true;
    case tonNode_preparedState::ID:
      func(static_cast<tonNode_preparedState &>(obj));
      return true;
    case tonNode_notFoundState::ID:
      func(static_cast<tonNode_notFoundState &>(obj));
      return true;
    case tonNode_sessionId::ID:
      func(static_cast<tonNode_sessionId &>(obj));
      return true;
    case tonNode_shardPublicOverlayId::ID:
      func(static_cast<tonNode_shardPublicOverlayId &>(obj));
      return true;
    case tonNode_zeroStateIdExt::ID:
      func(static_cast<tonNode_zeroStateIdExt &>(obj));
      return true;
    case validator_config_global::ID:
      func(static_cast<validator_config_global &>(obj));
      return true;
    case validator_config_local::ID:
      func(static_cast<validator_config_local &>(obj));
      return true;
    case validator_config_random_local::ID:
      func(static_cast<validator_config_random_local &>(obj));
      return true;
    case validatorSession_blockUpdate::ID:
      func(static_cast<validatorSession_blockUpdate &>(obj));
      return true;
    case validatorSession_candidate::ID:
      func(static_cast<validatorSession_candidate &>(obj));
      return true;
    case validatorSession_candidateId::ID:
      func(static_cast<validatorSession_candidateId &>(obj));
      return true;
    case validatorSession_id::ID:
      func(static_cast<validatorSession_id &>(obj));
      return true;
    case validatorSession_message_startSession::ID:
      func(static_cast<validatorSession_message_startSession &>(obj));
      return true;
    case validatorSession_message_finishSession::ID:
      func(static_cast<validatorSession_message_finishSession &>(obj));
      return true;
    case validatorSession_pong::ID:
      func(static_cast<validatorSession_pong &>(obj));
      return true;
    case validatorSession_round_id::ID:
      func(static_cast<validatorSession_round_id &>(obj));
      return true;
    case validatorSession_message_submittedBlock::ID:
      func(static_cast<validatorSession_message_submittedBlock &>(obj));
      return true;
    case validatorSession_message_approvedBlock::ID:
      func(static_cast<validatorSession_message_approvedBlock &>(obj));
      return true;
    case validatorSession_message_rejectedBlock::ID:
      func(static_cast<validatorSession_message_rejectedBlock &>(obj));
      return true;
    case validatorSession_message_commit::ID:
      func(static_cast<validatorSession_message_commit &>(obj));
      return true;
    case validatorSession_message_vote::ID:
      func(static_cast<validatorSession_message_vote &>(obj));
      return true;
    case validatorSession_message_precommit::ID:
      func(static_cast<validatorSession_message_precommit &>(obj));
      return true;
    case validatorSession_message_empty::ID:
      func(static_cast<validatorSession_message_empty &>(obj));
      return true;
    case validatorSession_candidate_id::ID:
      func(static_cast<validatorSession_candidate_id &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(Function &obj, const T &func) {
  switch (obj.get_id()) {
    case catchain_getBlock::ID:
      func(static_cast<catchain_getBlock &>(obj));
      return true;
    case catchain_getBlockHistory::ID:
      func(static_cast<catchain_getBlockHistory &>(obj));
      return true;
    case catchain_getBlocks::ID:
      func(static_cast<catchain_getBlocks &>(obj));
      return true;
    case catchain_getDifference::ID:
      func(static_cast<catchain_getDifference &>(obj));
      return true;
    case dht_findNode::ID:
      func(static_cast<dht_findNode &>(obj));
      return true;
    case dht_findValue::ID:
      func(static_cast<dht_findValue &>(obj));
      return true;
    case dht_getSignedAddressList::ID:
      func(static_cast<dht_getSignedAddressList &>(obj));
      return true;
    case dht_ping::ID:
      func(static_cast<dht_ping &>(obj));
      return true;
    case dht_query::ID:
      func(static_cast<dht_query &>(obj));
      return true;
    case dht_store::ID:
      func(static_cast<dht_store &>(obj));
      return true;
    case getTestObject::ID:
      func(static_cast<getTestObject &>(obj));
      return true;
    case overlay_getBroadcast::ID:
      func(static_cast<overlay_getBroadcast &>(obj));
      return true;
    case overlay_getBroadcastList::ID:
      func(static_cast<overlay_getBroadcastList &>(obj));
      return true;
    case overlay_getRandomPeers::ID:
      func(static_cast<overlay_getRandomPeers &>(obj));
      return true;
    case overlay_query::ID:
      func(static_cast<overlay_query &>(obj));
      return true;
    case tcp_ping::ID:
      func(static_cast<tcp_ping &>(obj));
      return true;
    case tonNode_downloadBlock::ID:
      func(static_cast<tonNode_downloadBlock &>(obj));
      return true;
    case tonNode_downloadBlockProof::ID:
      func(static_cast<tonNode_downloadBlockProof &>(obj));
      return true;
    case tonNode_downloadBlockProofLink::ID:
      func(static_cast<tonNode_downloadBlockProofLink &>(obj));
      return true;
    case tonNode_downloadPersistentState::ID:
      func(static_cast<tonNode_downloadPersistentState &>(obj));
      return true;
    case tonNode_downloadZeroState::ID:
      func(static_cast<tonNode_downloadZeroState &>(obj));
      return true;
    case tonNode_getNextBlockDescription::ID:
      func(static_cast<tonNode_getNextBlockDescription &>(obj));
      return true;
    case tonNode_getNextKeyBlockIds::ID:
      func(static_cast<tonNode_getNextKeyBlockIds &>(obj));
      return true;
    case tonNode_prepareBlock::ID:
      func(static_cast<tonNode_prepareBlock &>(obj));
      return true;
    case tonNode_prepareBlockProof::ID:
      func(static_cast<tonNode_prepareBlockProof &>(obj));
      return true;
    case tonNode_preparePersistentState::ID:
      func(static_cast<tonNode_preparePersistentState &>(obj));
      return true;
    case tonNode_prepareZeroState::ID:
      func(static_cast<tonNode_prepareZeroState &>(obj));
      return true;
    case validatorSession_downloadCandidate::ID:
      func(static_cast<validatorSession_downloadCandidate &>(obj));
      return true;
    case validatorSession_ping::ID:
      func(static_cast<validatorSession_ping &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(Hashable &obj, const T &func) {
  switch (obj.get_id()) {
    case hashable_bool::ID:
      func(static_cast<hashable_bool &>(obj));
      return true;
    case hashable_int32::ID:
      func(static_cast<hashable_int32 &>(obj));
      return true;
    case hashable_int64::ID:
      func(static_cast<hashable_int64 &>(obj));
      return true;
    case hashable_int256::ID:
      func(static_cast<hashable_int256 &>(obj));
      return true;
    case hashable_bytes::ID:
      func(static_cast<hashable_bytes &>(obj));
      return true;
    case hashable_pair::ID:
      func(static_cast<hashable_pair &>(obj));
      return true;
    case hashable_vector::ID:
      func(static_cast<hashable_vector &>(obj));
      return true;
    case hashable_validatorSessionOldRound::ID:
      func(static_cast<hashable_validatorSessionOldRound &>(obj));
      return true;
    case hashable_validatorSessionRoundAttempt::ID:
      func(static_cast<hashable_validatorSessionRoundAttempt &>(obj));
      return true;
    case hashable_validatorSessionRound::ID:
      func(static_cast<hashable_validatorSessionRound &>(obj));
      return true;
    case hashable_blockSignature::ID:
      func(static_cast<hashable_blockSignature &>(obj));
      return true;
    case hashable_sentBlock::ID:
      func(static_cast<hashable_sentBlock &>(obj));
      return true;
    case hashable_sentBlockEmpty::ID:
      func(static_cast<hashable_sentBlockEmpty &>(obj));
      return true;
    case hashable_vote::ID:
      func(static_cast<hashable_vote &>(obj));
      return true;
    case hashable_blockCandidate::ID:
      func(static_cast<hashable_blockCandidate &>(obj));
      return true;
    case hashable_blockCandidateAttempt::ID:
      func(static_cast<hashable_blockCandidateAttempt &>(obj));
      return true;
    case hashable_cntVector::ID:
      func(static_cast<hashable_cntVector &>(obj));
      return true;
    case hashable_cntSortedVector::ID:
      func(static_cast<hashable_cntSortedVector &>(obj));
      return true;
    case hashable_validatorSession::ID:
      func(static_cast<hashable_validatorSession &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(PrivateKey &obj, const T &func) {
  switch (obj.get_id()) {
    case pk_unenc::ID:
      func(static_cast<pk_unenc &>(obj));
      return true;
    case pk_ed25519::ID:
      func(static_cast<pk_ed25519 &>(obj));
      return true;
    case pk_aes::ID:
      func(static_cast<pk_aes &>(obj));
      return true;
    case pk_overlay::ID:
      func(static_cast<pk_overlay &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(PublicKey &obj, const T &func) {
  switch (obj.get_id()) {
    case pub_unenc::ID:
      func(static_cast<pub_unenc &>(obj));
      return true;
    case pub_ed25519::ID:
      func(static_cast<pub_ed25519 &>(obj));
      return true;
    case pub_aes::ID:
      func(static_cast<pub_aes &>(obj));
      return true;
    case pub_overlay::ID:
      func(static_cast<pub_overlay &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(TestObject &obj, const T &func) {
  switch (obj.get_id()) {
    case testObject::ID:
      func(static_cast<testObject &>(obj));
      return true;
    case testString::ID:
      func(static_cast<testString &>(obj));
      return true;
    case testInt::ID:
      func(static_cast<testInt &>(obj));
      return true;
    case testVectorBytes::ID:
      func(static_cast<testVectorBytes &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(adnl_Address &obj, const T &func) {
  switch (obj.get_id()) {
    case adnl_address_udp::ID:
      func(static_cast<adnl_address_udp &>(obj));
      return true;
    case adnl_address_udp6::ID:
      func(static_cast<adnl_address_udp6 &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(adnl_Message &obj, const T &func) {
  switch (obj.get_id()) {
    case adnl_message_createChannel::ID:
      func(static_cast<adnl_message_createChannel &>(obj));
      return true;
    case adnl_message_confirmChannel::ID:
      func(static_cast<adnl_message_confirmChannel &>(obj));
      return true;
    case adnl_message_custom::ID:
      func(static_cast<adnl_message_custom &>(obj));
      return true;
    case adnl_message_nop::ID:
      func(static_cast<adnl_message_nop &>(obj));
      return true;
    case adnl_message_reinit::ID:
      func(static_cast<adnl_message_reinit &>(obj));
      return true;
    case adnl_message_query::ID:
      func(static_cast<adnl_message_query &>(obj));
      return true;
    case adnl_message_answer::ID:
      func(static_cast<adnl_message_answer &>(obj));
      return true;
    case adnl_message_part::ID:
      func(static_cast<adnl_message_part &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(catchain_BlockResult &obj, const T &func) {
  switch (obj.get_id()) {
    case catchain_blockNotFound::ID:
      func(static_cast<catchain_blockNotFound &>(obj));
      return true;
    case catchain_blockResult::ID:
      func(static_cast<catchain_blockResult &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(catchain_Difference &obj, const T &func) {
  switch (obj.get_id()) {
    case catchain_difference::ID:
      func(static_cast<catchain_difference &>(obj));
      return true;
    case catchain_differenceFork::ID:
      func(static_cast<catchain_differenceFork &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(catchain_block_inner_Data &obj, const T &func) {
  switch (obj.get_id()) {
    case catchain_block_data_badBlock::ID:
      func(static_cast<catchain_block_data_badBlock &>(obj));
      return true;
    case catchain_block_data_fork::ID:
      func(static_cast<catchain_block_data_fork &>(obj));
      return true;
    case catchain_block_data_nop::ID:
      func(static_cast<catchain_block_data_nop &>(obj));
      return true;
    case catchain_block_data_vector::ID:
      func(static_cast<catchain_block_data_vector &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_block_Info &obj, const T &func) {
  switch (obj.get_id()) {
    case db_block_info::ID:
      func(static_cast<db_block_info &>(obj));
      return true;
    case db_block_archivedInfo::ID:
      func(static_cast<db_block_archivedInfo &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_blockdb_Key &obj, const T &func) {
  switch (obj.get_id()) {
    case db_blockdb_key_lru::ID:
      func(static_cast<db_blockdb_key_lru &>(obj));
      return true;
    case db_blockdb_key_value::ID:
      func(static_cast<db_blockdb_key_value &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_filedb_Key &obj, const T &func) {
  switch (obj.get_id()) {
    case db_filedb_key_empty::ID:
      func(static_cast<db_filedb_key_empty &>(obj));
      return true;
    case db_filedb_key_blockFile::ID:
      func(static_cast<db_filedb_key_blockFile &>(obj));
      return true;
    case db_filedb_key_zeroStateFile::ID:
      func(static_cast<db_filedb_key_zeroStateFile &>(obj));
      return true;
    case db_filedb_key_persistentStateFile::ID:
      func(static_cast<db_filedb_key_persistentStateFile &>(obj));
      return true;
    case db_filedb_key_proof::ID:
      func(static_cast<db_filedb_key_proof &>(obj));
      return true;
    case db_filedb_key_proofLink::ID:
      func(static_cast<db_filedb_key_proofLink &>(obj));
      return true;
    case db_filedb_key_signatures::ID:
      func(static_cast<db_filedb_key_signatures &>(obj));
      return true;
    case db_filedb_key_candidate::ID:
      func(static_cast<db_filedb_key_candidate &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_lt_Key &obj, const T &func) {
  switch (obj.get_id()) {
    case db_lt_el_key::ID:
      func(static_cast<db_lt_el_key &>(obj));
      return true;
    case db_lt_desc_key::ID:
      func(static_cast<db_lt_desc_key &>(obj));
      return true;
    case db_lt_shard_key::ID:
      func(static_cast<db_lt_shard_key &>(obj));
      return true;
    case db_lt_status_key::ID:
      func(static_cast<db_lt_status_key &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_root_Key &obj, const T &func) {
  switch (obj.get_id()) {
    case db_root_key_cellDb::ID:
      func(static_cast<db_root_key_cellDb &>(obj));
      return true;
    case db_root_key_blockDb::ID:
      func(static_cast<db_root_key_blockDb &>(obj));
      return true;
    case db_root_key_config::ID:
      func(static_cast<db_root_key_config &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(db_state_Key &obj, const T &func) {
  switch (obj.get_id()) {
    case db_state_key_destroyedSessions::ID:
      func(static_cast<db_state_key_destroyedSessions &>(obj));
      return true;
    case db_state_key_initBlockId::ID:
      func(static_cast<db_state_key_initBlockId &>(obj));
      return true;
    case db_state_key_gcBlockId::ID:
      func(static_cast<db_state_key_gcBlockId &>(obj));
      return true;
    case db_state_key_shardClient::ID:
      func(static_cast<db_state_key_shardClient &>(obj));
      return true;
    case db_state_key_asyncSerializer::ID:
      func(static_cast<db_state_key_asyncSerializer &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(dht_UpdateRule &obj, const T &func) {
  switch (obj.get_id()) {
    case dht_updateRule_signature::ID:
      func(static_cast<dht_updateRule_signature &>(obj));
      return true;
    case dht_updateRule_anybody::ID:
      func(static_cast<dht_updateRule_anybody &>(obj));
      return true;
    case dht_updateRule_overlayNodes::ID:
      func(static_cast<dht_updateRule_overlayNodes &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(dht_ValueResult &obj, const T &func) {
  switch (obj.get_id()) {
    case dht_valueNotFound::ID:
      func(static_cast<dht_valueNotFound &>(obj));
      return true;
    case dht_valueFound::ID:
      func(static_cast<dht_valueFound &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(dht_config_Local &obj, const T &func) {
  switch (obj.get_id()) {
    case dht_config_local::ID:
      func(static_cast<dht_config_local &>(obj));
      return true;
    case dht_config_random_local::ID:
      func(static_cast<dht_config_random_local &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(fec_Type &obj, const T &func) {
  switch (obj.get_id()) {
    case fec_raptorQ::ID:
      func(static_cast<fec_raptorQ &>(obj));
      return true;
    case fec_roundRobin::ID:
      func(static_cast<fec_roundRobin &>(obj));
      return true;
    case fec_online::ID:
      func(static_cast<fec_online &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(overlay_Broadcast &obj, const T &func) {
  switch (obj.get_id()) {
    case overlay_fec_received::ID:
      func(static_cast<overlay_fec_received &>(obj));
      return true;
    case overlay_fec_completed::ID:
      func(static_cast<overlay_fec_completed &>(obj));
      return true;
    case overlay_unicast::ID:
      func(static_cast<overlay_unicast &>(obj));
      return true;
    case overlay_broadcast::ID:
      func(static_cast<overlay_broadcast &>(obj));
      return true;
    case overlay_broadcastFec::ID:
      func(static_cast<overlay_broadcastFec &>(obj));
      return true;
    case overlay_broadcastFecShort::ID:
      func(static_cast<overlay_broadcastFecShort &>(obj));
      return true;
    case overlay_broadcastNotFound::ID:
      func(static_cast<overlay_broadcastNotFound &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(overlay_Certificate &obj, const T &func) {
  switch (obj.get_id()) {
    case overlay_certificate::ID:
      func(static_cast<overlay_certificate &>(obj));
      return true;
    case overlay_emptyCertificate::ID:
      func(static_cast<overlay_emptyCertificate &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(overlay_config_Local &obj, const T &func) {
  switch (obj.get_id()) {
    case overlay_config_local::ID:
      func(static_cast<overlay_config_local &>(obj));
      return true;
    case overlay_config_random_local::ID:
      func(static_cast<overlay_config_random_local &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(rldp_Message &obj, const T &func) {
  switch (obj.get_id()) {
    case rldp_message::ID:
      func(static_cast<rldp_message &>(obj));
      return true;
    case rldp_query::ID:
      func(static_cast<rldp_query &>(obj));
      return true;
    case rldp_answer::ID:
      func(static_cast<rldp_answer &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(rldp_MessagePart &obj, const T &func) {
  switch (obj.get_id()) {
    case rldp_messagePart::ID:
      func(static_cast<rldp_messagePart &>(obj));
      return true;
    case rldp_confirm::ID:
      func(static_cast<rldp_confirm &>(obj));
      return true;
    case rldp_complete::ID:
      func(static_cast<rldp_complete &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(test0_MasterchainBlockExtra &obj, const T &func) {
  switch (obj.get_id()) {
    case test0_masterchainBlockExtra_empty::ID:
      func(static_cast<test0_masterchainBlockExtra_empty &>(obj));
      return true;
    case test0_masterchainBlockExtra_extra::ID:
      func(static_cast<test0_masterchainBlockExtra_extra &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(test0_MasterchainStateExtra &obj, const T &func) {
  switch (obj.get_id()) {
    case test0_masterchainStateExtra_empty::ID:
      func(static_cast<test0_masterchainStateExtra_empty &>(obj));
      return true;
    case test0_masterchainStateExtra_extra::ID:
      func(static_cast<test0_masterchainStateExtra_extra &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(tonNode_BlockDescription &obj, const T &func) {
  switch (obj.get_id()) {
    case tonNode_blockDescriptionEmpty::ID:
      func(static_cast<tonNode_blockDescriptionEmpty &>(obj));
      return true;
    case tonNode_blockDescription::ID:
      func(static_cast<tonNode_blockDescription &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(tonNode_Broadcast &obj, const T &func) {
  switch (obj.get_id()) {
    case tonNode_blockBroadcast::ID:
      func(static_cast<tonNode_blockBroadcast &>(obj));
      return true;
    case tonNode_ihrMessageBroadcast::ID:
      func(static_cast<tonNode_ihrMessageBroadcast &>(obj));
      return true;
    case tonNode_externalMessageBroadcast::ID:
      func(static_cast<tonNode_externalMessageBroadcast &>(obj));
      return true;
    case tonNode_newShardBlockBroadcast::ID:
      func(static_cast<tonNode_newShardBlockBroadcast &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(tonNode_Prepared &obj, const T &func) {
  switch (obj.get_id()) {
    case tonNode_prepared::ID:
      func(static_cast<tonNode_prepared &>(obj));
      return true;
    case tonNode_notFound::ID:
      func(static_cast<tonNode_notFound &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(tonNode_PreparedProof &obj, const T &func) {
  switch (obj.get_id()) {
    case tonNode_preparedProofEmpty::ID:
      func(static_cast<tonNode_preparedProofEmpty &>(obj));
      return true;
    case tonNode_preparedProof::ID:
      func(static_cast<tonNode_preparedProof &>(obj));
      return true;
    case tonNode_preparedProofLink::ID:
      func(static_cast<tonNode_preparedProofLink &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(tonNode_PreparedState &obj, const T &func) {
  switch (obj.get_id()) {
    case tonNode_preparedState::ID:
      func(static_cast<tonNode_preparedState &>(obj));
      return true;
    case tonNode_notFoundState::ID:
      func(static_cast<tonNode_notFoundState &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(validator_config_Local &obj, const T &func) {
  switch (obj.get_id()) {
    case validator_config_local::ID:
      func(static_cast<validator_config_local &>(obj));
      return true;
    case validator_config_random_local::ID:
      func(static_cast<validator_config_random_local &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(validatorSession_Message &obj, const T &func) {
  switch (obj.get_id()) {
    case validatorSession_message_startSession::ID:
      func(static_cast<validatorSession_message_startSession &>(obj));
      return true;
    case validatorSession_message_finishSession::ID:
      func(static_cast<validatorSession_message_finishSession &>(obj));
      return true;
    default:
      return false;
  }
}

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(validatorSession_round_Message &obj, const T &func) {
  switch (obj.get_id()) {
    case validatorSession_message_submittedBlock::ID:
      func(static_cast<validatorSession_message_submittedBlock &>(obj));
      return true;
    case validatorSession_message_approvedBlock::ID:
      func(static_cast<validatorSession_message_approvedBlock &>(obj));
      return true;
    case validatorSession_message_rejectedBlock::ID:
      func(static_cast<validatorSession_message_rejectedBlock &>(obj));
      return true;
    case validatorSession_message_commit::ID:
      func(static_cast<validatorSession_message_commit &>(obj));
      return true;
    case validatorSession_message_vote::ID:
      func(static_cast<validatorSession_message_vote &>(obj));
      return true;
    case validatorSession_message_precommit::ID:
      func(static_cast<validatorSession_message_precommit &>(obj));
      return true;
    case validatorSession_message_empty::ID:
      func(static_cast<validatorSession_message_empty &>(obj));
      return true;
    default:
      return false;
  }
}

}  // namespace ton_api
}  // namespace ton 
