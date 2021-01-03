#pragma once
#include "math.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#define i8 int8_t
#define i32 int32_t
#define i64 int64_t
//hw0601
void printChoice(i64 *input);
void numModify(i64 *input, i32 choice, uint32_t change);
//hw0602
void printNum(i32 *, i32);
void redo(i32 *index);
void undo(i32 *index);
void moveback(i32 *arr);
//hw0603
void rotate(double *x, double *y, double theta);
//hw0604
//hw0605
