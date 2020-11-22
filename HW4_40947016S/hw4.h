#pragma once
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#define intt int32_t
//hw0401
void getRoman(intt);
//hw0402
void hanoi_re(intt, intt, intt, intt, intt);
void hanoi_it(intt);
void hanoi_it_v(intt);
intt gT(intt pole[]);
intt getEmpty(intt pole[]);
void move(intt s[], intt d[], intt);
intt mv(intt);
//hw0403
void go();
double getFactorial(int64_t);
//hw0404
double rq(double r, intt n);
//hw0405
intt game(intt, intt);    //input, ansCode
intt correct(intt, intt); //input, ansCode
intt getCode();
intt getInput();
intt checkInput(intt);
