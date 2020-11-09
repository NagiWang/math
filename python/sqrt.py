import numpy as np
import matplotlib.pyplot as plt


def sqrt_bisection(A):
    assert (A > 0)
    low = 0
    high = A
    mid = (low + high) * 0.5
    square = mid * mid
    t = 0
    time = [t]
    mids = [mid]
    lh = [float(high - low) * 0.5]
    errs = [float(A - square)]
    sqs = [square]
    while abs(square - A) > 2e-2:
        t += 1
        if square > A:
            high = mid
        else:
            low = mid
        mid = (low + high) * 0.5
        square = mid * mid
        time.append(t)
        mids.append(mid)
        lh.append(float(high - low) * 0.5)
        sqs.append(square)
        errs.append(float(A - square))

    fig, (ax0, ax1) = plt.subplots(nrows=2, sharex=True)
    ax0.errorbar(time, sqs, yerr=errs, linestyle='dotted', fmt='-o')
    ax0.set_yscale('log')
    ax0.set_xlabel('Step')
    ax0.set_ylabel('Sqrt')

    ax1.errorbar(time, mids, yerr=lh, linestyle='dotted', fmt='o')
    # ax1.set_yscale('log')
    ax1.set_ylabel('X')
    ax1.set_xlabel('Step')
    plt.show()


def sqrt_newton(A):
    assert (A > 0)
    xn = A * 0.5
    square = xn * xn
    t = 0
    time = [t]
    mids = [xn]
    errs = [float(A - square)]
    sqs = [square]
    while abs(square - A) > 1e-6:
        t += 1
        xn = (xn + A / xn) * 0.5
        square = xn * xn
        time.append(t)
        mids.append(xn)
        sqs.append(square)
        errs.append(float(A - square))

    errs = np.sqrt(np.abs(errs))

    fig, (ax0, ax1) = plt.subplots(nrows=2, sharex=True)
    ax0.errorbar(time, sqs, yerr=errs**2, linestyle='dotted', fmt='-o')
    ax0.set_yscale('log')
    ax0.set_xlabel('Step')
    ax0.set_ylabel('Sqrt')

    ax1.errorbar(time, mids, yerr=errs, linestyle='dotted', fmt='o')
    ax1.set_ylabel('X')
    ax1.set_xlabel('Step')
    plt.show()


if __name__ == "__main__":
    sqrt_bisection(1000)
    # sqrt_newton(1000)
