#include<stdio.h>
main()
{
    int n,m,i,j,k,co1,co2,emp,add[60];
    char s[100000],c;
    scanf("%d %d",&n, &m);
    int al[60][60] = {0};
    for(i=0; i<n; i++)
    {
        scanf("%s",s);
        for(j=0; s[j]!='\0'; j++)
        {
            if(s[j]>='a')
                al[i][s[j]-71]=1;
            else
                al[i][s[j]-65]=1;
        }
    }
    for (k=0; k<m; k++)
    {
        scanf("%d %c %d",&co1,&c,&co2);
        for(i=0; i<60; i++)
            add[i]=0;
        emp=1;
        for(j=0; j<60; j++)
            add[j] = al[co1][j] + al[co2][j];
        if(c=='*')
        {
            for (i=0; i<26; i++)
                if(add[i]==2)
                {
                    printf("%c",(i+65));
                    emp=0;
                }
            for(i=26; i<60; i++)
                if(add[i]==2)
                {
                    printf("%c",(i+71));
                    emp=0;
                }
        }
        if (c=='+')
        {
            for (i=0; i<26; i++)
                if(add[i]==1||add[i]==2)
                {
                    printf("%c",(i+65));
                    emp=0;
                }
            for(i=26; i<60; i++)
                if(add[i]==1||add[i]==2)
                {
                    printf("%c",(i+71));
                    emp=0;
                }
        }
        if (emp==1)
            printf("-1");
        printf("\n");
    }
    return 0;
}
