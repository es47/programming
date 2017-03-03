#include <stdio.h>
main()
{
    int x, y, n;
    int i, j, k;
    while (1)
    {
        scanf("%d", &x);
        if (x == 0) break;
        scanf(" %d %d", &y, &n);
        i = x % n;
        k = 1;
        j = 0;
        while (j < y)
        {
            k *= i;
            k %= n;
            j++;
        }
        printf("%d\n", k);
    }
    return 0;
}
