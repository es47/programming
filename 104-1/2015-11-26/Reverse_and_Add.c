#include <stdio.h>
int same(int N[], int R[], int k)
{
    int i, j, l;
    j = 0;
    for (i = 0; i < k; i++)
    {
        if (N[i] == R[i])
            j++;
    }
    if (j == k)
        l = 1;
    else
        l = 0;
    return l;
}
int main()
{
    int n, t, q, a;
    int i, j, k, r;
    int R[15], N[15];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &q);
        a = 0;
        t = 0;
        while (a == 0)
        {
            r = 0;
            for (i = 0; q > 0; i++)
            {
                R[i] = q %10;
                q /= 10;
            }
            k = i - 1;
            for (j = 0; j < i; j++)
            {
                N[j] = R[k];
                k--;
            }
            if (same(N, R, i) == 1)
            {
                for (j = 0; j < i; j++)
                {
                    a += N[j];
                    if (j != i - 1)
                        a *= 10;
                }
            }
            else
            {
                for (j = 0; j < i; j++)
                {
                    q += N[j];
                    r += R[j];
                    if (j != i - 1)
                    {
                        q *= 10;
                        r *= 10;
                    }
                }
                q += r;
                t++;
            }
        }
        printf("%d %d", t, a);
        if (n != 0)
            printf("\n");
    }
    return 0;
}
