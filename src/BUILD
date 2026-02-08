load(
    "@rules_cc//cc:defs.bzl",
    "cc_binary",
    "cc_library",
)

cc_library(
    name = "action",
    hdrs = ["client/action.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = ["@nlohmann_json//:json"],
)

cc_library(
    name = "order",
    hdrs = ["client/order.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = ["@nlohmann_json//:json"],
)

cc_library(
    name = "problem",
    hdrs = ["client/problem.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [":order"],
)

cc_library(
    name = "client",
    srcs = ["client/client.cpp"],
    hdrs = ["client/client.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        ":action",
        ":problem",
        "@cpr",
    ],
)

cc_binary(
    name = "order_processing_system_main",
    srcs = ["main.cpp"],
    deps = [
        "client",
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
    ],
)
