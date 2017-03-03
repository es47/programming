#include <stdio.h>
main()
{
    int n, i, j, x, y, a[1000], b[1000];
    int c[2000], k, z, t, ae, be;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &i, &j);
        for (x = 0; x < i; x++)
            scanf("%d", &a[x]);
        for (y = 0; y < j; y++)
            scanf("%d", &b[y]);
        k = x + y;
        ae = x;
        be = y;
        t = 0;
        x = 0;
        y = 0;
        for (z = 0; z < k; z++)
        {
            if (x == ae || y == be) break;
            if (a[x] <= b[y])
            {
                c[z] = a[x];
                x++;
            }
            else
            {
                c[z] = b[y];
                y++;
            }
            t++;
        }
        if (x == ae)
        {
            for (y > 0; y < be; y++)
            {
                c[z] = b[y];
                z++;
            }
        }
        else
        {
            for (x > 0; x < ae; x++)
            {
                c[z] = a[x];
                z++;
            }
        }
        printf("%d\n", t);
        if (k <= 6)
        {
            for (z = 0; z < k; z++)
            {
                if (z != k - 1)
                    printf("%d ", c[z]);
                else
                    printf("%d\n", c[z]);
            }
        }
        else
        {
            printf("%d %d %d %d %d %d\n", c[0], c[1], c[2], c[k - 3], c[k - 2] , c[k - 1]);
        }
    }
    return 0;
}
