#include "hw4.h"
#define intt int32_t
//hw0401
void getRoman(int32_t n)
{
    char tableT[3][3] = {"M", "MM", "MMM"};
    char tableH[9][4] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char tableTe[9][4] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char tableU[9][4] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int32_t index;
    index = n / 1000;
    printf("%d in Roman Number: ", n);
    if (index != 0)
    {
        for (int32_t i = 0; i < 3; i++)
            printf("%c", tableT[index - 1][i]);
    }
    n %= 1000;
    index = n / 100;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableH[index - 1][i]);
    }
    n %= 100;
    index = n / 10;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableTe[index - 1][i]);
    }
    n %= 10;
    index = n / 1;
    if (index != 0)
    {
        for (int32_t i = 0; i < 4; i++)
            printf("%c", tableU[index - 1][i]);
    }
    printf("\n");
}
//hw0402
void hanoi_re(intt num, intt source, intt spare, intt target, intt disk)
{
    //source spare target 0,1,2
    if (num == 1)
    {
        printf("Move disk %d to rod %d.\n", disk, target);
    }
    else
    {
        hanoi_re(num - 1, source, target, spare, num - 1);
        hanoi_re(1, source, spare, target, num);
        hanoi_re(num - 1, spare, source, target, num - 1);
    }
    return;
}
void hanoi_it(intt num)
{
    int A, B, C, exA, exB, exC;
    A = 1;
    B = 21;
    C = 21;
    exA = 2;
    exB = B;
    exC = C;
    if (num % 2 == 0)
    {
        for (intt i = 0; i < mv(num); i++)
        {
            if (A < B)
            {
                printf("Move disk %d to rod 2.\n", A);
                exB = B;
                B = A;
                A++;
                exA++;
                if (exA > num)
                {
                    A = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 1.\n", B);
                exA = A;
                A = B;
                B++;
                exB++;
                if (exB > num)
                {
                    B = 21;
                }
            }
            i++;
            if (i >= mv(num))
                break;
            if (A < C)
            {
                printf("Move disk %d to rod 3.\n", A);
                exC = C;
                C = A;
                A++;
                exA++;
                if (exA > num)
                {
                    A = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 1.\n", C);
                exA = A;
                A = C;
                C++;
                exC++;
                if (exC > num)
                {
                    C = 21;
                }
            }
            i++;
            if (i >= mv(num))
                break;
            if (B < C)
            {
                printf("Move disk %d to rod 3.\n", B);
                exC = C;
                C = A;
                B++;
                exB++;
                if (exB > num)
                {
                    B = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 2.\n", C);
                exB = B;
                B = C;
                C++;
                exC++;
                if (exC > num)
                {
                    C = 21;
                }
            }
        }
    }
    else
    {
        for (intt i = 0; i < mv(num); i++)
        {
            if (A < C)
            {
                printf("Move disk %d to rod 3.\n", A);
                exC = C;
                C = A;
                A++;
                exA++;
                if (exA > num)
                {
                    A = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 1.\n", C);
                exA = A;
                A = C;
                C++;
                exC++;
                if (exC > num)
                {
                    C = 21;
                }
            }
            i++;
            if (i >= mv(num))
                break;
            if (A < B)
            {
                printf("Move disk %d to rod 2.\n", A);
                exB = B;
                B = A;
                A++;
                exA++;
                if (exA > num)
                {
                    A = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 1.\n", B);
                exA = A;
                A = B;
                B++;
                exB++;
                if (exB > num)
                {
                    B = 21;
                }
            }
            i++;
            if (i >= mv(num))
                break;
            if (B < C)
            {
                printf("Move disk %d to rod 3.\n", B);
                exC = C;
                C = B;
                B++;
                exB++;
                if (exB > num)
                {
                    B = 21;
                }
            }
            else
            {
                printf("Move disk %d to rod 2.\n", C);
                exB = B;
                B = C;
                C++;
                exC++;
                if (exC > num)
                {
                    C = 21;
                }
            }
        }
    }

    return;
}
int32_t mv(intt n)
{
    int r = 1;
    for (intt i = 0; i < n; i++)
        r *= 2;
    return r - 1;
}
void hanoi_it_v(intt n)
{
    intt A[21], B[21], C[21];
    //init array
    intt passingV = n;
    A[20] = 21, B[20] = 21, C[20] = 21;
    for (intt i = 0; i < 20; i++)
    {
        if (i < n)
        {
            A[19 - i] = passingV;
            B[i] = 0;
            C[i] = 0;
            passingV--;
        }
        else
        {
            A[19 - i] = 0;
            B[i] = 0;
            C[i] = 0;
        }
    }
    intt moves = mv(n);
    if (n % 2 == 0)
    {
        for (intt i = 0; i < moves; i++)
        {
            if (A[gT(A)] < B[gT(B)])
                move(A, B, 2);
            else
                move(B, A, 1);
            i++;
            if (A[gT(A)] < C[gT(C)])
                move(A, C, 3);
            else
                move(C, A, 1);
            i++;
            if (i >= moves)
                break;
            if (i >= moves)
                break;
            if (B[gT(B)] < C[gT(C)])
                move(B, C, 3);
            else
                move(C, B, 2);
        }
    }
    else
    {
        for (intt i = 0; i < moves; i++)
        {
            if (A[gT(A)] < C[gT(C)])
                move(A, C, 3);
            else
                move(C, A, 1);
            i++;
            if (i >= moves)
                break;
            if (A[gT(A)] < B[gT(B)])
                move(A, B, 2);
            else
                move(B, A, 1);
            i++;
            if (i >= moves)
                break;
            if (B[gT(B)] < C[gT(C)])
                move(B, C, 3);
            else
                move(C, B, 2);
        }
    }
}
intt getEmpty(intt *pole)
{
    for (int i = 0; i < 21; i++)
        if (pole[i] != 0)
        {
            //printf("Empty is %d\n", i - 1);
            return i - 1;
        }
    printf("Empty is 19\n");
    return 19;
}
intt gT(intt *pole)
{
    for (int i = 0; i < 21; i++)
        if (pole[i] != 0)
        {
            //printf("Top is %d\n", pole[i]);
            return i;
        }

    return 21;
}
void move(intt *s, intt *d, intt rod)
{
    printf("Move disk %d to rod %d\n", s[gT(s)], rod);
    d[getEmpty(d)] = s[gT(s)];
    s[gT(s)] = 0;
}
//hw0403
void go()
{
    int64_t k;
    double result = 0;
    printf("k-th order Taylor polynomial for e\nPlease enter k: ");
    if (scanf("%ld", &k) != 1 || k <= 0)
    {
        printf("ERROR\n");
        return;
    }
    for (intt i = 0; i < k + 1; i++)
    {
        result += 1 / getFactorial(i);
    }
    printf("%.20lf\n", result);
    return;
}
double getFactorial(int64_t n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * getFactorial(n - 1);
    }
}
//hw0404
double rq(double r, int32_t n)
{
    double result = 0;
    for (int32_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            result += r * 2;
        }
        else
        {
            result = 1 / (1 / result + 1 / r);
            result += r;
        }
    }
    return result;
}
//hw0405
intt getCode()
{
    srand(time(NULL));
    intt a[4]; //four digits
    intt result = 0;
    int used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int pow = 1000;
    for (intt i = 0; i < 4; i++)
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
    if (scanf("%d", &input) != 1 || (input > 9999 || input < 0))
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
        if (input < 1000)
            printf("Your Guess: 0%d\nResponse: ", input);
        else
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
        if (input < 1000)
            printf("Your Guess: 0%d\nResponse: ", input);
        else
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
        printf("Round %4d >>> ", round);
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