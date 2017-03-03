#include <stdio.h>
main()
{
    int ncase, D, k, i, j, sum, a, b, c, A, B, C;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &D);
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d %d", &A, &B, &C);
        for (i = 0; i <= a; i++)
        {
            for (j = 0; j <= b; j++)
            {
                for (k = 0; k <= c; k++)
                {
                    sum = A * i + B * j + C * k;
                    if (sum == D)break;
                }
                if (sum == D)break;
            }
            if (sum == D)break;
        }
        if (sum == D)
            printf("yes\n");
        else
            printf("no\n");
    }
}
