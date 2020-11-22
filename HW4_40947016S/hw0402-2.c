#include "hw4.h"
#include "stdint.h"
#include "stdio.h"
#define intt int32_t
int main()
{

	int num;
	printf("Please enter the disk number :");
	if (scanf("%d", &num) != 1 || (num < 2 || num > 20))
	{
		printf("ERROR\n");
		return 0;
	}
	hanoi_it_v(num);

	return 0;
}
