load(
    "@rules_cc//cc:defs.bzl",
    "cc_binary",
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    # We define the visibilty explicitly,
    # so it can be accessed from other packages.
    # https://bazel.build/concepts/visibility
    visibility = ["//visibility:public"],
    deps = [
        "//src/client",
        "//src/ledger:action",
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
        "@abseil-cpp//absl/log:log",
    ],
)
