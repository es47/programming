#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define NUM 100000
main()
{
    int ncase, i, j, k;
    char str[NUM];
    unsigned long int sum;
    while (1)
    {
        scanf("%d", &ncase);
        if (ncase == 0) break;
        gets(str);
        sum = 0;
        for(i = 0; i < ncase; i++)
        {
            k = 0;
            gets(str);
            for (j = 0; j < strlen(str); j++)
            {
                k *= 2;
                if (str[j]=='1') k++;
            }
            sum += k;
        }
        printf("%lu\n", sum);
    }
    return 0;
}
