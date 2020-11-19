#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"

bool numCheck(int32_t);
void out(int32_t a, int32_t b);
int32_t totalNum = 0, an = 0, bn = 0;
int main()
{
    int32_t a, b;
    printf("Please enter the 1st integer : ");
    if (scanf("%d", &a) != 1 || a < 0)
    {
        printf("ERROR\n");
        return 0;
    }
    if (numCheck(a))
    {
        printf("ERROR\n");
        return 0;
    }
    an = totalNum;
    printf("Please enter the 2nd integer : ");
    if (scanf("%d", &b) != 1 || b < 0)
    {
        printf("ERROR\n");
        return 0;
    }
    if (numCheck(b))
    {
        printf("ERROR\n");
        return 0;
    }
    bn = totalNum - an;
    out(a, b);
    return 0;
}
bool numCheck(int32_t a)
{
    int32_t c = 10;
    while (a / c > 0)
    {
        if (a % c < (a / c) % (c))
        {
            return true;
        }
        totalNum++;

        c *= 10;
    }
    totalNum++;

    return false;
}

void out(int32_t a, int32_t b)
{
    int32_t min = 1, result = 0, ac = 10, bc = 10;
    while (totalNum > 0)
    {
        int32_t mincount = 0;
        int32_t ao = a, bo = b;
        for (int32_t i = 0; i < an; i++)
        {
            if (min == ao % 10)
            {
                mincount++;
            }
            ao /= 10;
        }
        for (int32_t i = 0; i < bn; i++)
        {
            if (min == bo % 10)
            {
                mincount++;
            }
            bo /= 10;
        }
        for (int32_t i = 0; i < mincount; i++)
        {
            result = result * 10 + min;
        }
        min++;
        totalNum -= mincount;
    }
    printf("Result : %d\n", result);
    return;
}
