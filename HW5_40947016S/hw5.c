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
    if (scanf("\n%d", &p1) != 1 || p1 < 0)
        return -1;
    printf("Please enter p1 coefficients: ");
    intt p1c[p1 + 1], p1p[p1 + 1];
    for (intt i = 0; i < p1 + 1; i++)
    {
        if (scanf("\n%d", &p1c[i]) != 1)
            return -1;
        if (i == 0 && p1c[0] == 0)
        {
            printf("Leading coefficient shouldn't be 0.\n");
            return -1;
        }

        p1p[i] = p1c[i];
    }
    printf("Please enter p2 degree: ");
    if (scanf("\n%d", &p2) != 1 || p2 < 0)
        return -1;
    printf("Please enter p2 coefficients: ");
    intt p2c[p2 + 1], p2p[p2 + 1];
    for (intt i = 0; i < p2 + 1; i++)
    {
        if (scanf("\n%d", &p2c[i]) != 1)
            return -1;
        if (i == 0 && p2c[0] == 0)
        {
            printf("Leading coefficient shouldn't be 0.\n");
            return -1;
        }
        p2p[i] = p2c[i];
    }
    printf("p1: ");
    printp(p1p, p1 + 1);
    printf("p2: ");
    printp(p2p, p2 + 1);
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
                //printf("p1c[%d] %d \n", p1copy, p1c[p1copy]);
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
                //printf("p2c[%d] %d \n", p1copy, p2c[p2copy]);
                pn2[max - i] = p2c[p2copy];
                p2copy--;
            }
        }
        printf("pn1[%d] = %d,p1c[%d] = %d\n", i, pn1[i], i, p1c[i]);
        printf("pn2[%d] = %d,p2c[%d] = %d\n", i, pn2[i], i, p2c[i]);
    }

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
        else
        {
            printf("%dx^%d", a[i], c);
        }
        if (a[i + 1] > 0)
        {
            printf(" + ");
        }
        else if (a[i + 1] < 0)
        {
            printf(" - ");
            a[i + 1] = -(a[i + 1]);
        }
        else
        {
            for (intt j = i + 1; j < size; j++)
            {
                if (a[j] != 0)
                {
                    if (a[j] > 0)
                        printf(" + ");
                    else
                    {
                        printf(" - ");
                    }
                }
            }
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
//hw0504
intt getRegression()
{
    double a, b; // result y = ax + b
    intt num;
    printf("Please enter the point number: ");
    if (scanf("%d", &num) != 1 && num <= 0)
        return 1;
    double pointx[num];
    double pointy[num];
    double xa, ya;
    for (intt i = 0; i < num; i++)
    {
        printf("Please enter the point %d: ", i + 1);
        if (scanf("%lf", &pointx[i]) != 1 || scanf("%lf", &pointy[i]) != 1)
            return 1;
    }
    xa = avg(&pointx[0], num);
    ya = avg(&pointy[0], num);
    intt sumx = avg(&pointx[0], 1), sumy = avg(&pointy[0], 1);
    b = beta(xa, ya, &pointx[0], &pointy[0], num);
    a = alpha(ya, xa, b);
    if (a != 0 && b != 0)
        printf("Regression Equation: y = %.2lf x + %.2lf\n", b, a);
    else if (a == 0 && b != 0)
        printf("Regression Equation: y = %.2lf x \n", b);
    else if (a != 0 && b == 0)
        printf("Regression Equation: y = %.2lf\n", a);
    else if (a == 0 && b == 0)
        printf("Regression Equation: y = 0\n");
    return 0;
}
double alpha(double ya, double xa, double b)
{
    return ya - (xa * b);
}
double beta(double xa, double ya, double *x, double *y, intt n)
{
    double a = 0, c = 0;
    for (intt i = 0; i < n; i++)
    {
        a += (*x - xa) * (*y - ya);
        c += (*x - xa) * (*x - xa);
        *x++;
        *y++;
    }
    return a / c;
}
double avg(double *inputs, intt num)
{
    double result = 0;
    for (intt i = 0; i < num; i++)
    {
        result += *inputs;
        *inputs++;
    }
    return result / num;
}
//hw0505
void game()
{
    srand(time(NULL));
    intt w, h, mine;
    if (allInput(&w, &h, &mine))
        return;
    intt map[h][w];              //showing on screen,also saving flag placement
    intt open[h][w];             //checking is the square opened
    intt num[h][w];              //store mine place and mine counter
    for (intt i = 0; i < h; i++) //init arrays
    {
        for (intt j = 0; j < w; j++)
        {
            num[i][j] = 0;
            map[i][j] = 0;
            open[i][j] = 0;
        }
    }
    intt mineCount = mine;
    intt mx, my; //random location for mine
    while (mine) //init mine location
    {
        mx = rand() % w;
        my = rand() % h;
        if (num[my][mx] == 0)
        {
            num[my][mx] = -1;
            mine--;
        }
    }

    for (intt i = 0; i < h; i++) //caculate mine counter
    {
        for (intt j = 0; j < w; j++)
        {

            if (num[i][j] == -1)
                continue;
            intt counter = 0;
            for (intt p = -1; p < 2; p++)
                for (intt q = -1; q < 2; q++)
                {
                    if ((p + i) < 0 || (q + j) < 0 || p + i >= h || q + j >= w)
                        continue;
                    if (num[p + i][q + j] == -1)
                        counter++;
                }
            num[i][j] = counter;
        }
    }
    intt game = 1; //check whether the game is end
    intt option;   //get player's choice(1 is open,2 is flag)
    intt x, y;     //chosen square
    while (game)
    {
        drawGrid(&num[0][0], w, h, &open[0][0]);
        getChoice(&option, &x, &y, w, h, &open[0][0]);
        //printf("y = %d,x = %d\n", y, x);
        modifySquare(&game, &num[0][0], &open[0][0], x, y, w, h, option);
        //printf("unopen %d\n", getunOpenSquare(&open[0][0], w, h));
        if (!(getunOpenSquare(&open[0][0], w, h) - mineCount))
            break;
    }
    if (game == 0)
    {
        printf("\033[1;31mYou hit a mine,You lose.\n");
        return;
    }
    else
    {
        printf("\033[1;31mYou win!\n");
        return;
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
    if (input(mine, 30, 90))
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
intt getChoice(intt *o, intt *x, intt *y, intt width, intt height, intt *open)
{

    while (1)
    {
        printf("Your Option (1:Open, 2: Flag): ");
        if (!input(o, 1, 2))
            break;
    }
    while (1)
    {
        printf("Position (row,column): ");
        if (!input(y, 0, width - 1) && !input(x, 0, height - 1))
        {
            intt *openloc = ((open + *y * height) + *x);
            if (*o == 1 && *openloc == 1)
            {
                printf("Square is already opened.\n");
                y = NULL;
                x = NULL;
            }
            else if (*o == 1 && *openloc == 2)
            {
                printf("Square is flagged.\n");
                y = NULL;
                x = NULL;
            }

            else
            {
                break;
            }
        }
    }
    return 1;
}
void drawGrid(intt *num, intt w, intt h, intt *open)
{
    printf("\n");
    { //index print
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
    }
    intt color[8] = {34, 32, 31, 35, 36, 33, 43, 41};
    for (intt i = 0; i < h; i++)
    {
        printf("\033[0;39m");
        printf("%3d|", i);
        for (intt j = 0; j < w; j++)
        {
            printf("\033[0;39m");
            //printf("%d %d\n", *num, *open);
            if (*open == 2)
            {
                printf("  \033[1;47m\033[1;31mF");
                *open++;
                *num++;
                continue;
            }
            if (*open == 1)
            {
                if (*num == -1)
                {
                    printf("  M");
                    *open++;
                    *num++;
                    continue;
                }
                if (*num != 0)
                {

                    printf("\033[0;%dm%3d", color[*num - 1], *num);
                    *open++;
                    *num++;
                    continue;
                }
                if (*num == 0)
                {
                    printf("   ");
                    *open++;
                    *num++;
                    continue;
                }
            }
            else if (*open == 0)
            {
                printf("  *");
                *open++;
                *num++;
                continue;
            }
        }
        printf("\033[0;39m\n");
    }
}
void modifySquare(intt *game, intt *mine, intt *open, intt x, intt y, intt w, intt h, intt option)
{
    intt *openloc = ((open + y * w) + x);
    intt *mineloc = ((mine + y * w) + x);
    //printf("%d %d\n", *open, *mine);
    //printf("openloc = %d,mineloc = %d\n", *openloc, *mineloc);
    if (option == 1)
    {
        if (*mineloc == -1)
        {
            *game = 0;
            return;
        }
        if (*mineloc != 0)
        {
            *openloc = 1;
            return;
        }
        if (*mineloc == 0)
        {
            *openloc = 1;
            for (intt i = -1; i < 2; i++)
            {
                for (intt j = -1; j < 2; j++)
                {

                    if (y + i >= h || y + i < 0 || x + j < 0 || x + j >= w)
                        continue;

                    if ((*(open + (y + i) * h + x + j)) == 1)
                        continue;
                    if ((*(open + (y + i) * h + x + j)) == 2)
                        continue;
                    if ((*(mine + (y + i) * h + x + j)) == -1)
                        continue;
                    if ((*(mine + (y + i) * h + x + j)) != 0)
                    {
                        *(open + (y + i) * h + x + j) = 1;
                        continue;
                    }
                    //printf("y+i = %d,x+j = %d\n", y + i, x + j);
                    if ((*(mine + (y + i) * h + x + j)) == 0)
                        modifySquare(game, mine, open, x + j, y + i, w, h, 1);
                }
            }
            return;
        }
    }

    else if (option == 2)
    {
        if (*openloc == 1)
        {
            printf("Square is already opened.\n");
            return;
        }
        if (*openloc == 2)
            *openloc = 0;
        else
            *openloc = 2;
        return;
    }
}
intt getunOpenSquare(intt *open, intt w, intt h)
{
    intt returnValue = 0;
    for (intt i = 0; i < h; i++)
    {
        for (intt j = 0; j < w; j++)
        {
            if (*open == 0)
                returnValue++;
            *open++;
        }
    }
    return returnValue;
}
