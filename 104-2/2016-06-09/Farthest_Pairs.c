#include<stdio.h>
int main()
{
    int n, i, last[2010], max, temp, right, left, a, ans;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)break;
        right = left = 0;
        for(i = 0; i < 2000; i++)
            last[i] = -1;
        max = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if(last[a] == -1)
                last[a] = i;
            else
            {
                temp = i - last[a];
                if(temp > max)
                {
                    max = temp;
                    right = i;
                    left = last[a];
                    ans = a;
                }
            }
        }
        if(right == 0 && left == 0)
            printf("No solution\n");
        else
            printf("(%d,%d):%d\n", left, right, ans);
    }
    return 0;
}
