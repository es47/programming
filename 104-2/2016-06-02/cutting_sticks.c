#include<stdio.h>
#define INF 999999
#define N 1000
int point[N];
int table[N][N];
int cmp(int *a, int *b)
{
    return *a - *b;
}
int cost(int i, int j)
{
    int k, t, mincost;
    if(j <= i + 1)
        return 0;
    if(table[i][j] >= 0)
        return table[i][j];
    mincost = INF;
    for(k = i + 1; k < j; k++)
    {
        t = cost(i, k) + cost(k, j);
        if(t < mincost)
            mincost = t;
    }
    mincost += point[j] - point[i];
    table[i][j] = mincost;
    return mincost;
}
int main()
{
    int n, m, i, j;
    scanf("%d", &m);
    while(m > 0)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d", &point[i]);
        point[0] = 0;
        point[n+1] = m;
        qsort(point + 1, n, sizeof(int), cmp);
        for(i = 0; i < n + 2; i++)
            for(j = 0; j < n + 2; j++)
                table[i][j] = -1;
        printf("The minimum cutting is %d.\n", cost(0,n+1));
        scanf("%d", &m);
    }
    return 0;
}
