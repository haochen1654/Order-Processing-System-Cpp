#ifndef ORDER_H
#define ORDER_H

#include <absl/status/status.h>
#include <absl/status/statusor.h>
#include <absl/strings/string_view.h>
#include <constants/constants.h>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace models {

struct Order {
  std::string id;
  std::string name;
  constants::Temperature temp;
  int64_t price;
  int64_t freshness;

  void fromJson(const nlohmann::json &j, const Order &o) {
    j.at("id").get_to(o.id);
    j.at("name").get_to(o.name);
    j.at("temp").get_to(o.temp);
    j.at("price").get_to(o.price);
    j.at("freshness").get_to(o.freshness);
  }

  absl::StatusOr<std::vector<Order>>
  parseOrdersFromString(absl::string_view json_str) {
    if (json_str.empty()) {
      return absl::InvalidArgumentError("Input JSON string is empty");
    }

    auto j = nlohmann::json::parse(json_str.begin(), json_str.end());

    if (!j.is_array()) {
      return absl::InvalidArgumentError("Expected a JSON array of orders");
    }

    return j.get<std::vector<Order>>();
  }
};

} // namespace models
#endif // ORDER_H