#include "../src/math.hpp"
#include <benchmark/benchmark.h>

// static void System_Sqrt(benchmark::State& state) {
//     // Code inside this loop is measured repeatedly
//     for (auto _ : state) {
//         for (int j = 0; j < 1000; j++) {
//             auto res = std::sqrt(j);
//             benchmark::DoNotOptimize(res);
//         }
//     }
// }
// BENCHMARK(System_Sqrt);

static void Bisection_Sqrt(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = sqrt_bisection(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Bisection_Sqrt);

static void Newton_Sqrt(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = sqrt_newton(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Newton_Sqrt);

static void Carmack_Sqrt(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = C_sqrt(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Carmack_Sqrt);

static void Asm_Sqrt(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    for (auto _ : state) {
        for (int j = 0; j < 1000; j++) {
            auto res = sqrt_asm(j);
            benchmark::DoNotOptimize(res);
        }
    }
}
BENCHMARK(Asm_Sqrt);

BENCHMARK_MAIN();
