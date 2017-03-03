#include <stdio.h>
#include <string.h>
main()
{
    int n, i, m;
    char in[1000], a;
    scanf("%d\n", &n);
    while (n--)
    {
        int c[1000] = {0};
        gets(in);
        for (i = 0; i < strlen(in); i++)
        {
            if (in[i] >= 'A' && in[i] <= 'Z')
                c[in[i]]++;
            if (in[i] >= 'a' && in[i] <= 'z')
                c[in[i] - 32]++;
        }
        m = 1;
        for (i = 65; i < 91; i++)
            m = (c[i] > m)? c[i]: m;
        for (i = 65; i < 91; i++)
            if (c[i] == m)
            {
                a = i;
                printf("%c", a);
            }
        if (n != 0)
            printf("\n");
    }
    return 0;
}
