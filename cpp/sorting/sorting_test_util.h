#ifndef SORTING_TEST_UTIL_H_
#define SORTING_TEST_UTIL_H_

#include <random>

void print_array(int* arr, int n);

int* ascending_array(int n);
int* descending_array(int n);
int* random_array(int n, std::mt19937& mt);

#endif // SORTING_TEST_UTIL_H_
