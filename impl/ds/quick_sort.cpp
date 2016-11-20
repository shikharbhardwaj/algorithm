#include "qsort.hpp"
#include <algorithm>
#include <benchmark/benchmark.h>
#include <iostream>
#include <limits>
#include <random>
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(),
                                        std::numeric_limits<int>::max());
const int n = 1000000;
static void fill_vec(benchmark::State &state) {
    while (state.KeepRunning()) {
        int *x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = dist(gen);
        }
        delete[] x;
    }
}
static void qsort1(benchmark::State &state) {
    while (state.KeepRunning()) {
        int *x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = dist(gen);
        }
        qsort1(x, 0, n - 1);
        delete[] x;
    }
}
static void qsort2(benchmark::State &state) {
    while (state.KeepRunning()) {
        int *x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = dist(gen);
        }
        qsort2(x, 0, n - 1);
        delete[] x;
    }
}

static void qsort3(benchmark::State &state) {
    while (state.KeepRunning()) {
        int *x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = dist(gen);
        }
        qsort3(x, 0, n - 1);
        delete[] x;
    }
}

static void std_sort(benchmark::State &state) {
    while (state.KeepRunning()) {
        int *x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = dist(gen);
        }
        std::sort(x, x + n);
        delete[] x;
    }
}
BENCHMARK(fill_vec);
BENCHMARK(qsort1);
BENCHMARK(qsort2);
BENCHMARK(qsort3);
BENCHMARK(std_sort);

BENCHMARK_MAIN();
