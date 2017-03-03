#include <stdio.h>
main()
{
    int ncase;
    int x, y, z;
    int time, i, j;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d %d", &x, &y);
        time = 1;
        i = x;
        j = y;
        while (i % j != 0)
        {
            z = i % j;
            i = j;
            j = z;
            time++;
        }
        printf("gcd(%d,%d)=%d, using %d division.\n", x, y, j, time);
    }
}
