#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstdint>
#include <nlohmann/json.hpp>

namespace models {

struct Options {
  int64_t rate;
  int64_t min;
  int64_t max;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(rate, min, max);
};

} // namespace models
#endif // OPTIONS_H