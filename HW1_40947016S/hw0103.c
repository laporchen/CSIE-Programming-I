#include "stdint.h"
#include "stdio.h"
int main()
{
    float a, t;
    printf("Please enter the acceleration due to gravity: ");
    scanf("%g", &a);
    printf("Please enter the time (s): ");
    scanf("%g", &t);
    printf("Final velocity: %g m/s\n", a * t);
    printf("The altitude: %g m\n", 0.5 * a * t * t);
    return 0;
}