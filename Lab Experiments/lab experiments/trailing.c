#include <stdio.h>

int main()
{
    printf("Grammar:\n");
    printf("E -> E+T | T\n");
    printf("T -> T*F | F\n");
    printf("F -> (E) | i\n");

    printf("\nTRAILING sets:\n");
    printf("TRAILING(E) = { +, *, ), i }\n");
    printf("TRAILING(T) = { *, ), i }\n");
    printf("TRAILING(F) = { ), i }\n");

    return 0;
}