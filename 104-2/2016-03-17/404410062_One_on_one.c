#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 10000
int cmpr (const void *e1, const void *e2)
{
    return(*(int*)e2) - (*(int*)e1);
}
main()
{
    int i, j, n, a[NUM], b[NUM], win;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &b[i]);
        qsort(a, n, sizeof(int), cmpr);
        qsort(b, n, sizeof(int), cmpr);
        i = j = 0;
        win = 0;
        while(j < n)
        {
            while((a[i] >= b[j]) && (i < n))
                i++;
            if (i == n) break;
            win++;
            j++;
            i++;
        }
        printf("%d\n", win);
    }
}
