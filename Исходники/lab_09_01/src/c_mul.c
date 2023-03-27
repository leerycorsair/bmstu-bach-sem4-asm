#define _POSIX_C_SOURCE 199309L
#include "c_mul.h"

double c_float_mul(float num1, float num2)
{
    float result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        result = num1 * num2;
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}

double c_double_mul(double num1, double num2)
{
    double result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        result = num1 * num2;
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}

#ifndef MNO
double c_long_double_mul(long double num1, long double num2)
{
    long double result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < REPEATS; t++)
        result = num1 * num2;
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / REPEATS;
}
#endif