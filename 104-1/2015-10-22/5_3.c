#include <stdio.h>
main()
{
    int ncase, i;
    int j, k;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d", &i);
        j = 1;
        while (j <= i)
        {
            k = 1;
            while (0 < k && k <= j)
            {
                {
                    if (k < j)
                        printf("%d ", k);
                    else
                        printf("%d", k);
                }
                if (k == j)
                    printf("\n");
                k++;
            }
            j++;
        }
        if (ncase != 0)
            printf("\n");
    }
    return 0;
}
