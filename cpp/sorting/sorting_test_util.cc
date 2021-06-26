#include "sorting_test_util.h"

#include <iostream>


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

int* half_ascending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i / 2;
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

int* half_descending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = (n - i - 1) / 2;
    }
    return arr;
}

int* random_array(int n, std::mt19937& mt) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = mt();
    }
    return arr;
}

int* dense_random_array(int n, std::mt19937& mt) {
    std::uniform_int_distribution<> dist(0, n - 1);
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(mt);
    }
    return arr;
}
