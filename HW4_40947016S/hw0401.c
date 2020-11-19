#include "hw4.h"
int main()
{
    int32_t n;
    printf("Please enter a number (1-3000): ");
    if (scanf("%d", &n) != 1 || (n < 1 || n > 3000))
    {
        printf("ERROR\n");
        return 0;
    }
    getRoman(n);
    return 0;
}
