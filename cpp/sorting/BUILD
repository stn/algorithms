load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "sorting",
    srcs = [
      "bubble_sort.cc",
      "insertion_sort.cc",
      "quick_sort.cc",
      "selection_sort.cc",
      "shaker_sort.cc",
      "shell_sort.cc",
    ],
    hdrs = [
      "bubble_sort.h",
      "insertion_sort.h",
      "quick_sort.h",
      "selection_sort.h",
      "shaker_sort.h",
      "shell_sort.h",
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
  name = "bubble_sort_benchmark2",
  srcs = ["bubble_sort_benchmark2.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "insertion_sort_benchmark",
  srcs = ["insertion_sort_benchmark.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "insertion_sort_benchmark2",
  srcs = ["insertion_sort_benchmark2.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "insertion_sort_benchmark3",
  srcs = ["insertion_sort_benchmark3.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "quick_sort_benchmark",
  srcs = ["quick_sort_benchmark.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "quick_sort_benchmark2",
  srcs = ["quick_sort_benchmark2.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "quick_sort_benchmark3",
  srcs = ["quick_sort_benchmark3.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "quick_sort_3part_benchmark",
  srcs = ["quick_sort_3part_benchmark.cc"],
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

cc_binary(
  name = "shaker_sort_benchmark",
  srcs = ["shaker_sort_benchmark.cc"],
  deps = [
    ":sorting",
    ":sorting_test_util",
    "@com_github_google_benchmark//:benchmark_main"
  ]
)

cc_binary(
  name = "shell_sort_benchmark",
  srcs = ["shell_sort_benchmark.cc"],
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
    "insertion_sort_test.cc",
    "quick_sort_test.cc",
    "selection_sort_test.cc",
    "shaker_sort_test.cc",
    "shell_sort_test.cc",
  ],
  deps = [
      ":sorting",
      ":sorting_test_util",
      "@com_google_googletest//:gtest_main",
      ],
)
