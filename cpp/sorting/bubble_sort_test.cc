#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::ElementsAre;

#include "bubble_sort.h"

TEST(BubbleSortTest, BasicTest) {
    int arr0[] = {};
    bubble_sort(arr0, 0);
    //EXPECT_THAT(arr0, ElementsAre());

    int arr1[] = {1};
    bubble_sort(arr1, 1);
    EXPECT_THAT(arr1, ElementsAre(1));

    int arr2[] = {2, 1};
    bubble_sort(arr2, 2);
    EXPECT_THAT(arr2, ElementsAre(1, 2));
}
