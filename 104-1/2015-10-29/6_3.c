#include <stdio.h>
main()
{
    int n, m[100];
    int i, j, k, o[100], e[100], x, y;
    scanf("%d", &n);
    while (1)
    {
        if (n == 0) break;
        for (i = 0; i < n; i++)
        {
            if (i != n - 1)
                scanf("%d ", &m[i]);
            else
                scanf("%d", &m[i]);
        }
        j = 0;
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (m[i] % 2 != 0)
            {
                o[j] = m[i];
                j++;
            }
            else
            {
                e[k] = m[i];
                k++;
            }
        }
        for (x = 0; x < j; x++)
        {
            if (x != j - 1)
                printf("%d ", o[x]);
            else
                printf("%d\n", o[x]);
        }
        for (y = 0; y < k; y++)
        {
            if (y != k - 1)
                printf("%d ", e[y]);
            else
                printf("%d\n", e[y]);
        }
        scanf("%d", &n);
        if (n == 0) break;
        printf("\n");
    }
    return 0;
}
