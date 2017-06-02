#include <stdio.h>
#include <stdlib.h>
#define N 100
double determinant(double A[][N], int ncase)                    //計算determinant的值
{
    double sum = 0;
    sum += A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    sum -= A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]);
    sum += A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
    return sum;
}
void swap(double A[][N], int first, int second, int ncase)       //交換列
{
    int temp, i;
    for (i = 0; i <= ncase; i++)
    {
        temp = A[first][i];
        A[first][i] = A[second][i];
        A[second][i] = temp;
    }
}
void up_triangle(double A[][N], int ncase)                     //計算上三角
{
    int i, j, k, size, flag, a, b;
    for (i = 0; i < ncase; i++)
    {
        flag = 0;
        if (A[i][i] != 0)                                      //若對角不為零
        {
            if (A[i][i] < 0)                                   //負號變正號
                for (k = i; k <= ncase; k++)
                    A[i][k] = -A[i][k];
            if (A[i][i] == 1)                                  //為1則減其他列
            {
                for (j = i + 1; j < ncase; j++)
                {
                    size = A[j][i] / A[i][i];
                    for (k = 0; k <= ncase; k++)
                        A[j][k] -= A[i][k] * size;
                }
                flag = 1;
            }
            else                                               //不為1則除以自己
            {
                j = A[i][i];
                for (k = 0; k <= ncase; k++)
                    A[i][k] /= j;
            }
        }
        else                                                   //若對角為零
        {
            flag = 1;
            for (j = i + 1; j < ncase; j++)                    //往下一列找不為零的數
                if (A[j][i] != 0)
                {
                    flag = 0;
                    swap(A, i, j, ncase);
                }
        }
        if (flag == 0)
            i--;
    }
}
main()
{
    int ncase, i, j, count = 0;
    double A[N][N], d, x, y, z;
    while(1)
    {
        scanf("%d", &ncase);
        if (ncase == 0) break;
        for (i = 0; i < ncase; i++)
            for (j = 0; j < ncase; j++)
                scanf("%lf", &A[i][j]);
        for (i = 0; i < ncase; i++)
            scanf("%lf", &A[i][ncase]);
        printf("Case %d", count);
        printf(": n=%d\n\n", ncase);
        d = determinant(A, ncase);
        up_triangle(A, ncase);
        for (i = 0; i < ncase; i++)
        {
            for (j = 0; j <= ncase; j++)
                printf("  %.4lf", A[i][j]);
            printf("\n");
        }
        if (abs(d) < 0.0001)
            printf("determinant is zero\n");
        else
        {
            printf("determinant=%lf\n", d);
            z = A[2][3] / A[2][2];
            y = (A[1][3] - z * A[1][2]) / A[1][1];
            x = (A[0][3] - z * A[0][2] - y * A[0][1]) / A[0][0];
            printf("  %.4lf", x);
            printf("  %.4lf", y);
            printf("  %.4lf\n", z);
        }
        printf("===============\n");
        count++;
    }
    return 0;
}
