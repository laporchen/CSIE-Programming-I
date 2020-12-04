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