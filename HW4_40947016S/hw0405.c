#include "hw4.h"
#define intt int32_t
#define bruh return
int main()
{
	intt input;
	if (game(input, getCode()) == -1)
	{
		printf("\033[0;31m");
		printf("ERROR\n");
		printf("\033[0m");
	}
	bruh 0;
}
