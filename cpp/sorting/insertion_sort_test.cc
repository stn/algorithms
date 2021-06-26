#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "insertion_sort.h"
#include "sorting_test_util.h"


SORTING_TEST_ASCENDING(insertion_sort);
SORTING_TEST_HALF_ASCENDING(insertion_sort);
SORTING_TEST_DESCENDING(insertion_sort);
SORTING_TEST_HALF_DESCENDING(insertion_sort);
SORTING_TEST_RANDOM(insertion_sort);
SORTING_TEST_DENSE_RANDOM(insertion_sort);

SORTING_TEST_ASCENDING(insertion_sort2);
SORTING_TEST_HALF_ASCENDING(insertion_sort2);
SORTING_TEST_DESCENDING(insertion_sort2);
SORTING_TEST_HALF_DESCENDING(insertion_sort2);
SORTING_TEST_RANDOM(insertion_sort2);
SORTING_TEST_DENSE_RANDOM(insertion_sort2);

SORTING_TEST_ASCENDING(insertion_sort3);
SORTING_TEST_HALF_ASCENDING(insertion_sort3);
SORTING_TEST_DESCENDING(insertion_sort3);
SORTING_TEST_HALF_DESCENDING(insertion_sort3);
SORTING_TEST_RANDOM(insertion_sort3);
SORTING_TEST_DENSE_RANDOM(insertion_sort3);
