#include<stdio.h>
#include<stdlib.h>
#define N 50000
typedef struct
{
    unsigned int left;
    unsigned int right;
} interval;
int compare( const void *arg1, const void *arg2 )
{
    interval *ptr1 = (interval*)arg1;
    interval *ptr2 = (interval*)arg2;
    return ptr1->left - ptr2->left;
}

int main()
{
    int ncase, line, i, j , temp;
    unsigned int left[N], right[N], min, max, ans;
    interval l[N];
    scanf("%d", &ncase);
    while(ncase--)
    {
        max = min = ans = temp = 0;
        scanf("%d", &line);
        if(line == 0)
        {
            printf("0\n");
            continue;
        }
        for(i = 0; i < line; i++)
        {
            scanf("%u%u", &l[i].left, &l[i].right);
            if(l[i].left > l[i].right)
            {
                temp = l[i].left;
                l[i].left = l[i].right;
                l[i].right = temp;
            }
        }
        qsort(l, line, sizeof(interval), compare);
        min = l[0].left;
        max = l[0].right;
        for(i = 1; i < line; i++)
        {
            if(max >= l[i].left && max < l[i].right)
                max = l[i].right;
            if(max < l[i].left)
            {
                ans += max - min;
                max = l[i].right;
                min = l[i].left;
            }
        }
        ans += max - min;
        printf("%u\n", ans);
    }
}
