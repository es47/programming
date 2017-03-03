#include <stdio.h>
main()
{
    int t, n, k, i, j, max, x, temp;
    int s1[1000], s2[1000], s3[1000], total[1000], st[2], ft[1000];
    int fs1[1000], fs2[1000], fs3[1000], lt[1000];
    double av[1000];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++)
            scanf("%d %d %d", &s1[i], &s2[i], &s3[i]);
        for (i = 0; i < n; i++)
            total[i] = s1[i] + s2[i] + s3[i];
        for (i = 0; i < k; i++)
        {
            max = total[0];
            for (j = 1; j < n; j++)
            {
                if (max >= total[j])
                    max = max;
                else
                {
                    max = total[j];
                    x = j;
                }
            }
            if (max != total[0])
            {
                lt[i] = max;
                fs1[i] = s1[x];
                fs2[i] = s2[x];
                fs3[i] = s3[x];
                total[x] = -1;
            }
            else
            {
                lt[i] = max;
                fs1[i] = s1[0];
                fs2[i] = s2[0];
                fs3[i] = s3[0];
                total[0] = -1;
            }
        }
        for (i = 0; i < k; i++)
            ft[i] = lt[i];
        for (i = 0; i < 3; i++)
            st[i] = 0;
        for (i = 0; i < n; i++)
        {
            st[0] += s1[i];
            st[1] += s2[i];
            st[2] += s3[i];
        }
        for (i = 0; i < 3; i++)
            av[i] = (double) st[i] / n;
        for (i = 0; i < k; i++)
            printf("%d %d %d %d\n", fs1[i], fs2[i], fs3[i], ft[i]);
        for (i = 0; i < 3; i++)
        {
            if (i != 2)
                printf("%.2f ", av[i]);
            else
                printf("%.2f\n", av[i]);
        }
        if (t != 0)
            printf("\n");
    }
}
