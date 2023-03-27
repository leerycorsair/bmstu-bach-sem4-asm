#include "comparator.h"

void float_cmp(float num1, float num2)
{
    double asm_add_time = asm_float_add(num1, num2);
    double c_add_time = c_float_add(num1, num2);

    printf("ASM Float Add Time = %lf\n", asm_add_time);
    printf("C Float Add Time = %lf\n", c_add_time);

    printf("\n");

    double asm_mul_time = asm_float_mul(num1, num2);
    double c_mul_time = c_float_mul(num1, num2);

    printf("ASM Float Mul Time = %lf\n", asm_mul_time);
    printf("C Float Mul Time = %lf\n", c_mul_time);

    printf("\n");
}

void double_cmp(double num1, double num2)
{
    double asm_add_time = asm_double_add(num1, num2);
    double c_add_time = c_double_add(num1, num2);

    printf("ASM Double Add Time = %lf\n", asm_add_time);
    printf("C Double Add Time = %lf\n", c_add_time);

    printf("\n");

    double asm_mul_time = asm_double_mul(num1, num2);
    double c_mul_time = c_double_mul(num1, num2);

    printf("ASM Double Add Time = %lf\n", asm_mul_time);
    printf("C Double Add Time = %lf\n", c_mul_time);

    printf("\n");
}

#ifndef MNO
void long_double_cmp(double num1, double num2)
{
    double asm_add_time = asm_long_double_add(num1, num2);
    double c_add_time = c_long_double_add(num1, num2);

    printf("ASM Long Double Add Time = %lf\n", asm_add_time);
    printf("C Long Double Add Time = %lf\n", c_add_time);

    printf("\n");

    double asm_mul_time = asm_long_double_mul(num1, num2);
    double c_mul_time = c_long_double_mul(num1, num2);

    printf("ASM Long Double Mul Time = %lf\n", asm_mul_time);
    printf("C Long Double Mul Time = %lf\n", c_mul_time);

    printf("\n");
}
#endif