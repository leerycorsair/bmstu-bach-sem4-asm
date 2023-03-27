#include <stdio.h>
#include "my_sin.h"

int main()
{
    double sin_arg;
    double asm_value;
    double c_value;

    sin_arg = 3.14;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(%lf)=%lf\n", sin_arg, asm_value);
    printf("C_Sin(%lf)=%lf\n", sin_arg, c_value);

    sin_arg = 3.141596;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(%lf)=%lf\n", sin_arg, asm_value);
    printf("C_Sin(%lf)=%lf\n", sin_arg, c_value);

    sin_arg = 3.14 / 2;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(%lf)=%lf\n", sin_arg, asm_value);
    printf("C_Sin(%lf)=%lf\n", sin_arg, c_value);

    sin_arg = 3.141596 / 2;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(%lf)=%lf\n", sin_arg, asm_value);
    printf("C_Sin(%lf)=%lf\n", sin_arg, c_value);

    sin_arg = M_PI;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(M_PI)=%lf\n", asm_value);
    printf("C_Sin(M_PI)=%lf\n", c_value);

    sin_arg = M_PI/2;
    asm_value = asm_sin(sin_arg);
    c_value = c_sin(sin_arg);
    printf("ASM_Sin(M_PI/2)=%lf\n", asm_value);
    printf("C_Sin(M_PI/2)=%lf\n", c_value);

    asm_value = asm_sin_pi();
    printf("ASM_Sin(FPU_PI)=%lf\n", asm_value);

    
    asm_value = asm_sin_pi_2();
    printf("ASM_Sin(FPU_PI/2)=%lf\n", asm_value);
}