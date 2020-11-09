//
// Created by Senbon on 2020/11/6.
//

#ifndef MATH_SRC_MATH_HPP
#define MATH_SRC_MATH_HPP
#include <cassert>
#include <cmath>
#include <cstdint>

constexpr double epsilon = 1e-10f;
constexpr double E = 2.718281828459045;
constexpr double Pi = 3.141592653589793238;
constexpr double Ln10 = 2.30258509299404568;
constexpr double Ln2 = 0.69314718056;

using ull = unsigned long long;

double sin_simple(double A) {
    const int N = 50;
    A = std::fmod(A, 2 * Pi);
    double result = 0.0;
    double k = 1.0;
    double n;
    double x = A;
    double xx = A * A;
    for (int i = 1; i <= N; ++i) {
        if (i & 1)
            result += x / k;
        else
            result -= x / k;
        n = 2 * i - 1;
        k *= (n + 1) * (n + 2);
        x *= xx;
    }
    return result;
}

double sin_asm(double A) {
    asm volatile("fldl  %0;"
                 "fsin    ;"
                 "fstpl %0;"
                 : "+m"(A));
    return A;
}

double pow_simple(double A, int n) {
    double result = 1.0;
    while (n) {
        result *= A;
        --n;
    }
    return result;
}

double pow_fast(double A, int n) {
    double result = 1.0;
    while (n) {
        if (n & 1)
            result *= A;
        A *= A;
        n >>= 1;
    }
    return result;
}

double ln_simple(double A) {
    double x = (A - 1.0) / (A + 1.0);
    double xx = x * x;
    double k = 2.0 * 1000 + 1.0;
    double y = 0;
    while (k > 0.0) {
        y = 1.0 / k + xx * y;
        k -= 2.0;
    }
    return 2.0 * x * y;
}

double ln_asm(double x) {
    asm volatile("fldln2  ;"
                 "fldl  %0;"
                 "fyl2x   ;"
                 "fstpl %0;"
                 : "+m"(x));
    return x;
}

double log10_asm(double x) {
    asm volatile("fldlg2  ;"
                 "fldl  %0;"
                 "fyl2x   ;"
                 "fstpl %0;"
                 : "+m"(x));
    return x;
}

double log2_asm(double x) {
    asm volatile("fld1    ;"
                 "fldl  %0;"
                 "fyl2x   ;"
                 "fstpl %0;"
                 : "+m"(x));
    return x;
}

template <typename Real = double, ull degree = 1000, ull I = 1>
struct Atanh {
    static Real evaluate(Real x) {
        constexpr Real k = 1.0 / (2.0 * static_cast<Real>(I) - 1.0);
        x = k + x * x * Atanh<Real, degree, I + 1>::evaluate(x);
        return x;
    }
};

template <typename Real, ull degree>
struct Atanh<Real, degree, degree> {
    static Real evaluate(Real x) {
        constexpr Real k1 = 1.0 / (2.0 * static_cast<Real>(degree) - 1.0);
        constexpr Real k2 = 1.0 / (2.0 + k1);
        x *= x;
        x = k1 + x * k2;
        return x;
    }
};

template <typename Real = double, ull degree = 1000>
struct Ln {
    static Real evaluate(Real x) {
        Real A = (x - 1.0) / (x + 1.0);
        Real ln = 2 * A * Atanh<Real, degree>::evaluate(A);
        return ln;
    }
};

double log10_simple(double A) {
    return Ln<double>::evaluate(A) / Ln10;
}

double log(double A, double B) {
    return Ln<double>::evaluate(B) / Ln<double>::evaluate(A);
}

double sqrt_bisection(double A) {
    assert(A > 0);
    double low = 0, high = A;
    double mid = (low + high) * 0.5;
    double square = mid * mid;
    while (std::abs(square - A) > epsilon) {
        if (square > A)
            high = mid;
        else
            low = mid;
        mid = (low + high) * 0.5;
        square = mid * mid;
    }
    return mid;
}

double sqrt_newton(double A) {
    assert(A > 0);
    double xn = A * 0.5;
    double square = xn * xn;
    while (std::abs(square - A) > epsilon) {
        xn = (xn + A / xn) * 0.5;
        square = xn * xn;
    }
    return xn;
}

double C_sqrt(double A) {
    const double nhalf = (A * 0.5);
    int64_t i = *((int64_t*) &A);
    i = (0x1FF7A3BEA91D9B00 + (i >> 1));
    A = *((double*) &i);
    A *= (0.5 + ((nhalf / A) / A));
    A *= (0.5 + ((nhalf / A) / A));
    A *= (0.5 + ((nhalf / A) / A));
    return A;
}

double sqrt_asm(double A) {
    asm volatile("fldl  %0;"
                 "fsqrt   ;"
                 "fstpl %0;"
                 : "+m"(A));
    return A;
}

double exp_simple(double A) {
    const int degree = 1000;
    double k, z = 1.0;
    for (int i = degree; i > 0; --i) {
        k = 1.0 / static_cast<double>(i);
        z = 1.0 + k * A * z;
    }
    return z;
}

// g++ -O3 -ffast-math -funsafe-math-optimizations -msse4.2
template <typename Real = double, ull degree = 1000, ull I = 1>
struct Expv1 {
    static Real evaluate(Real x) {
        constexpr Real c = 1.0 / static_cast<Real>(I);
        x = 1.0 + c * x * Expv1<Real, degree, I + 1>::evaluate(x);
        return x;
    }
};

template <typename Real, ull degree>
struct Expv1<Real, degree, degree> {
    static Real evaluate(Real x) {
        constexpr Real c = 1.0 / static_cast<Real>(degree);
        x = 1.0 + c * x;
        return x;
    }
};

template <typename Real, ull degree = 50, ull i = 0>
struct Expv2 {
    static Real evaluate(Real x) {
        // constexpr Real c = 1.0 / static_cast<Real>(1ull << degree);
        x = Expv2<Real, degree, i + 1>::evaluate(x);
        return x * x;
    }
};

template <typename Real, ull degree>
struct Expv2<Real, degree, degree> {
    static Real evaluate(Real x) {
        constexpr Real c = 1.0 / static_cast<Real>(1ULL << degree);
        x = 1.0 + c * x;
        return x;
    }
};

using ull = unsigned long long;

template <typename Real, ull N>
constexpr Real Factorial = static_cast<Real>(N) * Factorial<Real, N - 1ULL>;

template <typename Real>
constexpr Real Factorial<Real, 0ULL> = static_cast<Real>(1.0);

// template <std::size_t N, typename Real>
// constexpr Real SinSeries = SinSeries<N+1>

#endif//MATH_SRC_MATH_HPP
