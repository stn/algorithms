#include "insertion_sort.h"

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void insertion_sort2(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        // search the position where the value is smaller than or equals to tmp.
        int j;
        for (j = i; j > 0; --j) {
            if (arr[j - 1] <= tmp) {
                break;
            }
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

void insertion_sort3(int *arr, int n) {
    if (n == 0) return;

    int min_pos = n - 1;
    for (int i = n - 1; i > 0; --i) {
        if (arr[i - 1] < arr[min_pos]) {
            min_pos = i - 1;
        }
    }
    int tmp = arr[min_pos];
    arr[min_pos] = arr[0];
    arr[0] = tmp;

    for (int i = 2; i < n; ++i) {
        int tmp = arr[i];
        // search the position where the value is smaller than or equals to tmp.
        int j = i;
        while (tmp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = tmp;
    }
}
