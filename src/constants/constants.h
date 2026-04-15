#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <nlohmann/json.hpp>

// Constants for the order processing system.
namespace constants {
enum class ActionType { PLACE, MOVE, PICKUP, DISCARD };

NLOHMANN_JSON_SERIALIZE_ENUM(ActionType, {{ActionType::PLACE, "place"},
                                          {ActionType::MOVE, "move"},
                                          {ActionType::PICKUP, "pickup"},
                                          {ActionType::DISCARD, "discard"}});

enum class ShelfType { HEATER, COOLER, SHELF };
NLOHMANN_JSON_SERIALIZE_ENUM(ShelfType, {{ShelfType::HEATER, "heater"},
                                         {ShelfType::COOLER, "cooler"},
                                         {ShelfType::SHELF, "shelf"}});

enum class Temperature { HOT, COLD, ROOM };
NLOHMANN_JSON_SERIALIZE_ENUM(Temperature, {{Temperature::HOT, "hot"},
                                           {Temperature::COLD, "cold"},
                                           {Temperature::ROOM, "room"}});
} // namespace constants
#endif // CONSTANTS_H
