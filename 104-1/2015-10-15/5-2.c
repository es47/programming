#include <stdio.h>
main()
{
    int ncase, i;
    int l, j;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d", &i);
        for (l = 1; l <= i; l++)
            printf("%d\n", l);
        for (j = i - 1; j > 0; j--)
            printf("%d\n", j);
        if (ncase != 0)
            printf("\n");
    }
    return 0;
}
