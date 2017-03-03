#include <stdio.h>
main()
{
    int ncase, i, j, k;
    unsigned int n, m, p;
    int book[10000], dig[10000];
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d %d %d", &n, &m, &p);
        if (p == 1)
        {
            printf("0\n");
            continue;
        }
        for (i = 0; i < p; i++)
            book[i] = -1;
        n %= p;
        i = 0;
        k = 1;
        book[i] = 0;
        dig[0] = k;
        for (i = 1; i <= m; i++)
        {
            k = (k * n) % p;
            if (book[k] >= 0) break;
            book[k] = i;
            dig[i] = k;
        }
        if (i > m)
        {
            printf("%d\n", k);
            continue;
        }
        j = i - book[k];
        m = (m - book[k]) % j;
        printf("%d\n", dig[book[k] + m]);
    }
    return 0;
}
