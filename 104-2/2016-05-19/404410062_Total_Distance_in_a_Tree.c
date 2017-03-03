#include<stdio.h>
#define N 10000
int main()
{
    int ncase, n, i, P[N], visit[N], L[N], sum;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &n);
        for(i = 2; i <= n; i++)
            scanf("%d", &P[i]);
        for(i = 1; i <= n; i++)
            visit[i]=1;
        for(i = n; i >= 1; i--)
            visit[P[i]] += visit[i];
        for(i = 2; i <= n; i++)
            scanf("%d", &L[i]);
        sum = 0;
        for(i = n; i >= 2; i--)
            sum += visit[i] * (n - visit[i]) * L[i];
        sum *= 2;
        printf("%d\n", sum);
    }
}
