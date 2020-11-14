#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
bool statInput();
void showmap();
char map[80][20];
int32_t hhp,hatk,hm,dhp,datk,dm,px = 1,py =1,x = 1,y = 1;
bool getout = false;
void move();
void stats();
int32_t input();
int main()
{
    for(int32_t i = 0;i<20;i++)
        for(int32_t j = 0;j<80;j++)
        {
            if(i== 0 || i == 19)
                map[j][i] = '-';
            else if(j == 0 || j == 79)
                 map[j][i] = '|';
            else
            {
                 map[j][i] = ' ';
            }
            
        }
    map[1][1] = 'H';
    map[78][18] = 'D'; 
    if(statInput())
    {
        printf("ERROR\n");
        return 0;
    }
    while(!getout)
    {
        showmap(); 
        int32_t m = input();
        if(m == 5)
        {
            getout = true;
            break;
        }
        if(m == 1)
        {
            move();
        }
        if(m == 4)
        {
            stats();
        }
    }
    return 0;
}
void move()
{
    int32_t mv,range;
    printf("Up (1) or Down (2): ");
    if(scanf("%d",&mv) !=1 || (mv>2||mv<1))
    {
        printf("Invaild Input. Now exiting.\n");
        getout = true;
        return;
    }
    printf("Range (0 -%d): ",hm);
    if(scanf("%d",&range) !=1 || (range>hm||mv<0))
    {
        printf("Invaild Input. Now exiting.\n");
        getout = true;
        return;
    }
    map[x][y] = ' ';
    if(mv == 1)
    {
        if(y-range <= 1)
        {
            printf("Hero is out of boundary. Now exiting.\n");
            getout = true;
            return;
        }
        px = x;
        py = y;
        map[x][y-range]= 'H';
        y = y - range;
    }
    if(mv ==2)
    {
            if(y+range >= 19)
        {
            printf("Hero is out of boundary. Now exiting.\n");
            getout = true;
            return;
        }
        px = x;
        py = y;
        map[x][y+range]= 'H';
        y = y + range;
    }
    printf("Left (1) or Right (2): ");
    if(scanf("%d",&mv) !=1 || (mv>2||mv<1))
    {
        printf("Invaild Input. Now exiting.\n");
        getout = true;
        return;
    }
    printf("Range (0 -%d): ",hm);
    if(scanf("%d",&range) !=1 || (range>hm||mv<0))
    {
        printf("Invaild Input. Now exiting.\n");
        getout = true;
        return;
    }
    map[x][y] = ' ';
    if(mv == 1)
    {
        if(x-range <= 1)
        {
            printf("Hero is out of boundary. Now exiting.\n");
            getout = true;
            return;
        }
        px = x;
        py = y;
        map[x-range][y] = 'H';
        x = x - range;
    }
    if(mv == 2)
    {
        if(x+range >= 79)
        {
            printf("Hero is out of boundary. Now exiting.\n");
            getout = true;
            return;
        }
        px = x;
        py = y;
        map[x+range][y]= 'H';
        x = x + range;
    }
    return;
}
int32_t input()
{
    int32_t m;
    printf("1)Move\n2)Attack\n3)Magic\n4)Status\n5)exit\nYour Choice (1-5) : ");
    if(scanf("%d",&m)!= 1||(m<1||m>5))
    {
        printf("Invaild Input. Now exiting.\n");
        return 5;
    }
    return m;

}
bool statInput()
{
    printf("Hero 's HP (50 -255): ");
    if(scanf("%d",&hhp) != 1|| (hhp<50 || hhp >255) )
    {
        return true;
    }
    printf("Hero 's ATK (1 -50): ");
    if(scanf("%d",&hatk) != 1|| (hatk<1 || hatk >50) )
    {
        return true;
    }
    printf("Hero 's Move (3 -6): ");
    if(scanf("%d",&hm) != 1|| (hm<3 || hm >6) )
    {
        return true;
    }
    printf("Dragon 's HP (100 -1024): ");
    if(scanf("%d",&dhp) != 1|| (dhp<100 || dhp >1024 ))
    {
        return true;
    }
    printf("Dragon 's ATK (1 -70): ");
    if(scanf("%d",&datk) != 1|| (datk<1 || datk >70) )
    {
        return true;
    }
    printf("Dragon 's Move (2 -5): ");
    if(scanf("%d",&dm) != 1|| (dm<2 || dm >5) )
    {
        return true;
    }
    return false;
}
void showmap()

{
    for(int32_t i =0;i<20;i++)
    {
        for(int32_t j =0;j<80;j++)
        {
            printf("%c",map[j][i]);
        }
        printf("\n");
    }
       
}
void stats()
{
    printf("Hero Status\nHP: %d, Max HP: %d\nMove: %d\nAttack : %d\nMagic : 1\n=====\nDragon Status\nHP: %d , Max HP: %d\nMove: %d Attack : %d\n",hhp,hhp,hm,hatk,dhp,dhp,dm,datk);
    return ;
}