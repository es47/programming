#include <stdio.h>
#define N 100000
main()
{
    int n, i, sum, ans, br[N], ncase = 0;
    while(1)
    {
        ncase++;
        scanf("%d", &n);
        if (n == 0) break;
        sum = ans = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &br[i]);
            sum += br[i];
        }
        sum /= n;
        for (i = 0; i < n; i++)
            if (br[i] > sum)
                ans += (br[i] - sum);
        printf("Set #%d\n", ncase);
        printf("The minimum number of moves is %d.\n\n", ans);
    }
    return 0;
}
