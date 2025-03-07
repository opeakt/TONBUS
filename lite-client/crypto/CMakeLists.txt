cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

if (NOT OPENSSL_FOUND)
  find_package(OpenSSL REQUIRED)
endif()

set (TON_CRYPTO_SOURCE
  Ed25519.cpp
  common/bigint.cpp
  common/refint.cpp
  common/bitstring.cpp
  common/util.cpp
  ellcurve/Ed25519.cpp
  ellcurve/Fp25519.cpp
  ellcurve/Montgomery.cpp
  ellcurve/TwEdwards.cpp
  openssl/bignum.cpp
  openssl/residue.cpp
  openssl/rand.cpp
  vm/stack.cpp
  vm/atom.cpp
  vm/continuation.cpp
  vm/dict.cpp
  vm/dispatch.cpp
  vm/opctable.cpp
  vm/cp0.cpp
  vm/stackops.cpp
  vm/tupleops.cpp
  vm/arithops.cpp
  vm/cellops.cpp
  vm/contops.cpp
  vm/dictops.cpp
  vm/debugops.cpp
  vm/tonops.cpp
  vm/boc.cpp
  tl/tlblib.cpp

  Ed25519.h
  common/AtomicRef.h
  common/bigint.hpp
  common/bitstring.h
  common/refcnt.hpp
  common/refint.h
  common/util.h

  ellcurve/Ed25519.h
  ellcurve/Fp25519.h
  ellcurve/Montgomery.h
  ellcurve/TwEdwards.h

  openssl/bignum.h
  openssl/digest.h
  openssl/rand.hpp
  openssl/residue.h

  tl/tlbc-aux.h
  tl/tlbc-data.h
  tl/tlblib.hpp

  vm/arithops.h
  vm/atom.h
  vm/boc.h
  vm/box.hpp
  vm/cellops.h
  vm/continuation.h
  vm/contops.h
  vm/cp0.h
  vm/debugops.h
  vm/dict.h
  vm/dictops.h
  vm/excno.hpp
  vm/fmt.hpp
  vm/log.h
  vm/opctable.h
  vm/stack.hpp
  vm/stackops.h
  vm/tupleops.h
  vm/tonops.h
  vm/vmstate.h

  vm/cells.h
  vm/cellslice.h

  vm/cells/Cell.cpp
  vm/cells/CellBuilder.cpp
  vm/cells/CellHash.cpp
  vm/cells/CellSlice.cpp
  vm/cells/CellTraits.cpp
  vm/cells/CellUsageTree.cpp
  vm/cells/DataCell.cpp
  vm/cells/LevelMask.cpp
  vm/cells/MerkleProof.cpp
  vm/cells/MerkleUpdate.cpp

  vm/cells/Cell.h
  vm/cells/CellBuilder.h
  vm/cells/CellHash.h
  vm/cells/CellSlice.h
  vm/cells/CellTraits.h
  vm/cells/CellUsageTree.h
  vm/cells/CellWithStorage.h
  vm/cells/DataCell.h
  vm/cells/ExtCell.h
  vm/cells/LevelMask.h
  vm/cells/MerkleProof.h
  vm/cells/MerkleUpdate.h
  vm/cells/PrunnedCell.h
  vm/cells/UsageCell.h
  vm/cells/VirtualCell.h
  vm/cells/VirtualizationParameters.h

  vm/db/StaticBagOfCellsDb.h
  vm/db/StaticBagOfCellsDb.cpp

  vm/db/BlobView.h
  vm/db/BlobView.cpp
)

set (TON_DB_SOURCE
  vm/db/DynamicBagOfCellsDb.cpp
  vm/db/CellStorage.cpp
  vm/db/TonDb.cpp

  vm/db/DynamicBagOfCellsDb.h
  vm/db/CellHashTable.h
  vm/db/CellStorage.h
  vm/db/TonDb.h
)

set (FIFT_SOURCE
  fift/Dictionary.cpp
  fift/Fift.cpp
  fift/IntCtx.cpp
  fift/SourceLookup.cpp
  fift/utils.cpp
  fift/words.cpp

  fift/Dictionary.h
  fift/Fift.h
  fift/IntCtx.h
  fift/SourceLookup.h
  fift/utils.h
  fift/words.h
)

