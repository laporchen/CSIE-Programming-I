#include "stdint.h"
#include "stdio.h"

int main()
{
    float a, b, c;
    char comma1, comma2;
    printf("Please enter a quadratic polynomial (a,b,c): ");
    if (scanf("%f,%f,%f", &a, &b, &c) != 3)
    {
        printf("Invaild Input.\n");
        return 0;
    }
    float out = b * b - 4 * (a * c);
    if (out > 0)
    {
        printf("Two distinct real roots.\n");
    }
    else if (out == 0)
    {
        printf("One real root.\n");
    }
    else
    {
        printf("No real roots.\n");
    }
    return 0;
}