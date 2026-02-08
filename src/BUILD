load("@rules_cc//cc:defs.bzl", 
    "cc_binary", "cc_library")

cc_library(
    name = "action",
    hdrs = ["client/action.h"],
    deps = ["@nlohmann_json//:json"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
)

cc_library(
    name = "order",
    hdrs = ["client/order.h"],
    deps = ["@nlohmann_json//:json"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
)

cc_library(
    name = "problem",
    hdrs = ["client/problem.h"],
    deps = [":order"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
)

cc_library(
    name = "client",
    hdrs = ["client/client.h"],
    srcs = ["client/client.cpp"],
    deps = [":action", ":problem", "@cpr//:cpr"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
)

cc_binary(
  name = "order_processing_system_main",
  deps = ["@abseil-cpp//absl/strings", "client"],
  srcs = ["main.cpp"],
)