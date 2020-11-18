#include "stdint.h"
#include "stdio.h"

#define intt int64_t

int main()
{
    intt a;
    printf("Please enter a natural number : ");
    if (scanf("%ld", &a) != 1)
    {
        printf("ERROR\n");
        return 0;
    }
    else if (a <= 0)
    {
        printf("ERROR\n");
        return 0;
    }
    intt b = a;
    intt c = 0;
    while (b != 0)
    {
        b /= 10;
        c++;
    }
    intt p = 1;
    for (intt i = 1; i < c; i++)
    {
        p *= 10;
    }
    c = p;
    intt d = a;
    a %= p;
    p *= d % 10;
    printf("%ld\n", (a / 10) * 10 + p + d / c);
    return 0;
}
