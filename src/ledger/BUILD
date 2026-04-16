load(
    "@rules_cc//cc:defs.bzl",
    "cc_library",
)

cc_library(
    name = "action",
    hdrs = ["action.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = ["@nlohmann_json//:json"],
)

cc_library(
    name = "action_ledger",
    srcs = ["action_ledger.cc"],
    hdrs = ["action_ledger.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        "action",
        "@abseil-cpp//absl/synchronization",
    ],
)
