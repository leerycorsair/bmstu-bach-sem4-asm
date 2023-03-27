#define _POSIX_C_SOURCE 199309L
#include "check_time.h"

double check_time(dot_t dot1, dot_t dot2, float (*func)(dot_t *, dot_t *))
{
    float result;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t t = 0; t < ITERATIONS; t++)
        result = func(&dot1, &dot2);
    clock_gettime(CLOCK_MONOTONIC, &stop);

    time_t seconds = (stop.tv_sec - start.tv_sec);
    long nanoseconds = (seconds * NSEC_IN_SEC + stop.tv_nsec) - start.tv_nsec;

    return (double)nanoseconds / ITERATIONS;
}
