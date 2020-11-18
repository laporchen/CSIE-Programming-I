#include "stdio.h"
#include "stdint.h"
#include "header2.h"

int main()
{

	int num;
	printf("Please enter the disk number :");
	if(scanf("%d",&num)!=1 ||(num<2 ||num>20)
	{
		printf("ERROR\n");
	}
	hanoi(num);


	return 0;
}

