#include <stdio.h>
#include <string.h>
#define N 100000
main()
{
    int i, j, len;
    char line[N];
    while(gets(line) != NULL)
    {
        len = strlen(line);
        for (i = 0; i < len; i++)
        {
            if (line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] += 'a' - 'A';
                line[i] = 'a' + 'z' - line[i];
                continue;
            }
            if (line[i] >= 'a' && line[i] <= 'z')
            {
                line[i] -= 'a' - 'A';
                line[i] = 'A' + 'Z' - line[i];
                continue;
            }
            if (line[i] >= '0' && line[i] <= '9')
            {
                if (line[i] != '9')
                    line[i]++;
                else
                    line[i] = '0';
            }
        }
        for (i = 0; i < len; i++)
            printf("%c", line[i]);
        printf("\n");
    }
}
