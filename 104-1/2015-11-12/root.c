#include <stdio.h>
double f(int p, double x, double c[])
{
    int i, j;
    double k, fx;
    j = 0;
    fx = 0;
    for ( ; p >= 0; p--)
    {
        k = 1;
        for (i = 0; i < p; i++)
            k *= x;
        fx += k * c[j];
        j++;
    }
    return fx;
}
int main()
{
    int p, t, i;
    double x, a, b, c[7], fl, fr, fm;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &p);
        for (i = 0; i <= p ; i++)
            scanf("%lf ", &c[i]);
        scanf("%lf %lf", &a, &b);
        do
        {
            fl = f(p, a, c);
            fr = f(p, b, c);
            x = (a + b) / 2;
            fm = f(p, x, c);
            if (fl * fm < 0)
                b = x;
            else
                a = x;
            if (fm < 0)
                fm = -fm;
        }
        while (fm > 0.000001);
        printf("%.5f", x);
        if (t != 0)
            printf("\n");
    }
    return 0;
}
