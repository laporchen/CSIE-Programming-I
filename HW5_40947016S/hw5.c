#include "hw5.h"
#define intt int32_t
//hw0501
void sortA(intt a[], intt size)
{
    intt tmp;
    for (intt i = 0; i < size; i++)
    {
        for (intt j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}
void sortD(intt a[], intt size)
{
    intt tmp;
    for (intt i = 0; i < size; i++)
    {
        for (intt j = i + 1; j < size; j++)
        {
            if (a[i] < a[j])
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}
void split(intt a[], intt odd[], intt even[], intt size)
{
    intt oddC = 0, evenC = 0;
    for (intt i = 0; i < size; i++)
    {
        if (a[i] % 2)
        {
            odd[oddC] = a[i];
            oddC++;
        }
        else
        {
            even[evenC] = a[i];
            evenC++;
        }
    }
    sortA(odd, oddC);
    sortD(even, evenC);
    for (intt i = 0; i < oddC; i++)
        printf("%d ", odd[i]);
    for (intt i = 0; i < evenC; i++)
        printf("%d ", even[i]);
    printf("\n");
}
//hw0502
void matrixR(intt m[4][4])
{
    printf("The determinant is %d.\n", m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
                                           m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
                                           m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
                                           m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
                                           m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
                                           m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
                                           m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
                                           m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
                                           m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
                                           m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
                                           m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
                                           m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3]);
}
//hw0503
intt func()
{
    intt p1, p2;
    printf("Please enter p1 degree: ");
    if (scanf("%d", &p1) != 1 || p1 < 0)
        return -1;
    printf("Please enter p1 coefficients: ");
    intt p1c[p1 + 1];
    for (intt i = 0; i < p1 + 1; i++)
    {
        if (scanf("\n%d", &p1c[i]) != 1)
            return -1;
    }
    printf("Please enter p2 degree: ");
    if (scanf("%d", &p2) != 1 || p1 < 0)
        return -1;
    printf("Please enter p2 coefficients: ");
    intt p2c[p2 + 1];
    for (intt i = 0; i < p2 + 1; i++)
    {
        if (scanf("\n%d", &p2c[i]) != 1)
            return -1;
    }
    printf("p1: ");
    printp(p1c, p1 + 1);
    printf("p2: ");
    printp(p2c, p2 + 1);
    intt max = p1;
    if (p2 > max)
        max = p2;
    intt pn1[max + 1];
    intt pn2[max + 1];
    for (intt i = 0; i < max + 1; i++)
    {
        pn1[i] = 0;
        pn2[i] = 0;
    }
    intt counter = max - 1;
    intt plus[max + 1];
    intt sub[max + 1];
    intt mul[p1 + p2 + 1];
    intt p1copy = p1;
    intt p2copy = p2;
    //put inputs to new arrays
    for (intt i = 0; i < max + 1; i++)
    {

        if (p1 == max)
        {
            pn1[i] = p1c[i];
        }
        else
        {
            if (p1copy >= 0)
            {
                pn1[max - i] = p1c[p1copy];
                p1copy--;
            }
        }

        if (p2 == max)
        {

            pn2[i] = p2c[i];
        }
        else
        {
            if (p2copy >= 0)
            {
                pn2[max - i] = p2c[p2copy];
                p2copy--;
            }
        }
    }
    /*  for (intt i = 0; i < max + 1; i++)
        printf("pn1[%d]:%d\n", i, pn1[i]);
    for (intt i = 0; i < max + 1; i++)
        printf("pn2[%d]:%d\n", i, pn2[i]);*/
    intt lz1 = 0, lz2 = 0; //get leading zeros
    for (intt i = 0; i < max + 1; i++)
    {
        if (pn1[i] == 0)
            lz1++;
        if (pn2[i] == 0)
            lz2++;
    }
    for (intt i = 0; i < max + 1; i++)
    {
        plus[i] = pn1[i] + pn2[i];
        sub[i] = pn1[i] - pn2[i];
    }
    for (intt i = 0; i < p1 + p2 + 1; i++)
        mul[i] = 0; //init mul[]

    for (intt i = 0; i < max + 1; i++)
        for (intt j = 0; j < max + 1; j++)
        {
            if (i + j - lz1 - lz2 < 0)
                continue;
            mul[i + j - lz1 - lz2] += pn1[i] * pn2[j];
        }
    printf("p1 + p2: ");
    printp(plus, max + 1);
    printf("p1 - p2: ");
    printp(sub, max + 1);
    printf("p1 * p2: ");
    printp(mul, p1 + p2 + 1);
}
void printp(intt a[], intt size)

{
    intt c = size - 1;
    for (intt i = 0; i < size; i++)
    {
        if (a[i] != 0)
            break;
        if (a[size - 1] == 0)
        {
            printf("0\n");
            return;
        }
    }
    for (intt i = 0; i < size - 1; i++)
    {
        if (a[i] == 0)
            continue;
        if (a[i] == 1 && c != 1)
            printf("x^%d", c);
        else if ((a[i] == 1 && c == 1))
        {
            printf("x");
        }
        else if ((a[i] != 1 && c == 1))
        {
            printf("%dx", a[i]);
        }
        else if (a[i] != 0)
        {
            printf("%dx^%d", a[i], c);
        }
        if (a[i + 1] > 0)
        {
            printf(" + ");
        }
        else
        {
            printf(" - ");
            a[i + 1] = -(a[i + 1]);
        }
        c--;
    }
    if (a[size - 1] != 0)
        printf("%d\n", a[size - 1]);
    else
    {
        printf("\n");
    }
}
void game()
{
    srand(time(NULL));
    intt width, height, mine;
    //initial inputs
    if (allInput(&width, &height, &mine))
        return;
    intt mineArray[height][width], numArray[height][width], opened[height][width], mask[height][width];
    //init arrays
    for (intt i = 0; i < height; i++)
    {
        for (intt j = 0; j < width; j++)
        {
            mineArray[i][j] = 0;
            numArray[i][j] = 0;
            opened[i][j] = 0;
            mask[i][j] = 1;
        }
    }
    //init mine locations
    while (mine)
    {
        intt x = rand() % width;
        intt y = rand() % height;
        if (modifyGrid(&mineArray[0][0], 0, y, x, height, 3))
        {
            mine--;
        }
    }
    //init numArray
    for (intt i = 0; i < height; i++)
    {
        for (intt j = 0; j < width; j++)
        {

            intt counter = 0;
            for (intt x = -1; x <= 1; x++)
            {
                for (intt y = -1; y <= 1; y++)
                {
                    if ((x == 0 && y == 0) || (((j + x) < 0) || (j + x == width)) || (((i + y) < 0) || (i + y == height)))
                        continue;
                    if (mineArray[i + y][j + x] == 1)
                        counter++;
                }
            }
            if (mineArray[i][j] == 1)
            {
                counter = -1;
            }
            numArray[i][j] = counter;
        }
    }
    intt game = 1;
    intt option, row, column;
    //main loop
    while (game)
    {
        drawGrid(&numArray[0][0], width, height, &opened[0][0], 1);
        drawGrid(&mineArray[0][0], width, height, &opened[0][0], 2);
        drawGrid(&numArray[0][0], width, height, &opened[0][0], 2);
        //drawGrid(&mineArray[0][0], width, height);
        while (1)
        {
            if (getChoice(&option, &row, &column, width, height))
                if (modifyGrid(&opened[0][0], option, row, column, height, 2))
                    break;
        }
        if (option == 1)
            recursiveBlank(&numArray[0][0], column, row, height, width, &opened[0][0]);
    }
}
//draw gameGrid
void drawGrid(intt *array, intt w, intt h, intt *open, intt mode)
{
    if (mode == 1)
    {
        printf("    ");
        for (intt i = 0; i < w; i++)
        {
            printf("%3d", i);
        }
        printf("\n");
        for (intt i = 0; i < w * 3 + 5; i++)
        {
            printf("-");
        }
        printf("\n");
        for (intt j = 0; j < h; j++)
        {
            printf("%3d|", j);
            for (intt i = 0; i < w; i++)
            {
                if (*((open + i * h) + j) == 1)
                    if (*((array + i * h) + j) != 0)
                        printf("%3d", *((array + i * h) + j));
                    else
                        printf("   ");
                else if (*((open + i * h) + j) == 0)
                    printf("  *");
            }
            printf("\n");
        }
    }
    if (mode == 2)
    {
        printf("    ");
        for (intt i = 0; i < w; i++)
        {
            printf("%3d", i);
        }
        printf("\n");
        for (intt i = 0; i < w * 3 + 5; i++)
        {
            printf("-");
        }
        printf("\n");
        for (intt j = 0; j < h; j++)
        {
            printf("%3d|", j);
            for (intt i = 0; i < w; i++)
            {
                printf("%3d", *((array + i * h) + j));
            }
            printf("\n");
        }
    }
}
intt allInput(intt *width, intt *height, intt *mine)
{
    printf("Please enter the width  (10-16): ");
    if (input(width, 10, 16))
        return 1;
    printf("Please enter the height (10-16): ");
    if (input(height, 10, 16))
        return 1;
    printf("Please enter the mine number (30-90): ");
    if (input(mine, 10, 90))
        return 1;
}
intt input(intt *a, intt range0, intt range1)
{
    if (scanf("%d", a) != 1 || (*a < range0 || *a > range1))
    {
        printf("ERROR\n");
        return 1;
    }
    return 0;
}
intt getChoice(intt *o, intt *r, intt *c, intt width, intt height)
{
    printf("Your Option (1:Open, 2: Flag): ");
    while (1)
    {
        if (!input(o, 1, 2))
            break;
    }
    printf("Position (row,column): ");
    while (1)
    {
        if (!input(r, 0, width - 1) && !input(c, 0, height - 1))
            break;
    }
    return 1;
}
intt modifyGrid(intt *array, intt o, intt r, intt c, intt height, intt mode)
{
    if (mode == 2)
    {
        if (*((array + c * height) + r) != 0)
        {
            printf("Square is already opened.\n");
            return 0;
        }
        return 1;
    }
    else if (mode == 3)
    {
        if (*((array + c * height) + r) == 0)
        {
            *((array + c * height) + r) = 1;
            return 1;
        }
        return 0;
    }
    *((array + c * height) + r) = o;
    return 0;
}
void recursiveBlank(intt *map, intt x, intt y, intt h, intt w, intt *open)
{
    if ((*((open + y * h) + x)) == 1)
        return;
    printf("x is %d,y is %d,open is %d\n", x, y, *((open + y * h) + x));

    if ((*((open + y * h) + x)) == 0 && (*((map + y * h) + x) == 0))
    {
        printf("change [%d][%d] to 1\n", y, x);
        modifyGrid(open, 1, y, x, h, 1);
        if (y > 0 && x > 0 && y < h - 1 && x < w - 1) // not on edge
        {
            recursiveBlank(map, x - 1, y, h, w, open);
            recursiveBlank(map, x, y - 1, h, w, open);
            recursiveBlank(map, x, y + 1, h, w, open);
            recursiveBlank(map, x + 1, y, h, w, open);
        }
        else if (y > 0 && x > 0) //right, bottom,right bottom corner
        {
            if (y < h - 1 && x == w - 1)
            {
                recursiveBlank(map, x, y + 1, h, w, open);
                recursiveBlank(map, x, y - 1, h, w, open);
                recursiveBlank(map, x - 1, y, h, w, open);
            }
            else if (y == h - 1 && x < w - 1)
            {
                recursiveBlank(map, x + 1, y, h, w, open);
                recursiveBlank(map, x - 1, y, h, w, open);
                recursiveBlank(map, x, y - 1, h, w, open);
            }
            else if (y == h - 1 && x == w - 1)
            {
                recursiveBlank(map, x - 1, y, h, w, open);
                recursiveBlank(map, x, y - 1, h, w, open);
            }
        }
        else if (y >= 0 && x == 0) // left,left top/bottom corner
        {
            if (y == 0)
            {
                recursiveBlank(map, x, y + 1, h, w, open);
                recursiveBlank(map, x + 1, y, h, w, open);
            }
            else if (y < h - 1)
            {
                recursiveBlank(map, x, y + 1, h, w, open);
                recursiveBlank(map, x, y - 1, h, w, open);
                recursiveBlank(map, x + 1, y, h, w, open);
            }
            else if (y == h - 1)
            {
                recursiveBlank(map, x, y - 1, h, w, open);
                recursiveBlank(map, x + 1, y, h, w, open);
            }
        }
        else if (y == 0 && x > 0)
        {
            if (x == w - 1) //
            {
                recursiveBlank(map, x - 1, y, h, w, open);
                recursiveBlank(map, x, y + 1, h, w, open);
            }
            else
            {
                recursiveBlank(map, x - 1, y, h, w, open);
                recursiveBlank(map, x + 1, y, h, w, open);
                recursiveBlank(map, x, y + 1, h, w, open);
            }
        }
    }
    else if (*((map + y * h) + x) != -1)
    {
        modifyGrid(open, 1, y, x, h, 1);
    }
    else
    {
        printf("[%d][%d] is mine\n", y, x);
        return;
    }
    return;
}