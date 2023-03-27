
#ifndef __ASM_MUL_H__
#define __ASM_MUL_H__

#include <stdlib.h>
#include <time.h>

#include "defines.h"

double asm_float_mul(float num1, float num2);

double asm_double_mul(double num1, double num2);

#ifndef MNO
double asm_long_double_mul(long double num1, long double num2);
#endif

#endif // __ASM_MUL_H__