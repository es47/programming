#include<stdio.h>
#define N 200010
int main()
{
    int ncase, weight, material, a[N], total, i, j, k, time;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %d", &weight, &material);
        memset(a, 0, sizeof(a));
        a[0] = 1;
        total = 0;
        for(i = 0; i < weight; i++)
        {
            scanf("%d", &k);
            for(j = total; j >= 0; j--)
                if(a[j])
                    a[j + k] = 1;
            total += k;
        }
        for(i = 0, time = 0; i < material; i++)
        {
            scanf("%d", &k);
            if(k <= total && (a[k] == 1))
                time++;
        }
        printf("%d\n", time);
    }
    return 0;
}
