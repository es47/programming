#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N[4][4];
void illustrate(void)
{
    printf("玩法說明:\n");
    printf("每輸入一個值，請再按 Enter 。\n");
    printf("在4 x 4大小的格子中，遊戲一開始會出現兩個數字，\n");
    printf("之後每次移動都會隨機出現一個新的數字。\n");
    printf("這個數字會是2或4。\n");
    printf("你能操作的選項只有4種：上、下、左、右\n");
    printf("(上:『w』、下:『s』、左:『a』、右:『d』)，\n");
    printf("移動時，是場上所有數字都一起向那個方向移動。\n");
    printf("當兩個相同的數字碰在一起時會合併。\n");
    printf("兩個「2」碰在一起時，會變成「4」。\n");
    printf("輸入'e'時，遊戲結束。\n");
    printf("請輸入'b'開始遊戲。\n");
}
void up(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 1; j < 4; j++)
        {
            if (j >= 1)
            {
                if (N[j][i] == N[j - 1][i] && x != j - 1 && N[j][i] != 0)
                {
                    N[j - 1][i] *= 2;
                    N[j][i] = 0;
                    x = j - 1;
                }
                else
                {
                    if(N[j][i] != 0 && N[j - 1][i] == 0)
                    {
                        N[j - 1][i] = N[j][i];
                        N[j][i] = 0;
                        j -= 2;
                    }
                }
            }
        }
    }
}
void down(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 2; j >= 0; j--)
        {
            if (j <= 2)
            {
                if (N[j][i] == N[j + 1][i] && x != j + 1 && N[j][i] != 0)
                {
                    N[j + 1][i] *= 2;
                    N[j][i] = 0;
                    x = j + 1;
                }
                else
                {
                    if(N[j][i] != 0 && N[j + 1][i] == 0)
                    {
                        N[j + 1][i] = N[j][i];
                        N[j][i] = 0;
                        j += 2;
                    }
                }
            }
        }
    }
}
void left(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 1; j < 4; j++)
            if (j >= 1)
            {
                if (N[i][j] == N[i][j - 1] && x != j - 1 && N[i][j] != 0)
                {
                    N[i][j - 1] *= 2;
                    N[i][j] = 0;
                    x = j - 1;
                }
                else
                {
                    if(N[i][j] != 0 && N[i][j - 1] == 0)
                    {
                        N[i][j - 1] = N[i][j];
                        N[i][j] = 0;
                        j -= 2;
                    }
                }
            }
    }
}
void right(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 2; j >= 0; j--)
            if (j <= 2)
            {

                if (N[i][j] == N[i][j + 1] && x != j + 1 && N[i][j] != 0)
                {
                    N[i][j + 1] *= 2;
                    N[i][j] = 0;
                    x = j + 1;
                }
                else
                {
                    if(N[i][j] != 0 && N[i][j + 1] == 0)
                    {
                        N[i][j + 1] = N[i][j];
                        N[i][j] = 0;
                        j += 2;
                    }
                }
            }
    }
}
int none(int N[][4])
{
    int i, j, flag;
    flag = 1;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (N[i][j] == 0)
                flag = 0;
            if (flag == 0) break;
        }
    return flag;
}
int next(int N[][4], int flag)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (N[i][j] == N[i + 1][j] || N[i][j] == N[i][j + 1])
                flag = 2;
            if (flag == 2) break;
        }
        if (flag == 2) break;
    }
    if (flag != 2)
    {
        j = 0;
        i = 3;
        while(j < 3)
        {
            for (j = 0; j < 3; j++)
            {
                if (N[i][j] == N[i][j + 1] || N[j][i] == N[j + 1][i])
                    flag = 2;
                if (flag == 2) break;
            }
            if (flag == 2) break;
        }
    }
    return flag;
}
int main()
{
    int i, j, flag, a, b, row, col, row2, col2;
    int move, fr;
    char x, y;
    illustrate();
    while (1)
    {
        scanf("%s", &y);
        if (y == 'b' || y == 'e') break;
        if (y != 'b' || y != 'e')
        {
            printf("Warning !!      ");
            printf("請再次輸入正確值。\n");
        }
    }
    if (y == 'e')
    {
        while (y != 'b')
        {
            printf("是否要離開遊戲?\n");
            printf("開始遊戲請輸入 b ，並按 Enter 。\n");
            printf("離開遊戲請輸入 e ，並按 Enter 。\n");
            scanf("%s", &y);
            if (y == 'e') break;
            if (y != 'b' && y != 'e')
            {
                printf("Warning !!      ");
                printf("請再次輸入正確值。\n");
            }
        }
        if (y == 'e')
            printf("感謝開啟  ~  ~  (^_^)");
    }
    while(y != 'e')
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                N[i][j] = 0;
        move = 0;
        while (y == 'b')
        {
            srand(time(NULL));
            a = (rand() % 2) + 1;
            b = (rand() % 2) + 1;
            a *= 2;
            b *= 2;
            row = (rand() % 4);
            col = (rand() % 4);
            row2 = (rand() % 4);
            col2 = (rand() % 4);
            if (move == 0)
            {
                N[row][col] = a;
                N[row2][col2] = b;
                move++;
            }
            else
            {
                while (1)
                {
                    scanf("%s", &x);
                    if (x == 'w' || x == 's' || x == 'a' || x == 'd' || x == 'e') break;
                    if (x != 'w' || x != 's' || x != 'a' || x != 'd' || x != 'e')
                    {
                        printf("Warning !!      ");
                        printf("請再次輸入正確值。\n");
                    }
                }
                if (x == 'e')
                {
                    while (x != 'n')
                    {
                        printf("是否要結束此局?\n");
                        printf("確定請輸入 y ，並按 Enter 。\n");
                        printf("繼續請輸入 n ，並按 Enter 。\n");
                        scanf("%s", &x);
                        if (x == 'y') break;
                        if (x != 'y' && x != 'n')
                        {
                            printf("Warning !!      ");
                            printf("請再次輸入正確值。\n");
                        }
                    }
                }
                if (x == 'y') break;
                if (x == 'w')
                    up(N);
                if (x == 's')
                    down(N);
                if (x == 'a')
                    left(N);
                if (x == 'd')
                    right(N);
                fr = 0;
                flag = 0;
                if (x == 'w' || x == 's' || x == 'a' || x == 'd')
                {
                    while(fr == 0)
                    {
                        if (none(N) == 1) break;
                        if (N[row][col] == 0)
                        {
                            N[row][col] = a;
                            fr = 1;
                        }
                        else
                        {
                            row = (rand() % 4);
                            col = (rand() % 4);
                        }
                    }
                    move++;
                }
            }
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (N[i][j] >= 0 && N[i][j] <= 8)
                        printf("   %d   ", N[i][j]);
                    if (N[i][j] >= 16 && N[i][j] <= 64)
                        printf("  %d   ", N[i][j]);
                    if (N[i][j] >= 128 && N[i][j] <= 512)
                        printf("  %d  ", N[i][j]);
                    if (N[i][j] == 1024)
                        printf(" %d  ", N[i][j]);
                    if (j == 3 & i == 1)
                        printf("        移動 %d 次", move - 1);
                    if (j == 3)
                        printf("\n");
                }
            flag = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (N[i][j] == 2048)
                        flag = 1;
                    if(N[i][j] == 0)
                        flag = 2;
                    if(flag == 1) break;
                }
                if(flag == 1) break;
            }
            if(flag == 0)
                flag = next(N, flag);
            if(flag == 1)
            {
                printf("You win\n");
                printf("!!恭喜達到 2048 !!\n");
            }
            if(flag == 0)
            {
                printf("Game over\n");
                printf("加油!\n");
                printf("請輸入 b 重新開始，\n");
                printf("或輸入 e 離開遊戲。\n");
            }
            if(flag != 2) break;
        }
        if (x == 'y')
        {
            while (y != 'e')
            {
                printf("是否要開始新的一局?\n");
                printf("新的一局請輸入 b ，並按 Enter 。\n");
                printf("離開遊戲請輸入 e ，並按 Enter 。\n");
                scanf("%s", &y);
                if (y == 'b') break;
                if (y != 'b' && y != 'e')
                {
                    printf("Warning !!      ");
                    printf("請再次輸入正確值。\n");
                }
            }
        }
        if (y == 'e')
            printf("感謝遊玩  ~  ~  (^///^)");
    }
}
