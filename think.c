#include "stdint.h"
#include <stdio.h>
#define intt int32_t
int main()
{
    intt A[3][3];
    intt B[3][3];
    intt C[3][3];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                printf("Enter array element [%d][%d]: ", j, k);
                if (i == 1)
                    scanf("%d", &B[j][k]);
                else
                    scanf("%d", &A[j][k]);
            }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%4d ", C[i][j]);
        printf("\n");
    }

    return 0;
}