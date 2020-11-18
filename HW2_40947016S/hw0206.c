#include "stdio.h"

int main()
{
    printf("\033[1;31m");
    printf("Hello ");
    printf("\033[1;34m");
    printf("\033[5m");
    printf("World.");
    printf("\033[0m");
    return 0;
}