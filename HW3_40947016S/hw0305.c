#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#define intt int32_t
#define dou double
/*
SIP Plan 
Annually payment: 40000 
Insurance fee in the first five years (0 is assumed afterwards): 60,30,30,15,15 
Insurance fee off: 1 
Monthly insurance processing fee: 100 
Age: 40 
How many years of payment: 15 
Expected annual return on investment rate: 5 
------------------------------ 
Your Payment and Account Value Table 
*/
intt payment, fee[5], foff, pf, age, year;
dou rate, value = 0;
bool input();
int main()
{
    if (!(input()))
    {
        printf("ERROR\n");
        return 0;
    }
    rate = 1 + rate * 0.01 / 12;
    dou realpayment;
    intt firstfive = age + 5;
    dou ageprice;
    intt totalpayment = 0;
    for (intt i = age; i < 101; i++)
    {
        ageprice = (i - 20) * 100 + 2000;
        if (ageprice < 2000)
            ageprice = 2000;
        if (i < firstfive)
        {
            realpayment = payment - ageprice - payment * (fee[i - age] - foff) * 0.01;
        }
        else if (i < age + year)
        {
            realpayment = payment - ageprice;
        }
        else
        {
            realpayment = -ageprice;
            payment = 0;
        }

        value += realpayment;
        totalpayment += payment;

        for (intt j = 0; j < 12; j++)
        {
            if (i == age && j == 0)
                continue;
            value = (value - pf) * rate;
        }
        if (value <= 0)
        {
            value = 0;
        }
        printf("%4d: %7d,%.2lf\n", i, totalpayment, value);
        if (value == 0)
        {
            break;
        }
    }
    return 0;
}

bool input()
{
    printf("SIP Plan\nAnnually payment: ");
    if (scanf("%d", &payment) != 1)
    {
        return false;
    }
    if (payment < 0)
    {
        return false;
    }
    printf("Insurance fee in the first five years (0 is assumed afterwards): ");
    if (scanf("%d,%d,%d,%d,%d", &fee[0], &fee[1], &fee[2], &fee[3], &fee[4]) != 5)
    {
        return false;
    }
    for (intt i = 0; i < 5; i++)
    {
        if (fee[i] < 0 || fee[i] > 100)
            return false;
    }
    printf("Insurance fee off: ");
    if (scanf("%d", &foff) != 1 || foff < 0)
    {
        return false;
    }
    printf("Monthly insurance processing fee: ");
    if (scanf("%d", &pf) != 1 || pf < 0)
    {
        return false;
    }
    printf("Age: ");
    if (scanf("%d", &age) != 1 || age <= 0)
    {
        return false;
    }
    printf("How many years of payment: ");
    if (scanf("%d", &year) != 1 || year <= 0)
    {
        return false;
    }
    printf("Expected annual return on investment rate: ");
    if (scanf("%lf", &rate) != 1 || rate < 0)
    {
        return false;
    }
    return true;
}
