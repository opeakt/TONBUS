#include <iostream>

#include "auto/tl/ton_api.h"
#include "auto/tl/ton_api_json.h"

#include "tl/tl_json.h"

namespace {
std::string config = R"json(
{
  "@type" : "config.local",
  "dht": [
    {
      "@type" : "dht.config.local",
      "id" : {
        "@type" : "adnl.id.pk.ed25519",
        "key" : "VdeZz3BEIE8+tuPSBUNKN0jQXL/0T/SoK4ZpJ9vTCNQ="
      },
      "addr_list" : {
        "@type" : "adnl.addressList",
        "version" : 0,
        "addrs" : [
          {
            "@type" : "adnl.address.udp",
            "ip" : 2130706433,
            "port" : 16000
          }
        ]
      }
    }
  ]
}
)json";
std::string config2 = R"json(
{
  "@type" : "config.local",
  "dht": [
    {
      "@type" : "dht.config.local",
      "id" : {
        "@type" : "adnl.id.pk.ed25519",
        "key" : "VdeZz3BEIE8+tuPSBUNKN0jQXL/0T/SoK4ZpJ9vTCNQ="
      },
      "addr_list" : {
        "@type" : "adnl.addressList",
        "version" : 0,
        "addrs" : [
          {
            "@type" : "adnl.address.udp",
            "ip" : 2130706433,
            "port" : 16000
          }
        ]
      }
    }
  ],
  "adnl" : {
    "@type" : "adnl.config.local"
  }
}
)json";
}  // namespace

int main() {
  std::cout << "hello world!\n";

  auto decode_encode = [](auto obj_json) {
    auto as_json_value = td::json_decode(obj_json).move_as_ok();
    ton::ton_api::object_ptr<ton::ton_api::Object> obj2;
    from_json(obj2, as_json_value).ensure();
    CHECK(obj2 != nullptr);
    return td::json_encode<std::string>(td::ToJson(obj2));
  };

  auto test_tl_json = [&decode_encode](auto obj) {
    auto obj_json = td::json_encode<std::string>(td::ToJson(obj));
    std::cout << obj_json << "\n";

    auto obj2_json = decode_encode(obj_json);
    CHECK(obj_json == obj2_json);
  };

  td::Bits256 uint256;
  uint256.set_ones();
  test_tl_json(ton::ton_api::make_object<ton::ton_api::adnl_id_short>(uint256));

  test_tl_json(ton::ton_api::make_object<ton::ton_api::testObject>(
      1, ton::ton_api::make_object<ton::ton_api::adnl_id_short>(uint256),
      ton::ton_api::make_object<ton::ton_api::getTestObject>()));

  std::cout << decode_encode(config) << std::endl;
  std::cout << decode_encode(config2) << std::endl;

  auto decode_encode_local = [](auto obj_json) {
    auto as_json_value = td::json_decode(obj_json).move_as_ok();
    ton::ton_api::config_local config_local;
    from_json(config_local, as_json_value.get_object()).ensure();
    return td::json_encode<std::string>(td::ToJson(config_local));
  };
  std::cout << decode_encode_local(config) << std::endl;
  std::cout << decode_encode_local(config2) << std::endl;

  auto create_vector_bytes = [] {
    std::vector<td::BufferSlice> res;
    res.emplace_back("fdjskld");
    res.emplace_back("fdj\0kld");
    res.emplace_back("fdj\0\x01\xff\x7fkld");
    return res;
  };
  test_tl_json(ton::ton_api::make_object<ton::ton_api::testVectorBytes>(create_vector_bytes()));
}
