#include "shell_sort.h"

void shell_sort(int *arr, int n) {
    // Knuth series
    int h = 1;
    while (h <= n / 9) {
        h = 3 * h + 1;
    }
    for (; h > 0; h /= 3) {
        for (int i = h; i < n; ++i) {
            int v = arr[i];
            int j;
            for (j = i; j >= h && v < arr[j - h]; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = v;
        }
    }
}

// TODO: use guard
// TODO: r->l, l->r like insertion_sort3

