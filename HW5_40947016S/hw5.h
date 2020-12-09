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
void game();
intt input(intt *, intt, intt);
intt allInput(intt *width, intt *height, intt *mine);
void drawGrid(intt *a, intt w, intt h, intt *open, intt mode);
intt getChoice(intt *o, intt *r, intt *c, intt width, intt height);
intt modifyGrid(intt *array, intt o, intt r, intt c, intt height, intt mode);
void recursiveBlank(intt *map, intt x, intt y, intt h, intt w, intt *open);
//mode 1 for mine,2 for gui,3 for mine random
