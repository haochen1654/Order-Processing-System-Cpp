load(
    "@rules_cc//cc:defs.bzl",
    "cc_binary",
    "cc_library",
)

cc_library(
    name = "action",
    hdrs = ["ledger/action.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        "@abseil-cpp//absl/status",
        "@abseil-cpp//absl/strings:string_view",
        "@abseil-cpp//absl/time",
        "@jsoncpp",
    ],
)

cc_library(
    name = "action_ledger",
    srcs = ["ledger/action_ledger.cpp"],
    hdrs = ["ledger/action_ledger.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        ":action",
        "@abseil-cpp//absl/synchronization",
    ],
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
        "@abseil-cpp//absl/strings:string_view",
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
