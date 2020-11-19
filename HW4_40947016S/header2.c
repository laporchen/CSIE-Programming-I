#include "stdio.h"
#include "stdint.h"
#define intt int32_t
int32_t hanoi_re(int32_t num)
{


}
int32_t hanoi_it(int32_t num)
{
	intt pos[20];
	for(intt i = 0;i<20;i++)
		pos[i] = 1;
	for(intt i =0;i<pw(num);i++)
	{
		if(num%2==0)
		{
			if(i%3==0)
			{
			}
			
		}
		else
		{
		
		}

	}

}

int32_t pw(intt n)
{
	int r = 1;
	for(intt i = 0;i<n;i++)
		r*=2;
	return r;
}

