#define _POSIX_C_SOURCE 199309L
#include "asm_mul.h"

double asm_float_mul(float num1, float num2)
{
    float result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        __asm__("fld %0\n"
                "fld %1\n"
                "fmulp\n"
                "fstp %2\n" ::"m"(num1),
                "m"(num2), "m"(result));
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}

double asm_double_mul(double num1, double num2)
{
    double result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        __asm__("fld %0\n"
                "fld %1\n"
                "fmulp\n"
                "fstp %2\n" ::"m"(num1),
                "m"(num2), "m"(result));
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}

#ifndef MNO
double asm_long_double_mul(long double num1, long double num2)
{
    long double result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        __asm__("fld %0\n"
                "fld %1\n"
                "fmulp\n"
                "fstp %2\n" ::"m"(num1),
                "m"(num2), "m"(result));
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}
#endif