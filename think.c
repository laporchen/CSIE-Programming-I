#include "stdint.h"
#include "unistd.h"
#include "stdlib.h"
#include <stdio.h>
#define intt int32_t

int main()
{
	int a = 2;
	int b = a+ 20;
	int c = 0;
	for(int i = 0;i<b;i++)
	{
	 c++;
	 for(int g = 0;g<c;g++)
	 	printf("\\");
	 printf("/");
	 for(int j =c+1;j<b;j++)
	 	printf("\\");
	
	 for(int p = b;p>c+1;p--)
	 	printf("/");
	 printf("\\");
	 for(int r = c;r>0;r--)
	 	printf("/");
	
	 printf("\n");

	}
	a = 2;
	b = a+20;
	c = 0;
	for(int i = 0;i<b;i++)
	{
	 c++;
		for(int p = b;p>c+1;p--)
	 		printf("/");
	 printf("\\");
	 for(int r = c;r>0;r--)
	 	printf("/");

	 for(int g = 0;g<c;g++)
	 	printf("\\");
	 printf("/");
	 for(int j =c+1;j<b;j++)
	 	printf("\\");
	
	
	 printf("\n");
	}	
	
	return 0;

}

