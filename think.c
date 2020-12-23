#include "stdint.h"
#include "unistd.h"
#include "stdlib.h"
#include <stdio.h>
#define intt int32_t

void nn(int **p,int s);

int main()
{
	int a;
	printf("Give me a number: ");
	scanf("%d",&a);
	int *ptr = NULL;
	nn(&ptr,a);
	for(int i = 0;i<a * a;i++)
	{
		printf("%4d",*(ptr+i));
		if(i%a== a-1)
			printf("\n");
	}
}
void nn(int * *p,int s)
{
	*p =  calloc(sizeof(int32_t),s);
	for(int i = 0;i<s;i++)
	{
		for(int j = 0;j<s;j++)
			*(*p + i*s + j) = (i+1) *(j+1); 
	}
	return;

}
