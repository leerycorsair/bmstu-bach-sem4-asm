#ifndef __CHECK_TIME_H__
#define __CHECK_TIME_H__

#include <time.h>

#include "dot.h"

#define ITERATIONS 1000000

#define NSEC_IN_SEC 100000000

double check_time(dot_t dot1, dot_t dot2, float (*func)(dot_t *, dot_t *));

#endif //__CHECK_TIME_H__