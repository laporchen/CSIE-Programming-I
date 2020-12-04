#include "hw5.h"
#define intt int32_t
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