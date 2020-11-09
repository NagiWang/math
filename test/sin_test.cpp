#include "../src/math.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

int main() {
    std::cout.setf(std::ios::fixed);
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    int ep = 16;
    double num;
    std::cout << "Input numsber: ";
    std::cin >> num;

    double a;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        a = std::sin(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "System Sin(" << num << ") = "
              << std::setprecision(ep) << a
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double b;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        b = sin_simple(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Simple Sin(" << num << ") = "
              << std::setprecision(ep) << b
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double c;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        c = sin_asm(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Asm    Sin(" << num << ") = "
              << std::setprecision(ep) << c
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";
}
