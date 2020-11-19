#include "stdio.h"
#include "stdint.h"
#include "header4.h"

double rq(double r,int32_t n)
{
	double result = 0;
	for(int32_t i =0;i<n;i++)
	{
		if(i==0)
		{
			result += r*2;
		}
		else
		{
			result = 1/(1/result + 1/r);
			result += r;
		}
	}
	return result;
}