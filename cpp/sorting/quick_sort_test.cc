#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "quick_sort.h"
#include "sorting_test_util.h"

SORTING_TEST_ASCENDING(quick_sort);
SORTING_TEST_HALF_ASCENDING(quick_sort);
SORTING_TEST_DESCENDING(quick_sort);
SORTING_TEST_HALF_DESCENDING(quick_sort);
SORTING_TEST_RANDOM(quick_sort);
SORTING_TEST_DENSE_RANDOM(quick_sort);
SORTING_TEST_BINARY_RANDOM(quick_sort);
SORTING_TEST_BINARY_SORTED_LAST10PRANDOM(quick_sort);

SORTING_TEST_ASCENDING(quick_sort2);
SORTING_TEST_HALF_ASCENDING(quick_sort2);
SORTING_TEST_DESCENDING(quick_sort2);
SORTING_TEST_HALF_DESCENDING(quick_sort2);
SORTING_TEST_RANDOM(quick_sort2);
SORTING_TEST_DENSE_RANDOM(quick_sort2);
SORTING_TEST_BINARY_RANDOM(quick_sort2);
SORTING_TEST_BINARY_SORTED_LAST10PRANDOM(quick_sort2);
