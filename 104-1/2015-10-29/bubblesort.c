#include <stdio.h>
main()
{
    int n, m[200];
    int i, j, temp, t;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++)
            scanf(" %d", &(m[i]));
        t = 0;
        for (i = n - 1; i > 0; i--)
        {
            for (j = n - 1; j > 0; j--)
            {
                if (m[j] < m[j - 1])
                {
                    temp = m[j];
                    m[j] = m[j - 1];
                    m[j - 1] = temp;
                    t++;
                }
            }
        }
        printf("%d\n", t);
    }
    return 0;
}
