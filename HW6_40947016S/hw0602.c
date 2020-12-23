#include "hw6.h"

int main()
{
	double x,y,theta;
	printf("Please enter a point : ");
	scanf("%lf %lf",&x,&y);
	printf("Please enter theta : ");
	scanf("%lf",&theta);
	rotate(&x,&y,theta);
	printf("%.2lf %.2lf\n",x,y);
	return 0;
}
