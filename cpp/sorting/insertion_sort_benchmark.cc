#include <random>

#include <benchmark/benchmark.h>

#include "insertion_sort.h"
#include "sorting_test_util.h"


static void BM_InsertionSortAsc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = ascending_array(n);
        state.ResumeTiming();

        insertion_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    //state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    state.SetComplexityN(n);
}

static void BM_InsertionSortDesc(benchmark::State& state) {
    const int n = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = descending_array(n);
        state.ResumeTiming();

        insertion_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    //state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    state.SetComplexityN(n);
}

static void BM_InsertionSortRandom(benchmark::State& state) {
    const int n = state.range(0);

    std::mt19937 mt;
    mt.seed(mt.default_seed);

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = random_array(n, mt);
        state.ResumeTiming();

        insertion_sort(arr, n);

        state.PauseTiming();
        delete arr;
        state.ResumeTiming();
    }
    //state.SetItemsProcessed(int64_t(state.iterations()) * int64_t(n));
    state.SetComplexityN(n);
}

BENCHMARK(BM_InsertionSortAsc)
    ->RangeMultiplier(2)->Range(8, 8<<12)
    ->Complexity([](benchmark::IterationCount n)->double{return n * n;});

BENCHMARK(BM_InsertionSortDesc)
    ->RangeMultiplier(2)->Range(8, 8<<12)
    ->Complexity([](benchmark::IterationCount n)->double{return n * n;});

BENCHMARK(BM_InsertionSortRandom)
    ->RangeMultiplier(2)->Range(8, 8<<12)
    ->Complexity([](benchmark::IterationCount n)->double{return n * n;});

// $ bazel run //sorting:insertion_sort_benchmark
BENCHMARK_MAIN();
