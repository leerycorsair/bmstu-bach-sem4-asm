#include "my_sin.h"

double c_sin(double arg)
{
    return sin(arg);
}

double asm_sin(double arg)
{
    double result = 0;
    __asm__(
        "fld %0\n"
        "fsin\n"
        "fstp %1\n" ::"m"(arg),
        "m"(result));
    return result;
}

double asm_sin_pi()
{
    double result = 0;
    __asm__(
        "fldpi\n"
        "fsin\n"
        "fstp %0\n" ::"m"(result));
    return result;
}

double asm_sin_pi_2()
{
    double result = 0;
    double tmp = 2;
    __asm__(
        "fldpi\n"
        "fld %0\n"
        "fdivp\n"
        "fsin\n"
        "fstp %1\n" ::"m"(tmp),
        "m"(result));
    return result;
}