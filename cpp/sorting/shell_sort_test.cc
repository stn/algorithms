#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shell_sort.h"
#include "sorting_test_util.h"


SORTING_TEST_ASCENDING(shell_sort);
SORTING_TEST_HALF_ASCENDING(shell_sort);
SORTING_TEST_DESCENDING(shell_sort);
SORTING_TEST_HALF_DESCENDING(shell_sort);
SORTING_TEST_RANDOM(shell_sort);
SORTING_TEST_DENSE_RANDOM(shell_sort);
SORTING_TEST_BINARY_RANDOM(shell_sort);
SORTING_TEST_BINARY_SORTED_LAST10PRANDOM(shell_sort);
