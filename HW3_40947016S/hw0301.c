#include "stdint.h"
#include "stdio.h"

#define intt int32_t

int main()
{
    intt h, w;
    printf("Please enter the width : ");
    if ((scanf("%d", &h)) != 1)
    {
        printf("ERROR\n");
        return 0;
    }
    printf("Please enter the height : ");
    if (scanf("%d", &w) != 1)
    {
        printf("ERROR\n");
        return 0;
    }
    if (h <= 0 || w <= 0)
    {
        printf("ERROR\n");
        return 0;
    }
    intt xo = h, yo = w;
    intt max = h * w;
    intt grid[w][h];
    intt pointer = 1;
    intt i = 0, j = 0, xst = 0, yst = 0;
    while (pointer <= max)
    {
        for (j = xst; j < h; j++)
        {
            grid[i][j] = pointer;
            pointer++;
            if (pointer > max)
            {
                break;
            }
        }
        j--;
        yst++;
        if (pointer > max)
        {
            break;
        }
        for (i = yst; i < w; i++)
        {
            grid[i][j] = pointer;
            pointer++;
            if (pointer > max)
            {
                break;
            }
        }
        i--;
        h--;
        if (pointer > max)
        {
            break;
        }
        for (j = h - 1; j >= xst; j--)
        {
            grid[i][j] = pointer;
            pointer++;
            if (pointer > max)
            {
                break;
            }
        }
        j++;
        w--;
        if (pointer > max)
        {
            break;
        }
        for (i = w - 1; i >= yst; i--)
        {
            grid[i][j] = pointer;
            pointer++;
            if (pointer > max)
            {
                break;
            }
        }
        i++;
        xst++;
        if (pointer > max)
        {
            break;
        }
    }
    for (intt b = 0; b < yo; b++)
    {
        for (intt a = 0; a < xo; a++)
        {
            printf("%4d ", grid[b][a]);
        }
        printf("\n");
    }

    return 0;
}