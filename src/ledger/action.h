#ifndef ACTION_H
#define ACTION_H

#include <nlohmann/json.hpp>
#include <string>

namespace ledger {

// Action is a json-friendly representation of an action.
struct Action {
  int64_t timestamp;  // unix timestamp in microseconds
  std::string id;     // order id
  std::string action; // place, move, pickup or discard
  std::string
      target; // heater, cooler or shelf. Target is the destination for move

  // Constructor
  Action(int64_t ts, std::string id_, std::string action_, std::string target_)
      : timestamp(ts), id(std::move(id_)), action(std::move(action_)),
        target(std::move(target_)) {}

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Action, timestamp, id, action, target);
};

} // namespace ledger

#endif // ACTION_H
