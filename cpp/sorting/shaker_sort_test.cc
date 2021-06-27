#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shaker_sort.h"
#include "sorting_test_util.h"

SORTING_TEST_ASCENDING(shaker_sort);
SORTING_TEST_HALF_ASCENDING(shaker_sort);
SORTING_TEST_DESCENDING(shaker_sort);
SORTING_TEST_HALF_DESCENDING(shaker_sort);
SORTING_TEST_RANDOM(shaker_sort);
SORTING_TEST_DENSE_RANDOM(shaker_sort);
