#include <stdio.h>
int a[5][5];
void square (int ans[][5], int d)
{
    int i, j;
    for (i = 0; i < d; i++)
    {
        j = i;
        ans[i][j] = 1;
    }
}
void copy (int from[][5],int to[][5], int d)
{
    int i, j;
    for (i = 0; i < d; i++)
        for (j = 0; j < d; j++)
            to[i][j] = from[i][j];
}
void mul (int a[][5], int c[][5], int A[][5][5], int p, int d)
{
    int i, j, k, l;
    long long t, t2;
    int b[5][5] = {0};
    square(b, d);
    for (l = 0; l < 32; l++)
    {
        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
            {
                t = 0;
                for (k = 0; k < d; k++)
                {
                    t2 = a[i][k];
                    t2 = (t2 * b[k][j]) % p;
                    t = (t + t2) % p;
                }
                c[i][j] = (int) t;
                A[l][i][j] = c[i][j];
            }
        copy(c, a, d);
        copy(c, b, d);
    }
}
void mul_ans (int ans[][5], int A[][5][5], int p, int d,int l)
{
    int i, j, k;
    long long t, t2;
    int c[5][5] = {0};
    for (i = 0; i < d; i++)
        for (j = 0; j < d; j++)
        {
            t = 0;
            for (k = 0; k < d; k++)
            {
                t2 = ans[i][k];
                t2 = (t2 * A[l][k][j]) % p;
                t = (t + t2) % p;
            }
            c[i][j] = (int) t;
        }
    copy(c, ans, d);
}
int main()
{
    int d, y, p, i, j;
    while (1)
    {
        scanf("%d %d %d", &d, &y, &p);
        if (d == 0 && y == 0 && p == 0) break;
        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
                scanf("%d", &a[i][j]);
        int c[5][5] = {0};
        int ans[5][5] = {0};
        int A[32][5][5] = {0};
        int bin[32] = {0};
        mul(a, c, A, p, d);
        square(ans, d);
        i = 0;
        while (y > 0)
        {
            bin[i++] = y % 2;
            y /= 2;
        }
        for (i = 0; i < 32; i++)
            if(bin[i] == 1)
                mul_ans(ans, A, p, d, i);
        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
            {
                if (j != d - 1)
                    printf("%d ", ans[i][j]);
                else
                    printf("%d\n", ans[i][j]);
            }
    }
}
