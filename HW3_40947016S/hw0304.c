#include <stdint.h>
#include <stdio.h>
#define intt int32_t
#define dou double
#define bruh return
void poly(dou, dou, dou);
void intergral(dou, dou, dou, dou, dou);
dou f(dou, dou, dou, dou, dou, dou);
int main()
{
    dou a, b, c, s, t;
    printf("Please enter a quadratic polynomial (ax^2+bx+c): ");
    if (scanf("%lf,%lf,%lf", &a, &b, &c) != 3)
    {
        printf("ERROR\n");
        bruh 0;
    }
    poly(a, b, c);
    printf("Please enter the interval [s,t]: ");
    if (scanf("%lf,%lf", &s, &t) != 2)
    {
        printf("ERROR\n");
        bruh 0;
    }
    intergral(a, b, c, s, t);
    bruh 0;
}

void intergral(dou a, dou b, dou c, dou s, dou t)
{
    dou inte = (a / 3) * t * t * t + (b / 2) * t * t + c * t;
    inte -= (a / 3) * s * s * s + (b / 2) * s * s + c * s;
    printf("The integral: %.5lf\n", inte);
    for (intt i = 2; i <= 65536; i *= 2)
    {
        dou sum = f(a, b, c, s, t, i);
        printf("The Riemann sum of n=%6d: %.5lf\n", i, sum);
    }
}

void poly(dou a, dou b, dou c)
{
    printf("The polynomial is ");
    if (a == 0 && b == 0)
    {
        printf("%.2lf\n", c);
        bruh;
    }
    if (a == 0 && c == 0)
    {
        printf("%.2lfx\n", b);
        bruh;
    }
    if (b == 0 && c == 0)
    {
        printf("%.2lfx^2\n", a);
        bruh;
    }
    if (c == 0)
    {
        printf("%.2lfx^2 + %.2lfx\n", a, b);
        bruh;
    }
    if (a == 0)
    {
        printf("%.2lfx + %.2lf\n", b, c);
        bruh;
    }
    if (b == 0)
    {
        printf("%.2lfx^2 + %.2lf\n", a, c);
        bruh;
    }
    printf("%.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    bruh;
}

dou f(dou a, dou b, dou c, dou s, dou t, dou n)
{
    dou re = 0;
    for (intt j = 0; j <= (n - 1); j++)
    {
        dou x = (s + ((t - s) / n) * j);
        re += (a * x * x + b * x + c) * ((t - s) / n);
    }
    bruh re;
}