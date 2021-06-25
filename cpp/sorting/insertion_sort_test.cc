#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "insertion_sort.h"
#include "sorting_test_util.h"


TEST(InsertionSortTest, AscendingArray) {
    int* arr0 = {};
    insertion_sort(arr0, 0);
    //EXPECT_THAT(arr0, ElementsAre());

    for (int i = 1; i < 10; ++i) {
        int* arr = ascending_array(i);
        //print_array(arr, i);
        insertion_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSortTest, DescendingArray) {
    for (int i = 1; i < 10; ++i) {
        int* arr = descending_array(i);
        //print_array(arr, i);
        insertion_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSortTest, RandomArray) {
    std::mt19937 mt;
    mt.seed(mt.default_seed);
    for (int i = 1; i < 10; ++i) {
        int* arr = random_array(i, mt);
        //print_array(arr, i);
        insertion_sort(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i - 1; ++j) {
            EXPECT_TRUE(arr[j] <= arr[j + 1]);
        }
        delete arr;
    }
}


// Insertion Sort 2

TEST(InsertionSort2Test, AscendingArray) {
    int* arr0 = {};
    insertion_sort2(arr0, 0);
    //EXPECT_THAT(arr0, ElementsAre());

    for (int i = 1; i < 10; ++i) {
        int* arr = ascending_array(i);
        //print_array(arr, i);
        insertion_sort2(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSort2Test, DescendingArray) {
    for (int i = 1; i < 10; ++i) {
        int* arr = descending_array(i);
        //print_array(arr, i);
        insertion_sort2(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSort2Test, RandomArray) {
    std::mt19937 mt;
    mt.seed(mt.default_seed);
    for (int i = 1; i < 10; ++i) {
        int* arr = random_array(i, mt);
        //print_array(arr, i);
        insertion_sort2(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i - 1; ++j) {
            EXPECT_TRUE(arr[j] <= arr[j + 1]);
        }
        delete arr;
    }
}

// Insertion Sort 3

TEST(InsertionSort3Test, AscendingArray) {
    int* arr0 = {};
    insertion_sort3(arr0, 0);
    //EXPECT_THAT(arr0, ElementsAre());

    for (int i = 1; i < 10; ++i) {
        int* arr = ascending_array(i);
        //print_array(arr, i);
        insertion_sort3(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSort3Test, DescendingArray) {
    for (int i = 1; i < 10; ++i) {
        int* arr = descending_array(i);
        //print_array(arr, i);
        insertion_sort3(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i; ++j) {
            EXPECT_EQ(j, arr[j]);
        }
        delete arr;
    }
}

TEST(InsertionSort3Test, RandomArray) {
    std::mt19937 mt;
    mt.seed(mt.default_seed);
    for (int i = 1; i < 10; ++i) {
        int* arr = random_array(i, mt);
        //print_array(arr, i);
        insertion_sort3(arr, i);
        //print_array(arr, i);
        for (int j = 0; j < i - 1; ++j) {
            EXPECT_TRUE(arr[j] <= arr[j + 1]);
        }
        delete arr;
    }
}
