#include <stdio.h>
#include <string.h>
main()
{
    int i, j, k, t, x, l, m, p, end;
    char n[1024], o[1024];
    while (scanf("%s", n) != EOF)
    {
        i = 0;
        while (end != strlen(n))
        {
            x = 0;
            t = 0;
            k = 0;
            for ( ; i < strlen(n); i++)
            {
                t++;
                if (n[i] > 57) break;
            }
            l = i - 1;
            for ( ; t > 1; t--)
            {
                x += n[l] - '0';
                l--;
                if (t != 2)
                    x *= 10;
            }
            j = i;
            for ( ; j < strlen(n); j++)
                if (n[j] <= 57) break;
            end = j;
            p = i;
            for (m = 0; m < j - i; m++)
            {
                o[k] = n[p];
                k++;
                p++;
            }
            i++;
            for ( ; x > 0; x--)
                for (l = 0; l < k; l++)
                    printf("%c", o[l]);
        }
        printf("\n");
    }
    return 0;
}
