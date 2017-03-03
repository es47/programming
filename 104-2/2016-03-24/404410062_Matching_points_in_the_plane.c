#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 10000
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int i, n, ii, nn, j;
    char line[10000];
    char *token;
    double totald;
    int p1[N], p2[N];
    gets(line);
    sscanf(line, "%d", &nn);
    for (ii = 0; ii < nn; ii++)
    {
        gets(line);
        i = 0;
        token = strtok(line, " \0");
        while (token != NULL)
        {
            p1[i] = atoi(token);
            i++;
            token = strtok(NULL, " \0");
        }
        n = i;
        gets(line);
        j = 0;
        for (i = 0; i < n; i++)
        {
            sscanf(line + j, "%d", p2 + i);
            while(line[j] != ' ' && line[j])
                j++;
            while(line[j] == ' ')
                j++;
        }
        for (i = 0; i < n; i++)
            p1[i] = abs(p1[i]);
        for (i = 0; i < n; i++)
            p2[i] = abs(p2[i]);
        qsort(p1, n, sizeof(int), cmp);
        qsort(p2, n, sizeof(int), cmp);
        totald = 0;
        for (i = 0; i < n; i++)
            totald += sqrt(p1[i] * p1[i] + p2[n - i - 1] * p2[n - 1 - i]);
        printf("%d\n", (int) totald);
    }
}
