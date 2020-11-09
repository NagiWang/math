#include "../src/math.hpp"
#include <benchmark/benchmark.h>

// static void System_Sin(benchmark::State& state) {
//     // Code inside this loop is measured repeatedly
//     for (auto _ : state) {
//         for (int j = 0; j < 1000; j++) {
//             auto res = std::sin(j);
//             benchmark::DoNotOptimize(res);
//         }
//     }
// }
// BENCHMARK(System_Sin);

static void Simple_Sin(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = sin_simple(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Simple_Sin);

static void Asm_Sin(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = sin_asm(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Asm_Sin);

BENCHMARK_MAIN();
