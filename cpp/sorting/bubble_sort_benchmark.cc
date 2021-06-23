#include <benchmark/benchmark.h>

#include "bubble_sort.h"
#include "sorting_test_util.h"


static void BM_BubbleSortAsc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = ascending_array(n);
        state.ResumeTiming();

        bubble_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    //state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    state.SetComplexityN(n);
}

BENCHMARK(BM_BubbleSortAsc)
    ->RangeMultiplier(2)->Range(8, 8<<12)
    ->Complexity([](benchmark::IterationCount n)->double{return n * n;});

BENCHMARK_MAIN();
