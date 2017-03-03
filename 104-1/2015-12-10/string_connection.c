#include <stdio.h>
#include <string.h>
#define ROW 31
#define COL 101
char num[ROW][COL];
main()
{
    int n, t, i, min;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d\n", &t);
        for (i = 1; i <= t; i++)
            scanf("%s", num[i]);
        for (i = 2; i <= t; i++)
        {
            min = (strlen(num[1]) > strlen(num[i]))? strlen(num[i]): strlen(num[1]);
            while (min > 0)
            {
                if (strncmp(num[1] + strlen(num[1]) - min, num[i], min) == 0) break;
                    min--;
            }
            strcpy(num[0], num[1]);
            memset(num[1], '\0', sizeof(num[1]));
            strncpy(num[1], num[0], strlen(num[0]) - min);
            strcat(num[1], num[i]);
        }
        printf("%d\n", strlen(num[1]));
        printf("%s", num[1]);
        if (n != 0)
            printf("\n");
    }
    return 0;
}
