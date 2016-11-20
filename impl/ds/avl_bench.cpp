#include "avl.hpp"
#include <benchmark/benchmark.h>
#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(-1e9, 1e9);
static void BM_get_num(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(dist(gen));
    }
}
BENCHMARK(BM_get_num);

static void BM_avl_create(benchmark::State &state) {
    while (state.KeepRunning()) {
        AVL_tree<int> tree;
        benchmark::DoNotOptimize(tree.size());
    }
}
BENCHMARK(BM_avl_create);

static void BM_avl_insert(benchmark::State &state) {
    while (state.KeepRunning()) {
        AVL_tree<int> tree;
        tree.insert(1);
        benchmark::DoNotOptimize(tree.size());
    }
}
BENCHMARK(BM_avl_insert);

BENCHMARK_MAIN();
