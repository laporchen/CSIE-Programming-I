#include "stdint.h"
#include "stdio.h"
//Please enter the first line : (1, 1), (-1, -1) Please enter the second line : (1, -1), (-1, 1) Intersection : (0, 0)
int main()
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    printf("Please enter the first line : ");

    if (scanf("(%f,%f), (%f,%f)", &x1, &y1, &x2, &y2) != 4)
    {
        printf("Invaild Input.\n");
        return 0;
    }
    printf("Please enter the second line : ");
    if (scanf(" (%f,%f), (%f,%f)", &x3, &y3, &x4, &y4) != 4)
    {
        printf("Invaild Input.\n");
        return 0;
    }
    if (x1 == x2 && y1 == y2)
    {
        printf("A line,not a point.\n");
        return 0;
    }
    if (x3 == x4 && y3 == y4)
    {
        printf("A line,not a point.\n");
        return 0;
    }

    float a = y2 - y1;
    float b = x1 - x2;
    float p = x1 * y2 - x2 * y1;
    float c = y4 - y3;
    float d = x3 - x4;
    float q = x3 * y4 - x4 * y3;
    if ((a / c) == (b / d))
    {
        fprintf(stderr, "Alert : The two lines are either parallel or the lines are the same line.\n");
        return 0;
    }
    float ox = (p * d - b * q) / (a * d - b * c);
    float oy = (p * c - a * q) / (b * c - a * d);
    if (ox == -0)
    {
        ox = 0;
    }
    if (oy == -0)
    {
        oy = 0;
    }
    printf("Intersection : (%.2f, %.2f)\n", ox, oy);
    return 0;
}