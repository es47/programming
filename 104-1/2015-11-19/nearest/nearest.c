#include <stdio.h>
main()
{
    int n, t, x[100000], y[100000], j, td;
    int i, xn, yn, d, dx, dy, nd, temp;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        for (i = 0; i < t; i++)
            scanf("%d %d", &x[i], &y[i]);
        xn = 0;
        yn = 0;
        td = 0;
        for (j = 0; j < t; j++)
        {
            nd = 100000;
            for (i = 0; i < t; i++)
            {
                dx = (x[i] - xn > 0)? x[i] - xn: xn - x[i];
                dy = (y[i] - yn > 0)? y[i] - yn: yn - y[i];
                d = dx + dy;
                if (nd > d)
                {
                    temp = i;
                    nd = d;
                }
            }
            xn = x[temp];
            yn = y[temp];
            x[temp] = 100000;
            y[temp] = 100000;
            td += nd;
        }
        printf("%d", td);
        if (n != 0)
            printf("\n");
    }
    return 0;
}
