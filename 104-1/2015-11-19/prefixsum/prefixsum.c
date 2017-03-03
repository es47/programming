#include <stdio.h>
main()
{
    int n, k, i, j, x, p;
    int a[100001], min, max;
    scanf("%d %d", &n, &k);
    for (x = 1; x <= n; x++)
        scanf("%d", &a[x]);
    while (k--)
    {
        scanf("%d %d", &i, &j);
        min = (i > j)? j: i;
        max = (j > i)? j: i;
        p = 0;
        for (x = min; x <= max; x++)
            p += a[x];
        printf("%d", p);
        if (k != 0)
            printf("\n");
    }
    return 0;
}
