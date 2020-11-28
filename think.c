#include "stdint.h"
#include <stdio.h>

int main()
{
    int32_t printfReturn, scanfReturn;
    int32_t input;
    printf("Input an integer. ");
    scanfReturn = scanf("%d", &input);
    printfReturn = printf("%d\n", input);
    printf("printf return %d\nscanf return %d\n", printfReturn, scanfReturn);
    return 0;
}