#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "bubble_sort.h"
#include "sorting_test_util.h"

SORTING_TEST_ASCENDING(bubble_sort);
SORTING_TEST_HALF_ASCENDING(bubble_sort);
SORTING_TEST_DESCENDING(bubble_sort);
SORTING_TEST_HALF_DESCENDING(bubble_sort);
SORTING_TEST_RANDOM(bubble_sort);
SORTING_TEST_DENSE_RANDOM(bubble_sort);

SORTING_TEST_ASCENDING(bubble_sort2);
SORTING_TEST_HALF_ASCENDING(bubble_sort2);
SORTING_TEST_DESCENDING(bubble_sort2);
SORTING_TEST_HALF_DESCENDING(bubble_sort2);
SORTING_TEST_RANDOM(bubble_sort2);
SORTING_TEST_DENSE_RANDOM(bubble_sort2);
