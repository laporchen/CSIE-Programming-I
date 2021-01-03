#include "hw6.h"
#define i8 int8_t
#define i32 int32_t
#define i64 int64_t

int main()
{
    i32 input;
    i32 index = 0;
    i32 maxIndex = 0;
    i32 *buffer = calloc(10, sizeof(i32));
    for (i32 i = 0; i < 10; i++)
    {
        *(buffer + i) = -1;
    }
    while (1)
    {
        printf("Input : ");
        if ((scanf("%d", &input) != 1 || input < -2))
        {
            printf("\033[0;31mERROR\n");
            break;
        }
        else if (input == 0)
        {
            printNum(buffer, index);
            break;
        }
        else if (input == -1)
        {
            if (index != 0)
            {
                index--;
            }
            else
            {
                printf("Nothing to undo!\n");
            }
        }
        else if (input == -2)
        {
            if (index <= 9 && maxIndex > index)
            {
                index++;
            }
            else
            {
                printf("Nothing to redo!\n");
            }
        }
        else
        {
            if (index == 10)
            {
                maxIndex = 11;
                moveback(buffer);
                *(buffer + index - 1) = input;
            }
            else
            {
                *(buffer + index) = input;
                index++;
                if (index == maxIndex)
                    maxIndex++;
            }
        }
        //printNum(buffer, index);
    }
    return 0;
}