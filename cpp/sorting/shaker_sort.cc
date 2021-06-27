#include "shaker_sort.h"

void shaker_sort(int *arr, int n) {
    if (n == 0) return;

    int left = 0;
    int right = n - 1;

    while (true) {
        int last = left;

        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                last = i;
            }
        }
        right = last;

        if (left == right) {
            break;
        }

        for (int i = right; i > left; --i) {
            if (arr[i -1] > arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                last = i;
            }
        }
        left = last;

        if (left == right) {
            break;
        }
    }
}
