#include <stdio.h>
typedef struct
{
    int day;
    int dline;
}
Hw ;
Hw hw[1024];
int cmp(const void* a, const void* b)
{
    if(((Hw*)a)->dline != ((Hw*)b)->dline)
        return ((Hw*)a)->dline - ((Hw*)b)->dline;
    else
        return ((Hw*)a)->day < ((Hw*)b)->day;
}
main()
{
    int n, nn, i, j;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &nn);
        for(i = 0; i < nn; i++)
            scanf("%d", &hw[i].day);
        for(i = 0; i < nn; i++)
            scanf("%d", &hw[i].dline);
        qsort(hw, nn, sizeof(Hw), cmp);
        int td = 0;
        for(i = 0; i < nn; i++)
        {
            td = td + hw[i].day;
            if(td > hw[i].dline) break;
        }
        if(i != nn)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
