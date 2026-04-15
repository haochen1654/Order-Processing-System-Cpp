load(
    "@rules_cc//cc:defs.bzl",
    "cc_library",
)

cc_library(
    name = "order",
    hdrs = ["order.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = ["@nlohmann_json//:json"],
)

cc_library(
    name = "problem",
    hdrs = ["problem.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [":order"],
)

cc_library(
    name = "client",
    srcs = ["client.cpp"],
    hdrs = ["client.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        "//src/ledger:action",
        ":problem",
        "@abseil-cpp//absl/strings:string_view",
        "@cpr",
    ],
)