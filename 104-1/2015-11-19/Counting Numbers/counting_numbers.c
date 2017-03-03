#include <stdio.h>
main()
{
    int n, num[52], i, j, max, t, k;
    int ft[52], nd[52], temp[52];
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0; ; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] == -999) break;
        }
        j = i;
        for (k = 0; k < j; k++)
        {
            max = num[0];
            for (i = 1; i < j; i++)
            {
                max = (max >= num[i])? max: num[i];
            }
            if (max == -1000000) break;
            ft[k] = max;
            t = 0;
            for (i = 0; i < j; i++)
            {
                if (num[i] == max)
                {
                    t++;
                    num[i] = -1000000;
                }
            }
            nd[k] = t;
        }
        for (i = 0; i < k; i++)
        {
            if (i != k - 1)
                printf("%d %d\n", ft[i], nd[i]);
            else
                printf("%d %d", ft[i], nd[i]);
        }
        if (n != 0)
            printf("\n\n");
    }
    return 0;
}
