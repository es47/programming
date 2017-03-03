#include <stdio.h>
#define N 1000
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
main()
{
    int ncase, i, j, k, t;
    int seg[N];
    while (1)
    {
        scanf("%d", &ncase);
        if (ncase == 0) break;
        for (i = 0; i < ncase; i++)
            scanf("%d", &seg[i]);
        qsort(seg, ncase, sizeof(int), cmp);
        t = 0;
        for (i = 0; i < ncase; i++)
            for (j = i + 1; j < ncase; j++)
                for (k = j + 1; k < ncase; k++)
                    if (seg[i] + seg[j] > seg[k])
                        t++;
        printf("%d\n", t);
    }
}
