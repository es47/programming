#include<stdio.h>
#include<math.h>
#define N 20
int place(int test[N], int row, int column)              //辨認擺放後是否有衝突
{
    int i;
    for(i = 1; i <= row - 1; ++i)                        //有衝突傳回0
    {
        if(test[i] == column)
            return 0;
        else if(abs(test[i] - column) == abs(i - row))
            return 0;
    }
    return 1;                                            //無衝突傳回1
}
int add(int board[][N], int test[N], int n)              //計算總和
{
    int i, j, sum = 0, count;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            if(test[i] == j)
                sum += board[i - 1][j - 1];              //若是在ij可擺放queen，總和加上(i-1)(j-1)
    return sum;
}
int queen(int board[][N], int test[N], int row, int n, int *max)
{
    int column, sum = 0;
    for(column = 1; column <= n; ++column)
        if(place(test, row, column))
        {
            test[row] = column;                           //沒有衝突則擺放queen
            if(row == n)                                  //到最後一項
            {
                sum = add(board, test, n);                //計算此擺放之總和
                *max = (*max > sum)? *max: sum;           //比較最大的總和
            }
            else                                          //未到最後一項，繼續嘗試下一個queen
                queen(board, test, row + 1, n, &(*max));
        }
}
int main()
{
    int ncase, n, i, j, board[N][N], test[N], max;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &n);                                  //輸入棋盤大小
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &board[i][j]);                //輸入每格的值
        max = 0;
        queen(board, test, 1, n, &max);                   //計算queen的位置
        printf("%d\n", max);
    }
    return 0;
}
