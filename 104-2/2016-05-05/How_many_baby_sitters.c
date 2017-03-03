#include <stdio.h>
typedef struct
{
    int left;
    int right;
} interval;
interval a[1000];
int cmp(const interval *e1, const interval *e2)
{
    return e1 -> left - e2 -> left;
}
main()
{
    int ncase, i, j, k, temp, max, ans, temp_left;
    char buffer[100000];
    gets(buffer);
    sscanf(buffer,"%d", &ncase);
    gets(buffer);
    while (ncase--)
    {
        gets(buffer);
        i = 0;
        while (buffer[0] != 0)
        {
            sscanf(buffer,"%d %d", &(a[i].left), &(a[i].right));
            if (a[i].left > a[i].right)
            {
                temp = a[i].left;
                a[i].left = a[i].right;
                a[i].right = temp;
            }
            i++;
            if (gets(buffer)==NULL) break;
        }
        qsort(a, i, sizeof(interval), cmp);
        max = 0;
        for (j = 0; j < i; j++)
            if (a[j].left == 0 && max < a[j].right)
                max = a[j].right;
        for (j = 0; j < i; j++)
            if (a[j].left == 0)
                a[j].right = max;
        ans = 1;
        temp = temp_left = 0;
        for (j = 0; j < i; j++)
        {
            for (k = j; k < i; k++)
                if (a[k].left <= max + 1 && temp < a[k].right)
                {
                    temp = a[k].right;
                    temp_left = a[k].left;
                }
            max = temp;
            if (temp_left != 0)
                ans++;
            if (max == 199) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
