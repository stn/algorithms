#include <random>

#include <benchmark/benchmark.h>

#include "quick_sort.h"
#include "sorting_test_util.h"


static void BM_QuickSort3Asc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = ascending_array(n);
        state.ResumeTiming();

        quick_sort3(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

static void BM_QuickSort3Desc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = descending_array(n);
        state.ResumeTiming();

        quick_sort3(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

static void BM_QuickSort3Random(benchmark::State& state) {
    const int n = state.range(0);

    std::mt19937 mt;
    mt.seed(mt.default_seed);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = random_array(n, mt);
        state.ResumeTiming();

        quick_sort3(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

BENCHMARK(BM_QuickSort3Asc)
    ->RangeMultiplier(2)->Range(8, 8<<12);

BENCHMARK(BM_QuickSort3Desc)
    ->RangeMultiplier(2)->Range(8, 8<<12);

BENCHMARK(BM_QuickSort3Random)
    ->RangeMultiplier(2)->Range(8, 8<<12);

// $ bazel run //sorting:quick_sort_benchmark3 --compilation_mode=opt
BENCHMARK_MAIN();
