#include <random>

#include <benchmark/benchmark.h>

#include "shaker_sort.h"
#include "sorting_test_util.h"


static void BM_ShakerSortAsc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = ascending_array(n);
        state.ResumeTiming();

        shaker_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

static void BM_ShakerSortDesc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = descending_array(n);
        state.ResumeTiming();

        shaker_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

static void BM_ShakerSortRandom(benchmark::State& state) {
    const int n = state.range(0);

    std::mt19937 mt;
    mt.seed(mt.default_seed);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = random_array(n, mt);
        state.ResumeTiming();

        shaker_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    //state.SetComplexityN(n);
}

BENCHMARK(BM_ShakerSortAsc)
    ->RangeMultiplier(2)->Range(8, 8<<12);

BENCHMARK(BM_ShakerSortDesc)
    ->RangeMultiplier(2)->Range(8, 8<<12);

BENCHMARK(BM_ShakerSortRandom)
    ->RangeMultiplier(2)->Range(8, 8<<12);

// $ bazel run //sorting:shaker_sort_benchmark --compilation_mode=opt
BENCHMARK_MAIN();
