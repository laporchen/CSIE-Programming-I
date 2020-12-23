#include "hw6.h"
#define i32 int32_t
//hw0601
//hw0602
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
