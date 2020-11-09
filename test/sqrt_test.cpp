#include "../src/math.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

int main()
{
    std::cout.setf(std::ios::fixed);
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    int ep = 16;
    int num;
    std::cout << "Input numsber: ";
    std::cin >> num;

    double a;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        a = std::sqrt(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "System    Sqrt(" << num << ") = "
              << std::setprecision(ep) << a
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double b;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        b = sqrt_bisection(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Bisection Sqrt(" << num << ") = "
              << std::setprecision(ep) << b
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double c;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        c = sqrt_newton(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Newton    Sqrt(" << num << ") = "
              << std::setprecision(ep) << c
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double d;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        d = C_sqrt(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Carmack   Sqrt(" << num << ") = "
              << std::setprecision(ep) << d
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double e;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        e = sqrt_asm(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << std::setprecision(2)
              << "Asm       Sqrt(" << num << ") = "
              << std::setprecision(ep) << e
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";
}
