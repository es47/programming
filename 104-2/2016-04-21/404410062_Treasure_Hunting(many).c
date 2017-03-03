#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define N 10000
#define M 1000000
typedef struct {int x, y;} EDGELIST;
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int i, j, k, n, m, t, u, v, sol;
    int que[N], visit[N], start[N], c[N], vp[N + 2];
    EDGELIST *edge;
    int q1, q2, maxc, total;
    edge = (EDGELIST *)calloc(M, sizeof(EDGELIST));
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
        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            edge[i].x = u;
            edge[i].y = v;
        }
        qsort (edge, m, sizeof(EDGELIST), cmp);
        edge[m].x = n;
        j = 0;
        for (i = 0; i < n; i++)
        {
            vp[i] = j;
            while (edge[j].x == i)
                j++;
        }
        vp[n] = m;
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
                for (j = vp[k]; j < vp[k + 1]; j++)
                {
                    i = edge[j].y;
                    if (visit[i] == 0)
                    {
                        que[q2++] = i;
                        visit[i] = 1;
                        total++;
                    }
                }
            }
        }
        printf("%d\n", sol);
    }
}
