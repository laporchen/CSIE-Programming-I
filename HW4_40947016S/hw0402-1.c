#include "header2.h"
int main()
{

	int num;
	printf("Please enter the disk number :");
	if (scanf("%d", &num) != 1 || (num < 2 || num > 20))
	{
		printf("ERROR\n");
		return 0;
	}
	hanoi_re(num, 1, 2, 3, 1);

	return 0;
}
