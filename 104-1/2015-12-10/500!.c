#include <stdio.h>
#include <string.h>
#define LEN 2569
#define MAX 1001
int Num[MAX+1][LEN];
void Calc()
{
    int i, j;
    for(i = 0; i < MAX; i++)
        for(j = 0; j < LEN; j++)
            Num[i][j] = 0;
    Num[0][0] = 1;
    Num[1][0] = 1;
    for(i = 2; i <= MAX; i++)
        for(j = 0; j < LEN; j++)
        {
            Num[i][j] += Num[i-1][j] * i;
            if(Num[i][j] >= 10)
            {
                Num[i][j+1] += Num[i][j] / 10;
                Num[i][j] %= 10;
            }
        }
    return 0;
}
void Print(int n)
{
    int i;
    printf("%d!\n", n);
    for(i = LEN - 1; i > 0; i--)
        if(Num[n][i] != 0) break;
    for( ; i >= 0; i--)
        printf("%d", Num[n][i]);
    printf("\n");
    return 0;
}
void main()
{
    int n;
    Calc();
    while(1)
    {
        if(scanf("%d", &n) < 1) break;
        Print(n);
    }
    return 0;
}
