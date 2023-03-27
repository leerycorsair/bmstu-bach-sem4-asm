
#ifndef __C_ADD_H__
#define __C_ADD_H__

#include <stdlib.h>
#include <time.h>

#include "defines.h"

double c_float_add(float num1, float num2);

double c_double_add(double num1, double num2);

#ifndef MNO
double c_long_double_add(long double num1, long double num2);
#endif

#endif // __C_ADD_H__