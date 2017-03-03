#include <stdio.h>
typedef struct
{
    int w;
    int h;
}
PAIR;
PAIR pair[100000];
int cmp(const PAIR *e1, const PAIR *e2)
{
    return e2 -> w - e1 -> w;
}
void main()
{
    int ncase, tile, i, j, k, max, total;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &tile);
        j = tile;
        for (i = 0; i < tile; i++)
        {
            scanf("%d", &pair[i].w);
            scanf("%d", &pair[i].h);
            if (pair[i].w != pair[i].h)
            {
                pair[j].w = pair[i].h;
                pair[j].h = pair[i].w;
                j++;
            }
        }
        qsort(pair, j, sizeof(PAIR), cmp);
        for (i = 0; i < j; i++)
            if (pair[i].w == pair[i + 1].w)
            {
                if (pair[i].h > pair[i + 1].h)
                    pair[i + 1].h = pair[i].h;
                else
                    pair[i].h = pair[i + 1].h;
            }
        total = 0;
        for (i = 0; i < j; i++)
            if (pair[i].w > pair[i + 1].w)
                total += pair[i].h;
        printf("%d\n", total);
    }
}
