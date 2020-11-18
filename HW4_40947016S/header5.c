#include "header5.h"
#include "stdint.h"
#include "stdio.h"
#define intt int32_t

intt getCode()
{
    intt a[4]; //four digits
    intt result = 0;
    int used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    a[0] = rand() % 9 + 1;
    used[a[0]] = 1;
    result += a[0] * 1000;
    int pow = 100;
    for (intt i = 1; i < 4; i++)
    {
        while (1)
        {
            a[i] = rand() % 10;
            if (used[a[i]] != 1)
            {
                used[a[i]] = 1;
                break;
            }
        }
        result += a[i] * pow;
        pow /= 10;
    }
    return result;
}
intt checkInput(intt a)
{
    intt used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (intt i = 0; i < 4; i++)
    {
        if (used[a % 10] != 1)
        {
            used[a % 10] = 1;
        }
        else
        {
            return 0;
        }
        a /= 10;
    }
    return 1;
}
intt getInput()
{
    intt input;
    if (scanf("%d", &input) != 1 || (input > 9999 || input < 1000))
    {
        return -1;
    }
    if (checkInput(input) == 0)
    {
        return -1;
    }
    return input;
}
intt correct(intt input, intt ans)
{
    if (input == ans)
    {
        printf("\033[0m");
        printf("Your Guess: %d\nResponse: ", input);
        printf("\033[1;32m");
        printf("BINGO! Congratulations.\n");
        printf("\033[0m");
        return 1;
    }
    else
    {
        intt A = 0, B = 0;
        intt shown[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        intt in[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        intt ansM = ans, inputM = input;
        for (intt i = 0; i < 4; i++)
        {
            if (ansM % 10 == inputM % 10)
            {
                A++;
            }
            in[inputM % 10] = 1;
            shown[ansM % 10] = 1;
            ansM /= 10;
            inputM /= 10;
        }
        for (intt i = 0; i < 10; i++)
        {
            if (in[i] == 1 && in[i] == shown[i])
            {
                B++;
            }
        }
        B -= A;
        printf("\033[0m");
        printf("Your Guess: %d\nResponse: ", input);
        printf("\033[0;31m");
        printf("%d A ", A);
        printf("\033[0;34m");
        printf("%d B", B);
        printf("\033[0m\n");
    }

    return 0;
}
intt game(intt input, intt answer)
{
    intt round = 1;
    while (1)
    {
        printf("Round %4d >>>", round);
        intt input = getInput();
        if (input == -1)
        {
            printf("\033[0;31m");
            printf("Invalid guess\n");
            printf("\033[0m");
            round++;
            continue;
        }
        if (correct(input, answer) == 1)
        {
            break;
        }
        round++;
    }
    return 0;
}