#include <stdio.h>
#define N 5000
int main()
{
    int ncase, n, m, i, j, k, s, t[N];
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < m; i++)
            t[i] = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            for (s = 0, j = 1; j < m; j++)
                if (t[j] < t[s])
                    s = j;
            t[s] += k;
        }
        for (s = 0,i = 0; i < m; i++)
            if (t[i] > t[s])
                s = i;
        printf("%d\n", t[s]);
    }
}
