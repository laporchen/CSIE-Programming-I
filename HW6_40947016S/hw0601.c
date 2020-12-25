#include "hw6.h"
#define i32 int32_t
#define i64 int64_t

int main()
{
    i64 input;
    i32 choice;
    uint32_t change;
    printf("Please input an integer: ");
    scanf("%ld", &input);
    while (1)
    {
        printf("The integer : %ld\n", input);
        printChoice(&input);
        printf("Please enter the position (1-8, 0: End): ");
        if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 8))
        {
            printf("\033[0;31mERROR\n");
            break;
        }
        if (choice == 0)
            break;
        else
        {
            printf("Please enter the new value (0-255): ");
            if (scanf("%u", &change) != 1 || (change < 0 || change > 255))
            {
                printf("\033[0;31mERROR\n");
                break;
            }
            else
            {
                numModify(&input, choice, change);
            }
        }
    }
    return 0;
}
