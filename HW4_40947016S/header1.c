#include "header1.h"

void getRoman(int32_t n)
{
    char tableT[3][3] = {"M", "MM", "MMM"};
    char tableH[9][4] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char tableTe[9][4] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char tableU[9][4] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int32_t index;
    index = n / 1000;
    printf("%d in Roman Number: ", n);
    if (index != 0)
    {
        for (int32_t i = 0; i < 3; i++)
            printf("%c", tableT[index - 1][i]);
    }
    n %= 1000;
    index = n / 100;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableH[index - 1][i]);
    }
    n %= 100;
    index = n / 10;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableTe[index - 1][i]);
    }
    n %= 10;
    index = n / 1;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableU[index - 1][i]);
    }
    printf("\n");
}