#include <stdio.h>
main()
{
    int ncase, pay, i, max1, max2, t1, t2;
    while(1)
    {
        scanf("%d", &ncase);
        if (ncase == 0) break;
        max1 = max2 = 0;
        for (i = 0; i < ncase; i++)
        {
            scanf("%d", &pay);
            t1 = pay + max2;
            t2 = (max1 > max2)? max1: max2;
            max1 = t1;
            max2 = t2;
        }
        printf("%d\n", (max1 > max2)? max1: max2);
    }
    return 0;
}
