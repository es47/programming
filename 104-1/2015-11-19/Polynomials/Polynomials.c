#include <stdio.h>
main()
{
    int n, co[3], d, m;
    int i, j, k, l, t, x[1025], y[1025];
    scanf("%d", &n);
    while (n--)
    {
        l = 3;
        for (i = 0; i < 3; i++)
            scanf("%d", &co[i]);
        scanf("%d", &d);
        for (i = 0; i < 3; i++)
            x[i] = co[i];
        if (d == 1)
        {
            for (i = 0; i < 3; i++)
                y[i] = co[i];
        }
        for (m = 0; m < d - 1; m++)
        {
            for (i = 0; i < 1025; i++)
                y[i] = 0;
            t = 0;
            for (i = 0; i < 3; i++)
            {
                k = t;
                for (j = 0; j < l; j++)
                {
                    y[k] += co[i] * x[j];
                    k++;
                }
                t++;
            }
            l = k;
            for (i = 0; i < 1025; i++)
                x[i] = y[i];
        }
        for (k = 0; k < l; k++)
        {
            if (k != l - 1)
                printf("%d ", y[k]);
            else
                printf("%d", y[k]);
        }
        if (n != 0)
            printf("\n");
    }
    return 0;
}
