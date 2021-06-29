#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "selection_sort.h"
#include "sorting_test_util.h"

SORTING_TEST_ASCENDING(selection_sort);
SORTING_TEST_HALF_ASCENDING(selection_sort);
SORTING_TEST_DESCENDING(selection_sort);
SORTING_TEST_HALF_DESCENDING(selection_sort);
SORTING_TEST_RANDOM(selection_sort);
SORTING_TEST_DENSE_RANDOM(selection_sort);
SORTING_TEST_BINARY_RANDOM(selection_sort);
SORTING_TEST_BINARY_SORTED_LAST10PRANDOM(selection_sort);
