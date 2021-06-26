#ifndef SORTING_TEST_UTIL_H_
#define SORTING_TEST_UTIL_H_

#include <random>

void print_array(int* arr, int n);

int* ascending_array(int n);
int* half_ascending_array(int n);
int* descending_array(int n);
int* half_descending_array(int n);
int* random_array(int n, std::mt19937& mt);
int* dense_random_array(int n, std::mt19937& mt);

#define SORTING_TEST_ASCENDING(sort) \
TEST(sort ## _test, AscendingArray) { \
    int* arr0 = {}; \
    sort(arr0, 0); \
    for (int i = 1; i < 10; ++i) { \
        int* arr = ascending_array(i); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i; ++j) { \
            EXPECT_EQ(j, arr[j]); \
        } \
        delete arr; \
    } \
}

#define SORTING_TEST_HALF_ASCENDING(sort) \
TEST(sort ## _test, HalfAscendingArray) { \
    int* arr0 = {}; \
    sort(arr0, 0); \
    for (int i = 1; i < 10; ++i) { \
        int* arr = half_ascending_array(i); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i; ++j) { \
            EXPECT_EQ(j / 2, arr[j]); \
        } \
        delete arr; \
    } \
}

#define SORTING_TEST_DESCENDING(sort) \
TEST(sort ## _test, DescendingArray) { \
    for (int i = 1; i < 10; ++i) { \
        int* arr = descending_array(i); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i; ++j) { \
            EXPECT_EQ(j, arr[j]); \
        } \
        delete arr; \
    } \
}

#define SORTING_TEST_HALF_DESCENDING(sort) \
TEST(sort ## _test, HalfDescendingArray) { \
    for (int i = 1; i < 10; ++i) { \
        int* arr = half_descending_array(i); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i; ++j) { \
            EXPECT_EQ(j / 2, arr[j]); \
        } \
        delete arr; \
    } \
}

#define SORTING_TEST_RANDOM(sort) \
TEST(sort ## _test, RandomArray) { \
    std::mt19937 mt; \
    mt.seed(mt.default_seed); \
    for (int i = 1; i < 10; ++i) { \
        int* arr = random_array(i, mt); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i - 1; ++j) { \
            EXPECT_TRUE(arr[j] <= arr[j + 1]); \
        } \
        delete arr; \
    } \
}

#define SORTING_TEST_DENSE_RANDOM(sort) \
TEST(sort ## _test, DenseRandomArray) { \
    std::mt19937 mt; \
    mt.seed(mt.default_seed); \
    for (int i = 1; i < 10; ++i) { \
        int* arr = dense_random_array(i, mt); \
        /* print_array(arr, i); */ \
        sort(arr, i); \
        /* print_array(arr, i); */ \
        for (int j = 0; j < i - 1; ++j) { \
            EXPECT_TRUE(arr[j] <= arr[j + 1]); \
        } \
        delete arr; \
    } \
}

#endif // SORTING_TEST_UTIL_H_
