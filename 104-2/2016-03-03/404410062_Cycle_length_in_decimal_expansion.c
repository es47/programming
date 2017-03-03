#include <stdio.h>
main()
{
    int p, q, i;
    int *book;
    book=malloc(sizeof(int)*1000100);
    while(1)
    {
        scanf("%d %d", &p, &q);
        if (q == 0) break;
        for (i = 0; i <= q; i++)
            book[i] = 0;
        for (i = 1; ; i++)
        {
            if (book[p] > 0) break;
            book[p] = i;
            p = (p * 10) % q;
        }
        printf("%d\n", i - book[p]);
    }
}
