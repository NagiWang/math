#include "../src/math.hpp"
#include <benchmark/benchmark.h>

// static void System_Log(benchmark::State& state) {
//     // Code inside this loop is measured repeatedly
//     for (auto _ : state) {
//         for (int j = 0; j < 100; j++) {
//             auto res = std::log(j);
//             benchmark::DoNotOptimize(res);
//         }
//     }
// }
// BENCHMARK(System_Log);

static void Simple_Log(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = ln_simple(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Simple_Log);

static void TMP_Log(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = Ln<double>::evaluate(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(TMP_Log);

static void Asm_Log(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 100; j++) {
            auto res = ln_asm(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Asm_Log);

BENCHMARK_MAIN();
