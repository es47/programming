#include <stdio.h>
int main()
{
    int n, i, j, t, l;
    int e[5000], f[5000];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &l);
        for (i = 0; i < l; i++)
            scanf("%d", &e[i]);
        for (i = 0; i < l - 1; i++)
        {
            if (e[i] - e[i + 1] > 0)
                f[i] = e[i] - e[i + 1];
            else
                f[i] = e[i + 1] - e[i];
        }
        t = 1;
        if (l == 2)
        {
            if (f[1] >= l)
                t = 0;
            else
                t = 1;
        }
        for (i = 0; i < l - 2; i++)
        {
            if (t == 0) break;
            for (j = i + 1; j < l - 1; j++)
            {
                if (f[i] == f[j])
                    t = 0;
                else if (f[i] == 0 || f[i] >= l)
                    t = 0;
                else
                    t = 1;
                if (t == 0) break;
            }
        }
        if (t == 0)
            printf("Not jolly");
        else
            printf("Jolly");
        if (n != 0)
            printf("\n");
    }
    return 0;
}
