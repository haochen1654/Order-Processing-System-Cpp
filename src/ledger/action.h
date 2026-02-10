#ifndef ACTION_H
#define ACTION_H

#include <absl/strings/string_view.h>
#include <absl/time/time.h>
#include <chrono>
#include <json/json.h>
#include <string>

// Action is a json-friendly representation of an action.
struct Action {
  int64_t timestamp;  // unix timestamp in microseconds
  std::string id;     // order id
  std::string action; // place, move, pickup or discard
  std::string
      target; // heater, cooler or shelf. Target is the destination for move

  Action() = default;
  Action(absl::Time timestamp, absl::string_view id, absl::string_view action,
         absl::string_view target)
      : timestamp(absl::ToUnixMicros(timestamp)), id(id), action(action),
        target(target) {}

  // Convert struct to Json::Value
  Json::Value toJson() const {
    Json::Value root;
    root["timestamp"] = timestamp;
    root["id"] = id;
    root["action"] = action;
    root["target"] = target;
    return root;
  }

  // Convert struct to JSON string
  std::string toJsonString(bool pretty) const {
    Json::StreamWriterBuilder builder;

    // Configure the builder for pretty or compact output
    builder["indentation"] = pretty ? "  " : "";
    builder["commentStyle"] = "None";
    builder["emitUTF8"] = true;
    builder["enableYAMLCompatibility"] = false;

    return Json::writeString(builder, toJson());
  }
};

#endif // ACTION_H
