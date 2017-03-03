#include <stdio.h>
main()
{
    char line[1000], *token;
    char sep[] = " ,;";
    int i, sum, x;
    while (gets (line) != NULL)
    {
        i = 0;
        sum = 0;
        token = strtok(line, sep);
        while (token != NULL)
        {
            i++;
            sum += atoi(token);
            token = strtok(NULL, sep);
        }
        printf("%d\n", sum);
    }
    return 0;
}
