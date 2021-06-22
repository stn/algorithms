#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "bubble_sort.h"
#include "sorting_test_util.h"


TEST(BubbleSortTest, AscendingArray) {
    int* arr0 = {};
    bubble_sort(arr0, 0);
    //EXPECT_THAT(arr0, ElementsAre());

    for (int i = 1; i < 10; ++i) {
        int* arr = ascending_array(i);
        //print_array(arr, i);
        bubble_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(BubbleSortTest, DescendingArray) {
    for (int i = 1; i < 10; ++i) {
        int* arr = descending_array(i);
        //print_array(arr, i);
        bubble_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(BubbleSortTest, RandomArray) {
    for (int i = 1; i < 10; ++i) {
        int* arr = random_array(i);
        //print_array(arr, i);
        bubble_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i - 1; ++j) {
            EXPECT_TRUE(arr[j] <= arr[j + 1]);
        }
        delete arr;
    }
}
