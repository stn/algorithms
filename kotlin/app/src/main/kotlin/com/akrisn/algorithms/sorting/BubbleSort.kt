package com.akrisn.algorithms.sorting

fun bubbleSort(arr: IntArray) {
    for (i in 0 until (arr.size - 1)) {
        for (j in 0 until (arr.size - i - 1)) {
            if (arr[j] > arr[j + 1]) {
                val tmp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = tmp
            }
        }
    }
}