set(TLB_BLOCK_AUTO
  ${CMAKE_CURRENT_SOURCE_DIR}/block/block-auto.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/block/block-auto.h
)

set (BLOCK_SOURCE
  block/Binlog.h
  block/Binlog.cpp
  block/block.cpp
  block/block-db.cpp
  block/check-proof.cpp
  block/mc-config.cpp
  block/output-queue-merger.cpp
  block/transaction.cpp
  ${TLB_BLOCK_AUTO}

  block/block-binlog.h
  block/block-db-impl.h
  block/block-db.h
  block/block.h
  block/check-proof.h
  block/output-queue-merger.h
  block/transaction.h
)

set(ED25519_TEST_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/test/Ed25519.cpp
  PARENT_SCOPE
)

set(TONDB_TEST_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/test/test-db.cpp
  PARENT_SCOPE
)

set(CELLS_TEST_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/test/test-cells.cpp
  PARENT_SCOPE
)

set(TONVM_TEST_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/test/vm.cpp
  PARENT_SCOPE
)

set(FIFT_TEST_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/test/fift.cpp
  PARENT_SCOPE
)

add_library(ton_crypto STATIC ${TON_CRYPTO_SOURCE})
target_include_directories(ton_crypto PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)
target_link_libraries(ton_crypto PUBLIC ${OPENSSL_CRYPTO_LIBRARY} tdutils)
if (NOT WIN32)
  target_link_libraries(ton_crypto PUBLIC dl z)
endif()
target_include_directories(ton_crypto SYSTEM PUBLIC ${OPENSSL_INCLUDE_DIR})

add_library(ton_db STATIC ${TON_DB_SOURCE})
target_include_directories(ton_db PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)
target_link_libraries(ton_db PUBLIC tdutils tddb ton_crypto)

add_executable(test-ed25519-crypto test/test-ed25519-crypto.cpp)
target_include_directories(test-ed25519-crypto PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(test-ed25519-crypto PUBLIC ton_crypto)

add_library(fift-lib ${FIFT_SOURCE})
target_include_directories(fift-lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(fift-lib PUBLIC ton_crypto ton_db tdutils ton_block)
set_target_properties(fift-lib PROPERTIES OUTPUT_NAME fift)

add_executable(fift fift/fift-main.cpp)
target_link_libraries(fift PUBLIC fift-lib)
if (WINGETOPT_FOUND)
  target_link_libraries_system(fift wingetopt)
endif()

add_executable(func func/func.cpp)
target_include_directories(func PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(func PUBLIC ton_crypto)
if (WINGETOPT_FOUND)
  target_link_libraries_system(func wingetopt)
endif()

add_executable(tlbc tl/tlbc.cpp)
target_include_directories(tlbc PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/func>)
target_link_libraries(tlbc PUBLIC ton_crypto)
if (WINGETOPT_FOUND)
  target_link_libraries_system(tlbc wingetopt)
endif()

set_source_files_properties(${TLB_BLOCK_AUTO} PROPERTIES GENERATED TRUE)
add_library(ton_block ${BLOCK_SOURCE})
target_include_directories(ton_block PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/block> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)
target_link_libraries(ton_block PUBLIC ton_crypto tdutils tdactor tl_api)

set(TURN_OFF_LSAN cd .)
if (TON_USE_ASAN AND NOT WIN32)
  set(TURN_OFF_LSAN export LSAN_OPTIONS=detect_leaks=0)
endif()

if (NOT CMAKE_CROSSCOMPILING)
  set(GenerateTlbCmd tlbc)
  add_custom_target(tlb_generate_block
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/block
    COMMAND ${TURN_OFF_LSAN}
    COMMAND ${GenerateTlbCmd} -o block-auto -n block::gen -z block.tlb
    COMMENT "Generate block tlb source files"
    DEPENDS tlbc block/block.tlb
  )
  add_dependencies(ton_block tlb_generate_block)
endif()

