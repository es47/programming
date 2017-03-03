#include <stdio.h>
#include <string.h>
main()
{
    int i, j;
    char in[150], out[150];
    while(scanf("%s", in) != EOF)
    {
        int t[150] = {0};
        i = 0;
        for (j = 0; j < strlen(in); j++)
        {
            for ( ; i < strlen(in); i++)
            {
                t[j]++;
                if (in[i] != in[i + 1]) break;
            }
            i++;
            out[j] = in[i - 1];
            if (i == strlen(in)) break;
        }
        j++;
        for (i = 0; i < j; i++)
            printf("%d%c", t[i], out[i]);
        printf("\n");
    }
}
