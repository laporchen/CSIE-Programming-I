#include "stdint.h"
#include "stdio.h"

int main()
{
    int32_t income, marry, ppl, hi, si, t, pc, dp, tax = 0;
    printf("Gross salary: ");
    if (scanf("%d", &income) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (income < 0)
    {
        printf("Invaild input(Negative input).\n");
        return 0;
    }
    printf("Married? (0/1)");
    if (scanf("%d", &marry) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    else if (marry != 1 && marry != 0)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("How many people are there in your family: ");
    if (scanf("%d", &ppl) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("How many people in your family have income: ");
    if (scanf("%d", &hi) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("Special Deduction for Savings and Investment: ");
    if (scanf("%d", &si) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("Special Deduction for Tuition: ");
    if (scanf("%d", &t) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("How many preschool children: ");
    if (scanf("%d", &pc) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("How many disable people: ");
    if (scanf("%d", &dp) != 1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if ((ppl == 2 && marry) && pc > 0)
    {
        printf("Invaild Input(Number did not add up).\n");
        return 0;
    }
    else if (ppl < pc + dp)
    {
        printf("Invaild Input(Number did not add up).\n");
        return 0;
    }
    else if (ppl < hi)
    {
        printf("Invaild Input(Number did not add up).\n");
        return 0;
    }
    if (marry)
    {
        income -= 240000;
    }
    else
    {
        income -= 120000;
    }
    income -= ppl * 88000;
    income -= hi * 200000;
    income -= si * 270000;
    income -= t * 25000;
    income -= pc * 120000;
    income -= dp * 200000;
    if (income <= 540000)
    {
        tax = income * 0.05;
    }
    else if (income <= 1210000)
    {
        tax = income * 0.12 - 37800;
    }
    else if (income <= 2420000)
    {
        tax = income * 0.2 - 134600;
    }
    else if (income <= 4530000)
    {
        tax = income * 0.3 - 376600;
    }
    else
    {
        tax = income * 0.4 - 829600;
    }
    if (tax <= 0)
    {
        tax = 0;
    }
    printf("Tax: %d\n", tax);
    return 0;
}