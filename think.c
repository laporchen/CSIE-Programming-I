#include <stdio.h>
void print_arr(int);
void recursion(int, int, int);
int examine(int, int, int);
int array[5][5];
int count, num; //count數已經填幾格，num數有幾個拉丁方陣
int main()
{
    int N;
    printf("Input N\n");
    scanf("%d", &N);
    int col = 0, row = 0; //col:x , row:y
    recursion(row, col, N);
    printf("Total: %d\n", num);
    return 0;
}

void print_arr(int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j == 0)
                printf("%d", array[i][0]);
            else
                printf("  %d", array[i][j]);
        }
        printf("\n");
    }
}

void recursion(int pos_row, int pos_col, int N)
{
    printf("%d\t", count);
    if (count == N * N)
    {
        count = 0, ++num;
        print_arr(N);
    }
    else
    {
        printf("Hello!\n");
        pos_col %= N;
        for (int i = 1; i <= N; ++i)
        {
            array[pos_row][pos_col] = i;
            if (examine(pos_row, pos_col, N))
            {
                ++count;
                if (pos_col + 1 == N - 1)
                    ++pos_row; //換到下一row(行)
                recursion(pos_row, pos_col + 1, N);
            }
        }
    }
}

int examine(int i, int j, int N)
{

    for (int row = 0; row < N; row++)
    {
        printf("row=%d\tN=%d", row, N);
        if (array[row][j] == array[i][j])
            return 0; //縱向檢查該列有無相同的數字
    }
    for (int col = 0; col < N; col++)
    {
        if (array[i][col] == array[i][j])
            return 0; //橫向檢查該行有無相同的數字
    }
    return 1;
}