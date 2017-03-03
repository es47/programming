#include<stdio.h>
#define N 10000
int main()
{
    int ncase, spy, i, leader[N], table[N], phone;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &spy);
        for(i = 1; i < spy; i++)
            scanf("%d", &leader[i]);
        for(i = 0; i < spy; i++)
            table[i] = 0;
        phone = 0;
        for (i = spy - 1; i > 0; i--)
        {
            if (!table[i])
                table[leader[i]] = 1;
            else
                phone++;
        }
        phone += table[0];
        printf("%d\n", phone);
    }
}
