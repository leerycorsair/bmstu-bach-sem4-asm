#include "dot.h"

float dot_prod_c(dot_t *dot1, dot_t *dot2)
{
    float result;
    result = dot1->x * dot2->x + dot1->y * dot2->y + dot1->z * dot2->z + dot1->w * dot2->w;
    return result;
}

float dot_prod_asm(dot_t *dot1, dot_t *dot2)
{
    float result;
    __asm__(
        "movups xmm0, [%0]\n"
        "movups xmm1, [%1]\n"
        "mulps  xmm0, xmm1\n"
        "haddps xmm0, xmm0\n"
        "haddps xmm0, xmm0\n"
        "movss  [%2], xmm0" ::"r"(dot1),
        "r"(dot2),
        "r"(&result));
    return result;
}