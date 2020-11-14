#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#define intt int32_t
intt p, a = 0;
void result(intt);
void loop();
intt main()
{
    printf("Start\n");
    loop();
    printf("Final\n");
    return 0;
}
void loop()
{
    while (true)
    {
        printf("Please enter an integer: ");
        scanf("%d", &p);
        result(p);
        if (a == 0)
            printf("Start\n");
        else if (a == 7)
            break;
        else
            printf("S%d\n", a);
    }
}
void result(intt p)
{
    if (a == 0)
    {
        if (p == 11)
        {
            a = 3;
            return;
        }
        if (p == 10 || p == 35)
        {
            a = 1;
            return;
        }
        if (p == 20 || p == 78)
        {
            a = 5;
            return;
        }
        return;
    }
    if (a == 1)
    {
        if (p == 19)
        {
            a = 2;
            return;
        }
        if (p == 12 || p == 36)
        {
            a = 6;
            return;
        }
        return;
    }
    if (a == 2)
    {
        if (p == 43)
        {
            return;
        }
        if (p == 99)
        {
            a = 7;
            return;
        }
        a = 0;
        return;
    }
    if (a == 3)
    {
        a = 4;
        return;
    }
    if (a == 4)
    {
        a = 6;
        return;
    }
    if (a == 5)
    {
        if (p == 1)
        {
            a = 4;
            return;
        }
        if (p == 2)
        {
            a = 6;
            return;
        }
        a = 0;
        return;
    }
    if (a == 6)
    {
        if (p == 108)
        {
            a = 7;
            return;
        }
        a = 5;
        return;
    }
}
