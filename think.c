#include "stdint.h"
#include <stdio.h>
#define intt int32_t
//hw0503 thinking
intt func();
void printp(intt[], intt);
int main()
{
    p(1, 10);
    return 0;
}
int p(int i, int N)
{
    return (i < N && printf("Nah%d\n", i) && !p(i + 1, N)) || printf("yes%d\n", i);
}
