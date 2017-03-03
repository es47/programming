#include <stdio.h>
#define NUM 10000
int cmpr (const void *e1, const void *e2)
{
    return(*(int*)e1) - (*(int*)e2);
}
main()
{
    int ncase, box, i, j, d[NUM], t[NUM], sum;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &box);
        for (i = 0; i < box; i++)
            scanf("%d", &d[i]);
        qsort(d, box, sizeof(int), cmpr);
        for (i = 0; i < box; i++)
        {
            if (i == 0)
                t[i] = d[i];
            else
                t[i] = t[i - 1] + d[i] + d[i - 1];
        }
        sum = 0;
        for (i = 0; i < box; i++)
            sum += t[i];
        printf("%d\n", sum);
    }
    return 0;
}
