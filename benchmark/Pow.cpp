#include "../src/math.hpp"
#include <benchmark/benchmark.h>

const int A = 3;

// static void System_Pow(benchmark::State& state) {
//     // Code inside this loop is measured repeatedly
//     for (auto _ : state) {
//         for (int j = 0; j < 100; j++) {
//             auto res = std::pow(A, j);
//             benchmark::DoNotOptimize(res);
//         }
//     }
// }
// BENCHMARK(System_Pow);

static void Simple_Pow(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = pow_simple(A, j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Simple_Pow);

static void Fast_Pow(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = pow_fast(A, j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Fast_Pow);

BENCHMARK_MAIN();
