package com.akrisn.algorithms.sorting

import kotlin.test.Test
import kotlin.test.assertContentEquals

class BubbleSortTest {
    @Test
    fun testBubbleSort() {
        val arr0 = intArrayOf()
        bubbleSort(arr0)
        assertContentEquals(intArrayOf(), arr0)

        val arr1 = intArrayOf(1)
        bubbleSort(arr1)
        assertContentEquals(intArrayOf(1), arr1)

        val arr2 = intArrayOf(2, 1)
        bubbleSort(arr2)
        assertContentEquals(intArrayOf(1, 2), arr2)

        val arr5 = intArrayOf(5, 4, 3, 2, 1)
        bubbleSort(arr5)
        assertContentEquals(intArrayOf(1, 2, 3, 4, 5), arr5)
    }
}
