#include <stdio.h>
main()
{
    int ncase, q;
    int i, t;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d", &q);
        i = 2;
        while (i <= q)
        {
            t = 0;
            while (q % i == 0)
            {
                q /=i;
                t++;
                if (q == 1) break;
            }
            if (t != 0)
            {
                printf("%d\n", i);
                printf("%d\n", t);
            }
            i++;
        }
        if (ncase != 0)
        printf("\n");
    }
}
