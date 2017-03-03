#include <stdio.h>
#define N 500
main()
{
    int ncase, i, j;
    unsigned long int map[N][N], opt[N][N];
    while(1)
    {
        scanf("%d", &ncase);
        if (ncase == 0) break;
        for (i = 0; i <= ncase; i++)
        {
            map[i][0] = map[0][i] = 0;
            opt[i][0] = opt[0][i] = 0;
        }
        for (i = 1; i <= ncase; i++)
            for (j = 1; j <= ncase; j++)
                scanf("%u", &map[i][j]);
        for (i = 1; i <= ncase; i++)
            for (j = 1; j <= ncase; j++)
                opt[i][j] = ((opt[i - 1][j] > opt[i][j - 1])? opt[i - 1][j]: opt[i][j - 1]) + map[i][j];
        printf("%u\n", opt[ncase][ncase]);
    }
    return 0;
}
