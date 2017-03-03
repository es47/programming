#include<stdio.h>
#include <stdlib.h>
#define N 1100000
int *c, *w;
int dp(int goal, int n)
{
    int mm, i, k;
    if(c[goal] >= 0)
        return c[goal];
    mm = 0;
    for(i = 0; i < n; i++)
    {
        if(goal & (1<<i))
        {
            k = dp(goal ^ (1<<i), n);
            if(k > mm)
            mm = k;
        }
    }
    c[goal] = mm + w[goal];
    return c[goal];
}

int main()
{
    int i, j, k, s, t, n, m;
    w = malloc(N * sizeof(int));
    c = malloc(N * sizeof(int));
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)break;
        m = 1<<n;
        for(i = 0; i < m; i++)
            scanf("%d", &w[i]);
        for(i = 0; i < m; i++)
            c[i] = -1;
        c[0] = w[0];
        printf("%d\n", dp(m-1, n));
    }
    return 0;
}


