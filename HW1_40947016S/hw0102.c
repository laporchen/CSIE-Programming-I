#include "stdint.h"
#include "stdio.h"
int main()
{
    int32_t a, result = 1;
    printf("Please enter a 5-digits integer: ");
    scanf("%d", &a);
    for (int32_t i = 0; i < 5; i++)
    {
        result *= a % 10;
        a /= 10;
    }
    printf("Result: %d", result);
    return 0;
}