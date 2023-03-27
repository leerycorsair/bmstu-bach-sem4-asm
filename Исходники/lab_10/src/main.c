#include <stdlib.h>
#include <stdio.h>

#include "dot.h"
#include "check_time.h"

int main()
{
    dot_t dot1 = {3.0, 1.2, -1.23, 321.0};
    dot_t dot2 = {21.63763, 121.2, 454.43, 325.5};

    double time;

    time = check_time(dot1, dot2, dot_prod_c);
    printf("C time = %lf\n", time);

    time = check_time(dot1, dot2, dot_prod_asm);
    printf("ASM time = %lf\n", time);

    return EXIT_SUCCESS;
}