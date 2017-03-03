#include <stdio.h>
main()
{
    int ncase, i, j, k, ans1, ans2, n;
    int chk[10], t, ok1, ok2;
    scanf("%d", &ncase);
    while(ncase--)
    {
        int book[10] = {0};
        int book2[10] = {0};
        for (i = 0; i < 6; i++)
        {
            scanf("%d", &k);
            book[k]++;
        }
        for (i = 0; i < 6; i++)
        {
            scanf("%d", &k);
            book2[k]++;
        }
        ans1 = 0;
        ans2 = 0;
        for (n = 0; n < 1000000; n++)
        {
            t = n;
            for (i = 0; i < 10; i++)
                chk[i] = book[i];
            ok1 = 1;
            do
            {
                k = t % 10;
                if (chk[k] < 1)
                {
                    ok1 = 0;
                    break;
                }
                chk[k]--;
                t /= 10;
            }
            while(t > 0);
            t = n;
            for (i = 0; i < 10; i++)
                chk[i] = book2[i];
            ok2 = 1;
            do
            {
                k = t % 10;
                if (chk[k] < 1)
                {
                    ok2 = 0;
                    break;
                }
                chk[k]--;
                t /= 10;
            }
            while(t > 0);
            if (ok1 - ok2 == 1)
                ans1++;
            if (ok2 - ok1 == 1)
                ans2++;
        }
        printf("%d %d", ans1, ans2);
        if (ncase != 0)
            printf("\n");
    }
}
