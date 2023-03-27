#include "comparator.h"

#include <stdlib.h>

int main()
{
    float fnum1 = 32, fnum2 = 15;
    float_cmp(fnum1, fnum2);

    double dnum1 = 21, dnum2 = -12.5;
    double_cmp(dnum1, dnum2);

#ifndef MNO
    long double ldnum1 = -3, ldnum2 = 0.1;
    long_double_cmp(ldnum1, ldnum2);
#endif

    return EXIT_SUCCESS;
}