load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "sorting",
    srcs = ["bubble_sort.cc"],
    hdrs = ["bubble_sort.h"],
)

cc_test(
  name = "sorting_test",
  size = "small",
  srcs = ["bubble_sort_test.cc"],
  deps = [
      "@com_google_googletest//:gtest_main",
      ":sorting",
      ],
)
