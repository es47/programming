#include<stdio.h>
#define N 100000
#include<stdlib.h>
int p[N], dep[N], que[N], longest[N];
int main()
{
    int ans, i, j, k, front, tail, m, n, ncase;
    int l;
    scanf("%d", &l);
    while(l--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            p[i] = -1;
        for(i = 0; i < n; i++)
            dep[i] = 0;
        for(i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &j, &k);
            p[k] = j;
            dep[j]++;
        }
        for(i = 0; i < n; i++)
            longest[i] = 0;
        front = tail = 0;
        for(i = 0; i < n; i++)
            if(dep[i] == 0)
                que[tail++] = i;
        ans = 0;
        while(front < tail)
        {
            i = que[front++];
            j = p[i];
            if(j == -1) break;
            k = longest[i] + 1 + longest[j];
            if(k > ans)
                ans = k;
            if(longest[i] + 1 > longest[j])
                longest[j] = longest[i] + 1;
            dep[j]--;
            if(dep[j] == 0)
                que[tail++] = j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
