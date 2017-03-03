#include <stdio.h>
#define CASE 10000
#define WAY 2
main()
{
    int m, n, i, j, k, cycle, flag;
    int stru[CASE], point[CASE][WAY], temp[CASE][WAY];
    while(1)
    {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        for (i = 0; i < m; i++)
            scanf("%d", &stru[i]);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &point[i][0]);
            scanf("%d", &point[i][1]);
        }
        for (i = 0; i < n; i++)
        {
            temp[0][0] = point[i][0];
            temp[0][1] = point[i][1];
            flag = -1;
            for (j = 1; j < CASE; j++)
            {
                temp [j][1] = stru[temp[j - 1][0]];
                if (temp[j - 1][1] < 0)
                    temp[j][1] = -temp[j][1];
                temp[j][0] = temp[j - 1][0] + temp[j][1];
                for (k = 0; k < j - 1; k++)
                {
                    if (temp[j][0] == temp[k][0] && temp[j][1] == temp[k][1])
                    {
                        flag = 0;
                        cycle = j - k;
                    }
                    if (flag == 0) break;
                }
                if (temp[j][0] >= m)
                    flag = 1;
                if (temp[j][0] < 0)
                    flag = 2;
                if (flag != -1) break;
            }
            if (flag == 0)
                printf("Cycle %d\n", cycle);
            if (flag == 1)
                printf("Forward\n");
            if (flag == 2)
                printf("Backward\n");
        }
    }
    return 0;
}
