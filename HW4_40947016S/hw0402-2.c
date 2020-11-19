#include "hw4.h"
int main()
{

	int num;
	printf("Please enter the disk number :");
	if (scanf("%d", &num) != 1 || (num < 2 || num > 20))
	{
		printf("ERROR\n");
		return 0;
	}
	hanoi_it(num);

	return 0;
}
