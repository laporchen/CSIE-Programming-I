#include "stdio.h"
#include "stdint.h"

int main()
{
    int32_t own;
    int32_t ex;
    int32_t open;
    printf("Please enter the Gashapon number : ");
    if(scanf("%d",&own)!=1 || own <0)
    {
        printf("ERROR\n");
        return 0;
    }
    printf("Please enter the exchange number : ");
    if(scanf("%d",&ex) != 1 || ex<=0)
    {
        printf("ERROR\n");
        return 0;
    }
    open = own;
    while(own/ex > 0)
    {
        open += own/ex;
        own /= ex;
    }
    printf("You can totally open %d Gashapon balls.\n",open);
    return 0;
}