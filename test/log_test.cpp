#include "../src/math.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>



int main() {
    std::cout.setf(std::ios::fixed);
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    // double A = 100000;
    int ep = 16;
    int num;
    std::cout << "Input numsber: ";
    std::cin >> num;

    double a;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        a = std::log(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "System Ln(" << num << ") = "
              << std::setprecision(ep) << a
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double b;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        b = ln_simple(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Simple Ln(" << num << ") = "
              << std::setprecision(ep) << b
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double c;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        c = Ln<double>::evaluate(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "TMP    Ln(" << num << ") = "
              << std::setprecision(ep) << c
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double d;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++) {
        d = ln_asm(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Asm    Ln(" << num << ") = "
              << std::setprecision(ep) << d
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";
}
