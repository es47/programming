#include<stdio.h>
int main()
{
    int n, i, last[2010], min, temp, right, left, a, ans;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        right = left = 0;
        for(i = 0; i < 2000; i++)
            last[i]=-1;
        min = n;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if(last[a] == -1)
                last[a] = i;
            else
            {
                temp = i - last[a];
                if(temp < min)
                {
                    min = temp;
                    right = i;
                    left = last[a];
                    ans = a;
                }
                last[a] = i;
            }
        }
        if(right == 0 && left == 0)
            printf("No solution\n");
        else
            printf("(%d,%d):%d\n", left, right, ans);
    }
}
