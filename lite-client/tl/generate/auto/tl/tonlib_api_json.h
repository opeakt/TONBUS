#pragma once

#include "auto/tl/tonlib_api.h"

#include "auto/tl/tonlib_api.hpp"

#include "td/utils/JsonBuilder.h"
#include "td/utils/Status.h"

#include "crypto/common/bitstring.h"
namespace ton {
namespace tonlib_api{
  using namespace td;
Result<int32> tl_constructor_from_string(tonlib_api::generic_AccountState *object, const std::string &str);
Result<int32> tl_constructor_from_string(tonlib_api::generic_InitialAccountState *object, const std::string &str);
Result<int32> tl_constructor_from_string(tonlib_api::Object *object, const std::string &str);
Result<int32> tl_constructor_from_string(tonlib_api::Function *object, const std::string &str);
Status from_json(tonlib_api::accountAddress &to, JsonObject &from);
Status from_json(tonlib_api::error &to, JsonObject &from);
Status from_json(tonlib_api::exportedEncryptedKey &to, JsonObject &from);
Status from_json(tonlib_api::exportedKey &to, JsonObject &from);
Status from_json(tonlib_api::exportedPemKey &to, JsonObject &from);
Status from_json(tonlib_api::inputKey &to, JsonObject &from);
Status from_json(tonlib_api::key &to, JsonObject &from);
Status from_json(tonlib_api::ok &to, JsonObject &from);
Status from_json(tonlib_api::options &to, JsonObject &from);
Status from_json(tonlib_api::generic_accountStateRaw &to, JsonObject &from);
Status from_json(tonlib_api::generic_accountStateTestWallet &to, JsonObject &from);
Status from_json(tonlib_api::generic_accountStateTestGiver &to, JsonObject &from);
Status from_json(tonlib_api::generic_accountStateUninited &to, JsonObject &from);
Status from_json(tonlib_api::generic_initialAccountStateRaw &to, JsonObject &from);
Status from_json(tonlib_api::generic_initialAccountStateTestWallet &to, JsonObject &from);
Status from_json(tonlib_api::internal_transactionId &to, JsonObject &from);
Status from_json(tonlib_api::raw_accountState &to, JsonObject &from);
Status from_json(tonlib_api::raw_initialAccountState &to, JsonObject &from);
Status from_json(tonlib_api::testGiver_accountState &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_accountState &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_initialAccountState &to, JsonObject &from);
Status from_json(tonlib_api::uninited_accountState &to, JsonObject &from);
Status from_json(tonlib_api::changeLocalPassword &to, JsonObject &from);
Status from_json(tonlib_api::close &to, JsonObject &from);
Status from_json(tonlib_api::createNewKey &to, JsonObject &from);
Status from_json(tonlib_api::deleteKey &to, JsonObject &from);
Status from_json(tonlib_api::exportEncryptedKey &to, JsonObject &from);
Status from_json(tonlib_api::exportKey &to, JsonObject &from);
Status from_json(tonlib_api::exportPemKey &to, JsonObject &from);
Status from_json(tonlib_api::generic_getAccountState &to, JsonObject &from);
Status from_json(tonlib_api::generic_sendGrams &to, JsonObject &from);
Status from_json(tonlib_api::importEncryptedKey &to, JsonObject &from);
Status from_json(tonlib_api::importKey &to, JsonObject &from);
Status from_json(tonlib_api::importPemKey &to, JsonObject &from);
Status from_json(tonlib_api::init &to, JsonObject &from);
Status from_json(tonlib_api::options_setConfig &to, JsonObject &from);
Status from_json(tonlib_api::raw_getAccountAddress &to, JsonObject &from);
Status from_json(tonlib_api::raw_getAccountState &to, JsonObject &from);
Status from_json(tonlib_api::raw_sendMessage &to, JsonObject &from);
Status from_json(tonlib_api::runTests &to, JsonObject &from);
Status from_json(tonlib_api::testGiver_getAccountAddress &to, JsonObject &from);
Status from_json(tonlib_api::testGiver_getAccountState &to, JsonObject &from);
Status from_json(tonlib_api::testGiver_sendGrams &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_getAccountAddress &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_getAccountState &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_init &to, JsonObject &from);
Status from_json(tonlib_api::testWallet_sendGrams &to, JsonObject &from);
void to_json(JsonValueScope &jv, const tonlib_api::accountAddress &object);
void to_json(JsonValueScope &jv, const tonlib_api::error &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportedEncryptedKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportedKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportedPemKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::inputKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::key &object);
void to_json(JsonValueScope &jv, const tonlib_api::ok &object);
void to_json(JsonValueScope &jv, const tonlib_api::options &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_AccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateRaw &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateTestWallet &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateTestGiver &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateUninited &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_InitialAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_initialAccountStateRaw &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_initialAccountStateTestWallet &object);
void to_json(JsonValueScope &jv, const tonlib_api::internal_transactionId &object);
void to_json(JsonValueScope &jv, const tonlib_api::raw_accountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::raw_initialAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_accountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_accountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_initialAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::uninited_accountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::changeLocalPassword &object);
void to_json(JsonValueScope &jv, const tonlib_api::close &object);
void to_json(JsonValueScope &jv, const tonlib_api::createNewKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::deleteKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportEncryptedKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::exportPemKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_getAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::generic_sendGrams &object);
void to_json(JsonValueScope &jv, const tonlib_api::importEncryptedKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::importKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::importPemKey &object);
void to_json(JsonValueScope &jv, const tonlib_api::init &object);
void to_json(JsonValueScope &jv, const tonlib_api::options_setConfig &object);
void to_json(JsonValueScope &jv, const tonlib_api::raw_getAccountAddress &object);
void to_json(JsonValueScope &jv, const tonlib_api::raw_getAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::raw_sendMessage &object);
void to_json(JsonValueScope &jv, const tonlib_api::runTests &object);
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_getAccountAddress &object);
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_getAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_sendGrams &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_getAccountAddress &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_getAccountState &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_init &object);
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_sendGrams &object);
inline void to_json(JsonValueScope &jv, const ton::tonlib_api::Object &object) {
  ton::tonlib_api::downcast_call(const_cast<ton::tonlib_api::Object &>(object),[&jv](const auto &object) { to_json(jv, object); });
}
inline void to_json(JsonValueScope &jv, const ton::tonlib_api::Function &object) {
  ton::tonlib_api::downcast_call(const_cast<ton::tonlib_api::Function &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
}  // namespace tonlib_api
}  // namespace ton
