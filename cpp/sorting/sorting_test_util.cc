#include "sorting_test_util.h"

#include <iostream>
#include <random>


void print_array(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* ascending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    return arr;
}


int* descending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i - 1;
    }
    return arr;
}


int* random_array(int n) {
    std::mt19937 mt;
    mt.seed(mt.default_seed);
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = mt();
    }
    return arr;
}
