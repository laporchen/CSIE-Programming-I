#include "header3.h"
#define intt int32_t

void go()
{
    intt k;
    double result = 0;
    printf("k-th order Taylor polynomial for e\nPlease enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0)
    {
        printf("ERROR\n");
        return;
    }
    for (intt i = 0; i < k + 1; i++)
    {
        result += 1 / getFactorial(i);
    }
    printf("%.20lf\n", result);
    return;
}

double getFactorial(intt n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * getFactorial(n - 1);
    }
}