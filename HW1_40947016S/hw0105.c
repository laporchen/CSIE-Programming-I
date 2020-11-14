#include "stdint.h"
#include "stdio.h"

int main()
{
    int32_t a;
    printf("Please enter an integer: ");
    scanf("%d", &a);
    printf("%d: %.8X", a, a);
    return 0;
}