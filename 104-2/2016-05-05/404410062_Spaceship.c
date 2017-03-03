#include <stdio.h>
#define N 10000
main()
{
    int ncase;
    unsigned long int a[N], b[N], x1, x2, y1, y2, t1, t2, i, ans;
    while(1)
    {
        scanf("%d", &ncase);
        if(ncase == 0) break;
        for (i = 0; i < ncase; i++)
            scanf("%d %d", &a[i], &b[i]);
        t1 = (long)abs(a[0] - 1000);
        t2 = (long)abs(b[0] - 1000);
        for (i = 1; i < ncase; i++)
        {
            x1 = t1 + (long)abs(a[i] - a[i - 1]);
            y1 = t2 + (long)abs(a[i] - b[i - 1]);
            x2 = t1 + (long)abs(b[i] - a[i - 1]);
            y2 = t2 + (long)abs(b[i] - b[i - 1]);
            t1 = (x1 > y1)? y1: x1;
            t2 = (x2 > y2)? y2: x2;
        }
        ans = (t1 > t2)? t2: t1;
        printf("%d\n", ans);
    }
}
