#include "my_strlen.h"

size_t my_strlen(const char *str)
{
    size_t len;
    __asm__ __volatile__(
        "xor %%rax, %%rax\n\t"
        "xor %%rcx, %%rcx\n\t"
        "not %%rcx\n\t"
        "repne scasb\n\t"
        "not %%rcx\n\t"
        "dec %%rcx\n\t"
        : "=c"(len)
        : "D"(str));

    return len;
}