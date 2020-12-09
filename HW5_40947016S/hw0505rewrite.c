#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define intt int32_t
intt allInput(intt *width, intt *height, intt *mine);
intt input(intt *a, intt range0, intt range1);
intt getChoice(intt *o, intt *c, intt *r, intt width, intt height, intt *open);
void drawGrid(intt *num, intt w, intt h, intt *open);
void modifySquare(intt *game, intt *mine, intt *open, intt x, intt y, intt w, intt h, intt option);
void game();
int main()
{
    game();
    return 0;
}

void game()
{
    srand(time(NULL));
    intt w, h, mine;
    if (allInput(&w, &h, &mine))
        return;
    intt map[h][w];              //showing on screen,also saving flag placement
    intt open[h][w];             //checking is the square opened
    intt num[h][w];              //store mine place and mine counter
    for (intt i = 0; i < h; i++) //init arrays
    {
        for (intt j = 0; j < w; j++)
        {
            num[i][j] = 0;
            map[i][j] = 0;
            open[i][j] = 0;
        }
    }
    intt mx, my; //random location for mine
    while (mine) //init mine location
    {
        mx = rand() % w;
        my = rand() % h;
        if (num[my][mx] == 0)
        {
            num[my][mx] = -1;
            mine--;
        }
    }
    for (intt i = 0; i < h; i++) //caculate mine counter
    {
        for (intt j = 0; j < w; j++)
        {
            if (num[i][j] == -1)
                continue;
            intt counter = 0;
            for (intt p = -1; p < 2; p++)
                for (intt q = -1; q < 2; q++)
                {
                    if ((p + i) * (q + j) < 0 || p + i >= h || q + j >= w)
                        continue;
                    if (num[p + i][q + j] == -1)
                        counter++;
                }
            num[i][j] = counter;
        }
    }
    intt game = 1; //check whether the game is end
    intt option;   //get player's choice(1 is open,2 is flag)
    intt x, y;     //chosen square
    while (game)
    {
        drawGrid(&num[0][0], w, h, &open[0][0]);
        getChoice(&option, &y, &x, w, h, &open[0][0]);
        modifySquare(&game, &num[0][0], &open[0][0], x, y, w, h, option);
    }
    if (game == 0)
    {
        printf("\033[1;31mYou hit a mine,You lose.\n");
        return;
    }
}
intt allInput(intt *width, intt *height, intt *mine)
{
    printf("Please enter the width  (10-16): ");
    if (input(width, 10, 16))
        return 1;
    printf("Please enter the height (10-16): ");
    if (input(height, 10, 16))
        return 1;
    printf("Please enter the mine number (30-90): ");
    if (input(mine, 10, 90))
        return 1;
}
intt input(intt *a, intt range0, intt range1)
{
    if (scanf("%d", a) != 1 || (*a < range0 || *a > range1))
    {
        printf("ERROR\n");
        return 1;
    }
    return 0;
}
intt getChoice(intt *o, intt *x, intt *y, intt width, intt height, intt *open)
{

    while (1)
    {
        printf("Your Option (1:Open, 2: Flag): ");
        if (!input(o, 1, 2))
            break;
    }
    while (1)
    {
        printf("Position (row,column): ");
        if (!input(y, 0, width - 1) && !input(x, 0, height - 1))
        {
            intt *openloc = ((open + *y * height) + *x);
            if (*o == 1 && *openloc == 1)
                printf("Square is already opened.\n");
            else if (*o == 1 && *openloc == 2)
                printf("Square is flagged.\n");
            else
            {
                break;
            }
        }
    }
    return 1;
}
void drawGrid(intt *num, intt w, intt h, intt *open)
{
    { //index print
        printf("    ");
        for (intt i = 0; i < w; i++)
        {
            printf("%3d", i);
        }
        printf("\n");
        for (intt i = 0; i < w * 3 + 5; i++)
        {
            printf("-");
        }
        printf("\n");
    }

    intt color[8] = {34, 32, 31, 35, 36, 33, 43, 41};
    for (intt j = 0; j < h; j++)
    {
        printf("%3d|", j);
        for (intt i = 0; i < w; i++)
        {
            printf("\033[0;39m");
            if (*((open + i * h) + j) == 2)
            {
                printf("  \033[1;47m\033[1;31mF");
                continue;
            }
            if (*((open + i * h) + j) == 1)
            {
                if (*((num + i * h) + j) != 0)
                {
                    printf("\033[0;%dm%3d", color[*((num + i * h) + j) - 1], *((num + i * h) + j));
                }
            }
            else if (*((open + i * h) + j) == 0)
                printf("  *");
        	printf("\033[0;39m");
	}
        printf("\n");
    }
}
void modifySquare(intt *game, intt *mine, intt *open, intt x, intt y, intt w, intt h, intt option)
{
    intt *openloc = ((open + y * h) + x);
    intt *mineloc = ((mine + y * h) + x);
    if (option == 1)
    {
        if (*mineloc == -1)
        {
            *game = 0;
            return;
        }
        if (*mineloc != 0)
        {
            *openloc = 1;
            return;
        }
        if (*mineloc == 0)
        {
            *openloc = 1;
            intt xo[2] = {-1, 1};
            intt yo[2] = {-1, 1};
            if (!((y + yo[0]) * (x) < 0 || (y + yo[0]) >= h - 1 || (x) >= w - 1))
                modifySquare(game, mine, open, x, y + yo[0], w, h, 3);
            if (!((y + yo[1]) * (x) < 0 || (y + yo[1]) >= h - 1 || (x) >= w - 1))
                modifySquare(game, mine, open, x, y + yo[1], w, h, 3);
            if (!((y) * (x + xo[0]) < 0 || (y >= h - 1 || (x) + xo[0] >= w - 1)))
                modifySquare(game, mine, open, x + xo[0], y, w, h, 3);
            if (!((y) * (x + xo[1]) < 0 || (y >= h - 1 || (x) + xo[1] >= w - 1)))
                modifySquare(game, mine, open, x + xo[1], y, w, h, 3);
        }
    }

    else if (option == 2)
    {
        if (*openloc == 2)
            *openloc = 0;
        else
            *openloc = 2;
        return;
    }
    else if (option == 3)
    {
        if (*mineloc == -1)
        {
            return;
        }
        if (*mineloc != 0)
        {
            *openloc = 1;
            return;
        }
        if (*mineloc == 0)
        {
            *openloc = 1;
            intt xo[2] = {-1, 1};
            intt yo[2] = {-1, 1};
            if (!((y + yo[0]) * (x) < 0 || (y + yo[0]) >= h - 1 || (x) >= w - 1))
                modifySquare(game, mine, open, x, y + yo[0], w, h, 3);
            if (!((y + yo[1]) * (x) < 0 || (y + yo[1]) >= h - 1 || (x) >= w - 1))
                modifySquare(game, mine, open, x, y + yo[1], w, h, 3);
            if (!((y) * (x + xo[0]) < 0 || (y >= h - 1 || (x) + xo[0] >= w - 1)))
                modifySquare(game, mine, open, x + xo[0], y, w, h, 3);
            if (!((y) * (x + xo[1]) < 0 || (y >= h - 1 || (x) + xo[1] >= w - 1)))
                modifySquare(game, mine, open, x + xo[1], y, w, h, 3);
        }
		return;
         }
    }
