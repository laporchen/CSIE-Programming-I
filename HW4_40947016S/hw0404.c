#include "stdio.h"
#include "stdint.h"
#include "header4.h"

int main()
{
	double r;
	int32_t n;
	printf("Please enter the resistance (1-100) :");
	if(scanf("%lf",&r)!=1||(r<1||r>100))
	{
	printf("ERROR\n");
	return 0;
	}
	printf("Please enter n (1-100) :");
        if(scanf("%d",&n)!=1||(n<1||n>100))
        {
        printf("ERROR\n");
        return 0;
        }
	printf("Ans: %lf\n", rq(r,n));
	return 0;
}
