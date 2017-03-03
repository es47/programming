#include <stdio.h>
#define N 500
int main()
{
    int i, j, k, n, m, t, u, v, sol;
    int g[N][N], que[N], visit[N], start[N], c[N];
    int q1, q2, maxc, total;
    while(1)
    {
        scanf("%d %d %d", &n, &m, &t);
        if (n == 0) break;
        for (i = 0; i < t; i++)
            scanf("%d", start+i);
        for (i = 0; i< n; i++)
            scanf("%d", c+i);
        for (maxc = 0, i = 0; i < n; i++)
            if (c[i] > maxc)
                maxc = c[i];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                g[i][j] = 0;
        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            g[u][v] = 1;
        }
        for (i = 0; i < n; i++)
            visit[i] = 0;
        sol = total = 0;
        while(--t >= 0)
        {
            k = start[t];
            if (visit[k]) continue;
            que[0] = k;
            q1 = 0;
            q2 = 1;
            total++;
            visit[k] = 1;
            while(q1 < q2)
            {
                k = que[q1++];
                if (c[k] > sol)
                    sol = c[k];
                for (i = 0; i < n; i++)
                    if (g[k][i] && visit[i] == 0)
                    {
                        que[q2++] = i;
                        visit[i] = 1;
                        total++;
                    }
            }
        }
        printf("%d\n", sol);
    }
}
