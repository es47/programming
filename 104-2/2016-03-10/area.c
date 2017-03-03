#include <fcntl.h>
#include <stdio.h>
#include <math.h>
typedef struct {int x, y;} POINT;
int rect(POINT p, POINT q)
{
    int area;
    area = (p.x - q.x) * (p.y - q.y);
    return (area < 0)? -area: area;
}
void main()
{
    int ii, i, j, k, n[100], y[100], m, a;
    POINT p[100];
    unsigned long area;
    scanf("%d", &a);
    for (ii = 0; ii < a; ii++)
    {
        scanf("%d", &m);
        for (i = 0; i < m; i++)
            scanf("%d%d", &(p[i].x), &(p[i].y));
        area = 0;
        for (i = 0; i < m; i++)
            for (j = i + 1; j < m; j++)
        {
            k = rect(p[i], p[j]);
            if (k > area)
                area = k;
        }
        printf("%lu\n", area);
    }
    return 0;
}
