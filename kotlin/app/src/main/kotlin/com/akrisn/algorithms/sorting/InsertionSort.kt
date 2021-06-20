package com.akrisn.algorithms.sorting

fun insertionSort(arr: IntArray) {
    for (i in 1 until arr.size) {
        val tmp = arr[i]
        if (arr[i - 1] > tmp) {
            var j = i
            do {
                arr[j] = arr[j - 1]
                --j;
            } while (j > 0 && arr[j - 1] > tmp)
            arr[j] = tmp
        }
    }
}
