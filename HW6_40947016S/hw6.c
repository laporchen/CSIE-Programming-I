#include "hw6.h"
#define i8 int8_t
#define ui8 uint8_t
#define i32 int32_t
#define i64 int64_t
//hw0601
void printChoice(i64 *input)
{
	ui8 *splitter = (ui8 *)input;
	for (i32 i = 0; i < 8; i++)
		printf("(%d) 0x%02X ", i + 1, *(splitter + i));
	printf("\n");

	return;
}
void numModify(i64 *input, i32 choice, uint32_t change)
{
	ui8 *modify = (ui8 *)input;
	*(modify + choice - 1) = change;
}
//hw0603
void rotate(double *x, double *y, double theta)
{
	double d = (theta * (-1) * M_PI) / 180, rx = *x, ry = *y;
	*x = rx * cos(d) - ry * sin(d);
	*y = rx * sin(d) + ry * cos(d);
	return;
}
