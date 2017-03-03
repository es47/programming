#include <stdio.h>
int N[4][4];
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
    return 0;
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
    return 0;
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
    return 0;
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
    return 0;
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
    int n, i, j, m, flag;
    char x;
    scanf("%d", &n);
    m = n;
    while(m--)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                scanf("%d", &N[i][j]);
        scanf("%s", &x);
        if (x == 'w')
            up(N);
        if (x == 's')
            down(N);
        if (x == 'a')
            left(N);
        if (x == 'd')
            right(N);
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                printf("%d", N[i][j]);
                if (j < 3)
                    printf(" ");
                if (j == 3 && i != 3)
                    printf("\n");
            }
        flag = 0;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if(N[i][j] == 64)
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
            printf("\nYou win");
        if(flag == 0)
            printf("\nGame over");
        if(m != 0)
            printf("\n\n");
    }
    return 0;
}
