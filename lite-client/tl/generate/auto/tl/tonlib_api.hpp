#pragma once

#include "tonlib_api.h"

namespace ton {
namespace tonlib_api {

/**
 * Calls specified function object with the specified object downcasted to the most-derived type.
 * \param[in] obj Object to pass as an argument to the function object.
 * \param[in] func Function object to which the object will be passed.
 * \returns whether function object call has happened. Should always return true for correct parameters.
 */
template <class T>
bool downcast_call(Object &obj, const T &func) {
  switch (obj.get_id()) {
    case accountAddress::ID:
      func(static_cast<accountAddress &>(obj));
      return true;
    case error::ID:
      func(static_cast<error &>(obj));
      return true;
    case exportedEncryptedKey::ID:
      func(static_cast<exportedEncryptedKey &>(obj));
      return true;
    case exportedKey::ID:
      func(static_cast<exportedKey &>(obj));
      return true;
    case exportedPemKey::ID:
      func(static_cast<exportedPemKey &>(obj));
      return true;
    case inputKey::ID:
      func(static_cast<inputKey &>(obj));
      return true;
    case key::ID:
      func(static_cast<key &>(obj));
      return true;
    case ok::ID:
      func(static_cast<ok &>(obj));
      return true;
    case options::ID:
      func(static_cast<options &>(obj));
      return true;
    case generic_accountStateRaw::ID:
      func(static_cast<generic_accountStateRaw &>(obj));
      return true;
    case generic_accountStateTestWallet::ID:
      func(static_cast<generic_accountStateTestWallet &>(obj));
      return true;
    case generic_accountStateTestGiver::ID:
      func(static_cast<generic_accountStateTestGiver &>(obj));
      return true;
    case generic_accountStateUninited::ID:
      func(static_cast<generic_accountStateUninited &>(obj));
      return true;
    case generic_initialAccountStateRaw::ID:
      func(static_cast<generic_initialAccountStateRaw &>(obj));
      return true;
    case generic_initialAccountStateTestWallet::ID:
      func(static_cast<generic_initialAccountStateTestWallet &>(obj));
      return true;
    case internal_transactionId::ID:
      func(static_cast<internal_transactionId &>(obj));
      return true;
    case raw_accountState::ID:
      func(static_cast<raw_accountState &>(obj));
      return true;
    case raw_initialAccountState::ID:
      func(static_cast<raw_initialAccountState &>(obj));
      return true;
    case testGiver_accountState::ID:
      func(static_cast<testGiver_accountState &>(obj));
      return true;
    case testWallet_accountState::ID:
      func(static_cast<testWallet_accountState &>(obj));
      return true;
    case testWallet_initialAccountState::ID:
      func(static_cast<testWallet_initialAccountState &>(obj));
      return true;
    case uninited_accountState::ID:
      func(static_cast<uninited_accountState &>(obj));
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
    case changeLocalPassword::ID:
      func(static_cast<changeLocalPassword &>(obj));
      return true;
    case close::ID:
      func(static_cast<close &>(obj));
      return true;
    case createNewKey::ID:
      func(static_cast<createNewKey &>(obj));
      return true;
    case deleteKey::ID:
      func(static_cast<deleteKey &>(obj));
      return true;
    case exportEncryptedKey::ID:
      func(static_cast<exportEncryptedKey &>(obj));
      return true;
    case exportKey::ID:
      func(static_cast<exportKey &>(obj));
      return true;
    case exportPemKey::ID:
      func(static_cast<exportPemKey &>(obj));
      return true;
    case generic_getAccountState::ID:
      func(static_cast<generic_getAccountState &>(obj));
      return true;
    case generic_sendGrams::ID:
      func(static_cast<generic_sendGrams &>(obj));
      return true;
    case importEncryptedKey::ID:
      func(static_cast<importEncryptedKey &>(obj));
      return true;
    case importKey::ID:
      func(static_cast<importKey &>(obj));
      return true;
    case importPemKey::ID:
      func(static_cast<importPemKey &>(obj));
      return true;
    case init::ID:
      func(static_cast<init &>(obj));
      return true;
    case options_setConfig::ID:
      func(static_cast<options_setConfig &>(obj));
      return true;
    case raw_getAccountAddress::ID:
      func(static_cast<raw_getAccountAddress &>(obj));
      return true;
    case raw_getAccountState::ID:
      func(static_cast<raw_getAccountState &>(obj));
      return true;
    case raw_sendMessage::ID:
      func(static_cast<raw_sendMessage &>(obj));
      return true;
    case runTests::ID:
      func(static_cast<runTests &>(obj));
      return true;
    case testGiver_getAccountAddress::ID:
      func(static_cast<testGiver_getAccountAddress &>(obj));
      return true;
    case testGiver_getAccountState::ID:
      func(static_cast<testGiver_getAccountState &>(obj));
      return true;
    case testGiver_sendGrams::ID:
      func(static_cast<testGiver_sendGrams &>(obj));
      return true;
    case testWallet_getAccountAddress::ID:
      func(static_cast<testWallet_getAccountAddress &>(obj));
      return true;
    case testWallet_getAccountState::ID:
      func(static_cast<testWallet_getAccountState &>(obj));
      return true;
    case testWallet_init::ID:
      func(static_cast<testWallet_init &>(obj));
      return true;
    case testWallet_sendGrams::ID:
      func(static_cast<testWallet_sendGrams &>(obj));
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
bool downcast_call(generic_AccountState &obj, const T &func) {
  switch (obj.get_id()) {
    case generic_accountStateRaw::ID:
      func(static_cast<generic_accountStateRaw &>(obj));
      return true;
    case generic_accountStateTestWallet::ID:
      func(static_cast<generic_accountStateTestWallet &>(obj));
      return true;
    case generic_accountStateTestGiver::ID:
      func(static_cast<generic_accountStateTestGiver &>(obj));
      return true;
    case generic_accountStateUninited::ID:
      func(static_cast<generic_accountStateUninited &>(obj));
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
bool downcast_call(generic_InitialAccountState &obj, const T &func) {
  switch (obj.get_id()) {
    case generic_initialAccountStateRaw::ID:
      func(static_cast<generic_initialAccountStateRaw &>(obj));
      return true;
    case generic_initialAccountStateTestWallet::ID:
      func(static_cast<generic_initialAccountStateTestWallet &>(obj));
      return true;
    default:
      return false;
  }
}

}  // namespace tonlib_api
}  // namespace ton 
