load(
    "@rules_cc//cc:defs.bzl",
    "cc_library",
)

cc_library(
    name = "constants",
    hdrs = ["constants.h"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        "@nlohmann_json//:json",
    ],
)
