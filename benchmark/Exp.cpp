#include "../src/math.hpp"
#include <benchmark/benchmark.h>

// static void System_Exp(benchmark::State& state) {
//     // Code inside this loop is measured repeatedly
//     for (auto _ : state) {
//         for (int j = 0; j < 100; j++) {
//             auto res = std::exp(j);
//             benchmark::DoNotOptimize(res);
//         }
//     }
// }
// BENCHMARK(System_Exp);

static void Simple_Exp(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = exp_simple(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Simple_Exp);

static void TMPv1_Exp(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = Expv1<double>::evaluate(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(TMPv1_Exp);

static void TMPv2_Exp(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = Expv2<double>::evaluate(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(TMPv2_Exp);

BENCHMARK_MAIN();
