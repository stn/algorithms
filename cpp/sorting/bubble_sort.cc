#include "bubble_sort.h"

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void bubble_sort2(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void bubble_sort3(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool no_swap = true;
        for (int j = n - 1; j > i; --j) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                no_swap = false;
            }
        }
        if (no_swap) {
            // if no swap happens, we can stop.
            return;
        }
    }
}
