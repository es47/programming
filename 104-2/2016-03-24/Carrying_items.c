#include <stdio.h>
#define NUM 10000
int cmpr (const void *e1, const void *e2)
{
    return(*(int*)e1) - (*(int*)e2);
}
main()
{
    int ncase, item, student, i, j, sum;
    int it[NUM], st[NUM];
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %d", &item, &student);
        for (i = 0; i < item; i++)
            scanf("%d", &it[i]);
        for (i = 0; i < student; i++)
            scanf("%d", &st[i]);
        qsort(it, item, sizeof(int), cmpr);
        qsort(st, student, sizeof(int), cmpr);
        sum = 0;
        i = j = 0;
        while(i < item)
        {
            while((st[j] < it[i]) && (j < student))
                j++;
            if (j == student) break;
            sum += st[j];
            i++;
            j++;
        }
        if (j == student && i != item)
            sum = -1;
        printf("%d\n", sum);
    }
    return 0;
}
