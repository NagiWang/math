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

    int ep = 10;
    int num;
    std::cout << "Input numsber: ";
    std::cin >> num;

    double a;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        a = std::exp(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "System Exp(" << num << ") = "
              << std::setprecision(ep) << a
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double b;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        b = exp_simple(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Simple Exp(" << num << ") = "
              << std::setprecision(ep) << b
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double c;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        c = Expv1<double>::evaluate(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "TMP v1 Exp(" << num << ") = "
              << std::setprecision(ep) << c
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";

    double d;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= num; i++)
    {
        d = Expv2<double>::evaluate(num);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "TMP v2 Exp(" << num << ") = "
              << std::setprecision(ep) << d
              << std::setprecision(10)
              << "\tTime: " << elapsed_seconds.count() * 1e6 << " ms\n";
}
