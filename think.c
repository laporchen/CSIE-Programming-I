#include "stdint.h"
#include <stdio.h>
#define intt int32_t
//hw0503 thinking
intt func();
void printp(intt[], intt);
int main()
{
    if (func() == -1)
        printf("ERROR\n");
    return 0;
}
