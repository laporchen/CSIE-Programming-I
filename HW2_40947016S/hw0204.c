#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
bool yes(int32_t y)
{
    bool isY;
    if (y % 4 == 0 && y % 100 != 0)
    {
        isY = true;
    }
    else
    {
        isY = false;
    }
    if (y % 400 == 0)
    {
        isY = true;
    }
    return isY;
}

int main()
{
    int32_t year, year1, month, month1, day, day1, daypassed = 0;
    printf("Date Format: YYYY/MM/DD\nStart Date: ");
    if (scanf("%d/%d/%d", &year, &month, &day) != 3)
    {
        printf("Invaild input.\n");
        return 0;
    }
    printf("End Date: ");
    if (scanf(" %d/%d/%d", &year1, &month1, &day1) != 3)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (month > 12 || day > 31)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (month < 0 || day < 0)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (month1 > 12 || day1 > 31)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (month1 < 0 || day1 < 0)
    {
        printf("Invaild input.\n");
        return 0;
    }
    if (year > year1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    else if (year == year1 && month > month1)
    {
        printf("Invaild input.\n");
        return 0;
    }
    else if (year == year1)
    {
        if (month == month1 && day > day1)
        {
            printf("Invaild input.\n");
            return 0;
        }
    }
    for (int32_t i = year + 1; i < year1; i++)
    {
        if (yes(i))
        {
            daypassed += 366;
        }
        else
        {
            daypassed += 365;
        }
    }
    int32_t md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (yes(year))
    {
        md[1] = 29;
    }
    else
    {
        md[1] = 28;
    }
    if (year == year1)
    {
        for (int32_t i = month + 1; i < month1; i++)
        {
            daypassed += md[i - 1];
        }
        if (month == month1)
        {
            daypassed += day1 - day;
        }
        else
        {
            daypassed += md[month - 1] - day;
            daypassed += day1;
        }
    }
    else
    {
        for (int32_t i = month + 1; i < 13; i++)
        {
            daypassed += md[i - 1];
        }
        daypassed += md[month - 1] - day;
        if (yes(year1))
        {
            md[1] = 29;
        }
        else
        {
            md[1] = 28;
        }
        for (int32_t i = 1; i < month1; i++)
        {
            daypassed += md[i - 1];
        }
        daypassed += day1;
    }

    printf("Duration: %d Day(s)\n", daypassed);
    return 0;
}
