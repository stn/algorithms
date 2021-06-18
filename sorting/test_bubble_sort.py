from bubble_sort import bubble_sort


def test_bubble_sort():
    assert bubble_sort([]) == []
    assert bubble_sort([1]) == [1]
    assert bubble_sort([2, 1]) == [1, 2]
    assert bubble_sort([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]


def test_bubble_sort_benchmark_1to100(benchmark):
    benchmark(bubble_sort, list(range(1, 101)))


def test_bubble_sort_benchmark_100to1(benchmark):
    benchmark(bubble_sort, list(range(100, 0, -1)))
