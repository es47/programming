#include <stdio.h>
main()
{
    int ncase, q1, q2, r1, r2, i, j, a, b, min, ans[10000];
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %d %d %d", &q1, &r1, &q2, &r2);
        a = q1 - r1;
        b = q2 - r2;
        min = (a > b)? b: a;
        j = 0;
        for (i = 1; i <= min; i++)
            if (a % i == 0 && b % i == 0)
            {
                ans[j] = i;
                j++;
            }
        for (i = 0; i < j; i++)
        {
            if (i != j - 1)
                printf("%d ", ans[i]);
            else
                printf("%d", ans[i]);
        }
        if(ncase != 0)
            printf("\n");
    }
    return 0;
}
