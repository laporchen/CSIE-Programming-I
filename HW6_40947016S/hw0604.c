#include "hw6.h"
#define i8 int8_t
#define i32 int32_t
#define i64 int64_t

int main()
{
    i32 plane[4]; // x y z c
    double point[3];
    i32 zero = 1;
    printf("Please enter the plane: ");
    for (i32 i = 0; i < 4; i++)
    {
        if (scanf("%d", &plane[i]) != 1)
        {
            printf("ERROR\n");
            return 0;
        }
        if (plane[i] != 0)
        {
            zero = 0;
        }
        if (zero && i == 3)
        {
            printf("ERROR ()\n");
            return 0;
        }
    }
    printPlane(plane);
    printf("Please enter the point: ");
    for (i32 i = 0; i < 3; i++)
    {
        if (scanf("%lf", &point[i]) != 1)
        {
            printf("ERROR\n");
            return 0;
        }
    }
    project(&point[0], &point[1], &point[2], plane[0], plane[1], plane[2], plane[3]);
    return 0;
}