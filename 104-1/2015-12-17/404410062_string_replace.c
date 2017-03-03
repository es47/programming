#include <stdio.h>
#include <string.h>
main()
{
    int n, i, j, k, l, t;
    char in[100000], r[100000], re[100000];
    scanf("%d\n", &n);
    while(n--)
    {
        gets(in);
        gets(r);
        gets(re);
        l = 0;
        i = 0;
        while (l < strlen(in))
        {
            for ( ; l <= strlen(in) - strlen(r); l++)
            {
                t = 0;
                k = l;
                for (j = 0; j < strlen(r); j++)
                {
                    if (in[k] == r[j])
                        t++;
                    k++;
                }
                if (t == strlen(r)) break;
            }
            if (strlen(in) == strlen(r))
            {
                if (t == strlen(r))
                    for (j = 0; j < strlen(re); j++)
                        printf("%c", re[j]);
                else
                    for (j = 0; j < strlen(in); j++)
                        printf("%c", in[j]);
            }
            else
            {
                if (l < strlen(in) - strlen(r) + 1)
                {
                    for (j = i; j < l; j++)
                        printf("%c", in[j]);
                    for (j = 0; j < strlen(re); j++)
                        printf("%c", re[j]);
                }
                if (l == strlen(in) - strlen(r) + 1)
                {
                    for ( ; i < strlen(in); i++)
                        printf("%c", in[i]);
                }
                if (l > strlen(in) - strlen(r) + 1 && l < strlen(in))
                {
                    for (j = i; j <= l; j++)
                        printf("%c", in[j]);
                }
            }
            l += strlen(r);
            i = l;
        }
        if (n != 0)
            printf("\n");
    }
}
