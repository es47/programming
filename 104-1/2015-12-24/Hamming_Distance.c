#include <stdio.h>
int ham(int a, int b)
{
    int i, d;
    d = 0;
    i = a ^ b;
    while(i)
    {
        if(i & 1)
            d++;
        i >>= 1;
    }
    return d;
}
int main()
{
    int n, t, i, j, k, d;
    unsigned int N[510];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &t);
        for(i = 0; i < t; i++)
            scanf("%d", N + i);
        d = 0;
        for (i = 0; i < t; i++)
            for (j = i + 1; j < t; j++)
                if((k = ham(N[i], N[j])) > d)
                    d = k;
        printf("%d", d);
        if(n != 0)
            printf("\n");
    }
    return 0;
}
