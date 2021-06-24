load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "sorting",
    srcs = [
      "bubble_sort.cc",
      "selection_sort.cc",
    ],
    hdrs = [
      "bubble_sort.h",
      "selection_sort.h",
    ],
)

cc_library(
    name = "sorting_test_util",
    srcs = ["sorting_test_util.cc"],
    hdrs = ["sorting_test_util.h"],
)

cc_binary(
  name = "bubble_sort_benchmark",
  srcs = ["bubble_sort_benchmark.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "selection_sort_benchmark",
  srcs = ["selection_sort_benchmark.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_test(
  name = "sorting_test",
  size = "small",
  srcs = [
    "bubble_sort_test.cc",
    "selection_sort_test.cc",
  ],
  deps = [
      ":sorting",
      ":sorting_test_util",
      "@com_google_googletest//:gtest_main",
      ],
)
