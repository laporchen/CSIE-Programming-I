#include "stdint.h"
#include "stdio.h"
#include <stdbool.h>
int main()
{
    bool usedCard[52];
    for (int32_t i = 0; i < 52; i++)
    {
        usedCard[i] = false;
    }
    int32_t c[5];
    printf("Please enter 5 cards: ");
    if (scanf("%d %d %d %d %d", &c[0], &c[1], &c[2], &c[3], &c[4]) != 5)
    {
        printf("Invaild input.\n");
        return 0;
    }
    for (int32_t i = 0; i < 5; i++) //Check duplicated card
    {
        if (usedCard[c[i]])
        {
            printf("Invaild input(Duplicated cards).\n");
            return 0;
        }
        else if (c[i] > 52 || c[i] < 1)
        {
            printf("Invaild input(Out of range).\n");
            return 0;
        }
        else
        {
            usedCard[c[i]] = true;
        }
        c[i]--;
    }
    for (int32_t i = 0; i < 5; i++)
    {

        for (int32_t j = 0; j < 4 - i; j++)
        {
            if (c[j + 1] < c[j])
            {
                int32_t tmp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = tmp;
            }
        }
    }
    int32_t result;
    bool rf = true;
    //straight flush
    for (int32_t i = 1; i < 4; i++)
    {
        if (c[i] + 1 != c[i + 1] || c[i] / 13 != c[i + 1] / 13)
        {
            rf = false;
            break;
        }
    }
    if (rf)
    {
        if (c[0] / 13 == c[1] / 13 && c[0] + 12 == c[4])
        {
            printf("Straight flush\n");
            return 0;
        }
        else if (c[0] / 13 == c[1] / 13 && c[0] + 1 == c[1])
        {
            printf("Straight flush\n");
            return 0;
        }
    }

    bool f = true;
    //four of a kind
    int32_t samecard[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool foak = false;
    for (int32_t i = 0; i < 5; i++)
    {
        samecard[c[i] % 13]++;
    }
    for (int32_t i = 0; i < 13; i++)
    {
        if (samecard[i] == 4)
        {
            foak = true;
            break;
        }
    }
    if (foak)
    {
        printf("Four of a kind\n");
        return 0;
    }
    //two pair,three of a kind, one pair,full house
    int32_t pair = 0;
    bool threecard = false;
    for (int32_t i = 0; i < 13; i++)
    {
        if (samecard[i] == 2)
        {
            pair++;
        }
        if (samecard[i] == 3)
        {
            threecard = true;
        }
    }
    if (pair == 2)
    {
        printf("Two pair\n");
        return 0;
    }
    else if (pair == 1 && threecard)
    {
        printf("Full house\n");
        return 0;
    }
    else if (threecard && pair == 0)

    {
        printf("Three of a kind\n");
        return 0;
    }
    else if (!threecard && pair == 1)
    {
        printf("One pair\n");
        return 0;
    }
    //flush
    bool flush = true;
    int32_t pip = c[0] / 13;
    for (int32_t i = 1; i < 5; i++)
    {
        if (c[i] / 13 != pip)
        {
            flush = false;
            break;
        }
    }
    if (flush)
    {
        printf("Flush\n");
        return 0;
    }
    //straight
    bool straight = true;
    bool check = false;
    for (int32_t i = 0; i < 9; i++)

    {
        if (samecard[i] == 1)
        {
            check = true;
            for (int32_t j = i; j < i + 5; j++)
            {
                if (samecard[j] != 1)
                {
                    straight = false;
                    break;
                }
            }
        }
        if (check)
        {
            break;
        }
    }
    bool straightSpec = true;
    for (int32_t i = 9; i < 13; i++)

    {
        if (samecard[i] != 1)
        {
            straightSpec = false;
            break;
        }
        if (samecard[0] != 1)
        {
            straightSpec = false;
            break;
        }
    }
    if (straight || straightSpec)
    {
        printf("Straight\n");
        return 0;
    }
    printf("High card\n");
    return 0;
}