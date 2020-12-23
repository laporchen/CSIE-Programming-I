#include "hw6.h"
#define i32 int32_t
#define i64 int64_t
//hw0601
void split(i64 *input)
{
 	int8_t *splitter = input;
	int8_t *arr[8];
	for(i32 i = 0;i<8;i++)
	{
		*arr[i] = *splitter;
		splitter++;
	} 
}

//hw0603
void rotate(double *x,double *y,double theta)
{
	double d = theta;
	d /= 180.0;
	d*= -1;
	d *= M_PI;
	double rx = *x,ry = *y;
	*x = rx * cos(d) - ry * sin(d);
	*y = rx * sin(d) + ry * cos(d);
	return;
}
