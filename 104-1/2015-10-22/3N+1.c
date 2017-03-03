#include <stdio.h>
main()
{
    int i, j;
    int x, y, m, t, mt;
    while (1)
    {
        scanf("%d %d", &i, &j);
        if (i == 0 && j == 0) break;
        if (i < 0 || i > 1000000 || j < 0 || j > 1000000) break;
        x = (i < j)? i: j;
        y = (i < j)? j: i;
        mt = 0;
        while (x <= y)
        {
            t = 1;
            m = x;
            while (m > 1)
            {
                if (m % 2 != 0)
                    m = 3 * m + 1;
                else
                    m = m / 2;
                t++;
            }
            mt = (mt > t)? mt: t;
            x++;
        }
        printf("%d %d %d\n", i, j, mt);
    }
    return 0;
}
