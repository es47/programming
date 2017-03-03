#include <stdio.h>
main()
{
    int n, m[200];
    int i, j, min, t, temp, x;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++)
            scanf(" %d", &m[i]);
        t = 0;
        for (i = 0; i < n; i++)
        {
            min = m[i];
            for (j = i + 1; j < n; j++)
            {
                if (min < m[j])
                    min = min;
                else
                    min = m[j];
                if (min == m[j])
                    x = j;
            }
            if (min != m[i])
            {
                temp = m[i];
                m[i] = min;
                m[x] = temp;
                t++;
            }
        }
        if (n < 3)
        {
            for (i = 0; i < n; i++)
                printf("%d ", m[i]);
            printf("%d\n", t);
        }
        else
            printf("%d %d %d %d\n", m[0], m[1], m[2], t);
    }
    return 0;
}
