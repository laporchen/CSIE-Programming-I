#pragma once
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define intt int32_t
//hw0501
void sortA(intt[], intt);
void sortD(intt[], intt);
void split(intt[], intt[], intt[], intt);
//hw0502
void matrixR(intt[4][4]);
//hw0503
intt func();
void printp(intt[], intt);
//hw0504

//hw0505
intt allInput(intt *width, intt *height, intt *mine);
intt input(intt *a, intt range0, intt range1);
intt getChoice(intt *o, intt *c, intt *r, intt width, intt height, intt *open);
intt getunOpenSquare(intt *open, intt w, intt h);
void drawGrid(intt *num, intt w, intt h, intt *open);
void modifySquare(intt *game, intt *mine, intt *open, intt x, intt y, intt w, intt h, intt option);
void game();
