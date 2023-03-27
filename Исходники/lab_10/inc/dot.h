#ifndef __DOT_H__
#define __DOT_H__

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} dot_t;

float dot_prod_c(dot_t *dot1, dot_t *dot2);
float dot_prod_asm(dot_t *dot1, dot_t *dot2);

#endif //__DOT_H__