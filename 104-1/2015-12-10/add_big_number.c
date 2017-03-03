#include <stdio.h>
#include <string.h>
#define LEN 30
main()
{
    char str1[LEN], str2[LEN];
    int num1[LEN], num2[LEN], n, i, j, len1, len2, max;
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0; i < LEN; i++)
        {
            str1[i] = 0;
            str2[i] = 0;
            num1[i] = 0;
            num2[i] = 0;
        }
        scanf("%s %s", str1, str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        j = 0;
        max = (len1 > len2)? len1: len2;
        for(i = len1 - 1; i >= 0; i--)
            num1[j++] = str1[i] - '0';
        j = 0;
        for(i = len2 - 1; i >= 0; i--)
            num2[j++] = str2[i] - '0';
        for(i = 0; i < max; i++)
        {
            num2[i] += num1[i];
            if(num2[i] >= 10)
            {
                num2[i] -= 10;
                num2[i+1] += 1;
            }
        }
        if(num2[max])
            printf("%d", num2[max]);
        for(i = max - 1; i >= 0; i--)
            printf("%d", num2[i]);
        if (n != 0)
            printf("\n");
    }
    return 0;
}
