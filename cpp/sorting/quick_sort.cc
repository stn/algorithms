#include "quick_sort.h"

#include "insertion_sort.h"


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


// quick sort 2

#define M 100

void quick_sort_sub2(int *arr, int l, int r) {
    if (r - l <= M) return;
    int i = partition(arr, l, r);
    quick_sort_sub2(arr, l, i - 1);
    quick_sort_sub2(arr, i + 1, r);
}

void quick_sort2(int *arr, int n) {
    quick_sort_sub2(arr, 0, n - 1);
    insertion_sort3(arr, n);
}

// quick sort 3

#define M 100

void quick_sort_sub3(int *arr, int l, int r) {
    if (r - l <= M) return;

    int m = (l + r) / 2;
    int tmp = arr[m];
    arr[m] = arr[r - 1];
    arr[r - 1] = tmp;

    if (arr[l] > arr[r - 1]) {
        //tmp = arr[r - 1];
        arr[r - 1] = arr[l];
        arr[l] = tmp;
    }

    if (arr[l] > arr[r]) {
        tmp = arr[r];
        arr[r] = arr[l];
        arr[l] = tmp;
    }

    if (arr[r - 1] > arr[r]) {
        tmp = arr[r];
        arr[r] = arr[r - 1];
        arr[r - 1] = tmp;
    }

    int i = partition(arr, l + 1, r - 1);
    quick_sort_sub3(arr, l, i - 1);
    quick_sort_sub3(arr, i + 1, r);
}

void quick_sort3(int *arr, int n) {
    quick_sort_sub3(arr, 0, n - 1);
    insertion_sort3(arr, n);
}

// quick sort 3 partitions

void quick_sort_3part_sub(int *arr, int l, int r) {
    if (r - l <= M) return;

    int m = (l + r) / 2;
    int tmp = arr[m];
    arr[m] = arr[r - 1];
    arr[r - 1] = tmp;

    if (arr[l] > arr[r - 1]) {
        //tmp = arr[r - 1];
        arr[r - 1] = arr[l];
        arr[l] = tmp;
    }

    if (arr[l] > arr[r]) {
        tmp = arr[r];
        arr[r] = arr[l];
        arr[l] = tmp;
    }

    if (arr[r - 1] < arr[r]) {
        tmp = arr[r];
        arr[r] = arr[r - 1];
        arr[r - 1] = tmp;
    }

    int i = l - 1;
    int p = l - 1;
    int j = r;
    int q = r;

    int v = arr[r];

    while (true) {
        while (arr[++i] < v);
        while (v < arr[--j]) if (j == l) break;
        if (i >= j) break;

        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        if (arr[i] == v) {
            ++p;
            tmp = arr[p];
            arr[p] = arr[i];
            arr[i] = tmp;
        }
        if (v == arr[j]) {
            --q;
            tmp = arr[q];
            arr[q] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i];
    arr[i] = arr[r];
    arr[r] = tmp;
    j = i - 1;
    i = i + 1;
    for (int k = l; k < p; ++k, --j) {
        tmp = arr[k];
        arr[k] = arr[j];
        arr[j] = tmp;
    }
    for (int k = r - 1; k > q; --k, ++i) {
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }

    quick_sort_3part_sub(arr, l, j);
    quick_sort_3part_sub(arr, i, r);
}

void quick_sort_3part(int *arr, int n) {
    quick_sort_3part_sub(arr, 0, n - 1);
    insertion_sort3(arr, n);
}
