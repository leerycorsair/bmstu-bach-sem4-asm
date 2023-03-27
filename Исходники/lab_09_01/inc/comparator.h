#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include <stdio.h>

#include "asm_add.h"
#include "asm_mul.h"

#include "c_add.h"
#include "c_mul.h"

void float_cmp(float num1, float num2);

void double_cmp(double num1, double num2);

#ifndef MNO
void long_double_cmp(double num1, double num2);
#endif

#endif // __COMPARATOR_H__