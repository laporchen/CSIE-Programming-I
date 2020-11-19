#include "header2.h"
#define intt int32_t
void hanoi_re(intt num, intt source, intt spare, intt target, intt disk)
{
	//source spare target 0,1,2
	if (num == 1)
	{
		printf("Move disk %d to rod %d.\n", disk, target);
	}
	else
	{
		hanoi_re(num - 1, source, target, spare, num - 1);
		hanoi_re(1, source, spare, target, num);
		hanoi_re(num - 1, spare, source, target, num - 1);
	}
	return;
}
void hanoi_it(intt num)
{
	int A, B, C, exA, exB, exC;
	A = 1;
	B = 21;
	C = 21;
	exA = 2;
	exB = B;
	exC = C;
	if (num % 2 == 0)
	{
		for (intt i = 0; i < mv(num); i++)
		{
			if (A < B)
			{
				printf("Move disk %d to rod 2.\n", A);
				exB = B;
				B = A;
				A++;
				if (exA > num)
				{
					A = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 1.\n", B);
				exA = A;
				A = B;
				B++;
				if (exB > num)
				{
					B = 21;
				}
			}
			i++;
			if (i >= mv(num))
				break;
			if (A < C)
			{
				printf("Move disk %d to rod 3.\n", A);
				exC = C;
				C = A;
				A++;
				if (exA > num)
				{
					A = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 1.\n", C);
				exA = A;
				A = C;
				C++;
				if (exC > num)
				{
					C = 21;
				}
			}
			i++;
			if (i >= mv(num))
				break;
			if (B < C)
			{
				printf("Move disk %d to rod 3.\n", B);
				exC = C;
				C = A;
				B++;
				if (exB > num)
				{
					B = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 2.\n", C);
				exB = B;
				B = C;
				C++;
				if (exC > num)
				{
					C = 21;
				}
			}
		}
	}
	else
	{
		for (intt i = 0; i < mv(num); i++)
		{
			if (A < C)
			{
				printf("Move disk %d to rod 3.\n", A);
				exC = C;
				C = A;
				A++;
				if (exA > num)
				{
					A = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 1.\n", C);
				exA = A;
				A = C;
				C++;
				if (exC > num)
				{
					C = 21;
				}
			}
			i++;
			if (i >= mv(num))
				break;
			if (A < B)
			{
				printf("Move disk %d to rod 2.\n", A);
				exB = B;
				B = A;
				A++;
				if (exA > num)
				{
					A = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 1.\n", B);
				exA = A;
				A = B;
				B++;
				if (exB > num)
				{
					B = 21;
				}
			}
			i++;
			if (i >= mv(num))
				break;
			if (B < C)
			{
				printf("Move disk %d to rod 3.\n", B);
				exC = C;
				C = B;
				B++;
				if (exB > num)
				{
					B = 21;
				}
			}
			else
			{
				printf("Move disk %d to rod 2.\n", C);
				exB = B;
				B = C;
				C++;
				if (exC > num)
				{
					C = 21;
				}
			}
		}
	}

	return;
}
int32_t mv(intt n)
{
	int r = 1;
	for (intt i = 0; i < n; i++)
		r *= 2;
	return r - 1;
}
