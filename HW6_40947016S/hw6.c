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
//hw0602
void printNum(i32 *arr, i32 index)
{
	printf("Result : ");
	for (i32 i = 0; i < index; i++)
	{
		if (*(arr + i) != -1)
		{
			printf("%4d ", *(arr + i));
		}
	}
	printf("\n");
	return;
}
void redo(i32 *index)
{
	*index++;
	return;
}
void undo(i32 *index)
{
	*index--;
	return;
}
void moveback(i32 *arr)
{
	for (i32 i = 1; i < 10; i++)
	{
		*(arr + i - 1) = *(arr + i);
	}
	*(arr + 9) = -1;
	return;
}
//hw0603
void rotate(double *x, double *y, double theta)
{
	double d = (theta * (-1) * M_PI) / 180, rx = *x, ry = *y;
	*x = rx * cos(d) - ry * sin(d);
	*y = rx * sin(d) + ry * cos(d);
	return;
}
//hw0604
//hw0605
i32 checks(ui8 a[], ui8 b[], ui8 c[], ui8 d[])
{
	i32 appearedAll[52] = {0};

	for (i32 i = 0; i < 13; i++)
	{
		if ((a[i] > 52 || a[i] < 1) || appearedAll[a[i]] == 1)
			return 1;
		else
		{
			appearedAll[a[i]] = 1;
		}
		if ((b[i] > 52 || b[i] < 1) || appearedAll[b[i]] == 1)
			return 1;
		else
		{
			appearedAll[b[i]] = 1;
		}
		if ((c[i] > 52 || c[i] < 1) || appearedAll[c[i]] == 1)
			return 1;
		else
		{
			appearedAll[c[i]] = 1;
		}
		if ((d[i] > 52 || d[i] < 1) || appearedAll[d[i]] == 1)
			return 1;
		else
		{
			appearedAll[d[i]] = 1;
		}
	}
	return 0;
}