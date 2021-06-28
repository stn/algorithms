#include "quick_sort.h"

int partition(int* arr, int l, int r) {
    int i = l - 1;
    int j = r;
    int v = arr[r];
    while (true) {
        while (arr[++i] < v);
        while (v < arr[--j]) {
            if (j == l) break;
        }
        if (i >= j) break;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    arr[r] = arr[i];
    arr[i] = v;
    return i;
}

void quick_sort_sub(int *arr, int l, int r) {
    if (r <= l) return;
    int i = partition(arr, l, r);
    quick_sort_sub(arr, l, i - 1);
    quick_sort_sub(arr, i + 1, r);
}

void quick_sort(int *arr, int n) {
    quick_sort_sub(arr, 0, n - 1);
}
