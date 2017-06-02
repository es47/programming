#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 30
#define CASE 10000
int JUDGE(char line[], int len)
{
    int i = 0, age = 0, flag = 0;
    while(line[i] != ',')
        i++;
    for (i++; line[i] != ','; i++)
    {
        if (line[i] > '9' && line[i] < '0')          //檢查年齡輸入有無錯誤
            flag = -1;
        if (flag == -1) break;
        age *= 10;                                   //若無錯誤，計算年齡
        age += line[i];
    }
    if (age < 0)                                     //檢查年齡是否錯誤
        flag = -1;
    for (i++; i < len; i++)
    {
        if (line[i] > 'z' && line[i] < 'a')          //檢查性別輸入有無錯誤
            flag = -1;
        if (flag == -1) break;
    }
    return flag;
}
void COPY(char line[], char input[][NAME], int len, int ncase)
{
    int i, j = 0;
    for (i = 0; i < len; i++)                        //將正確之輸入複製到陣列中
    {
        input[ncase][j] = line[i];
        j++;
    }
}
void PRINTF(char input[][NAME], int len, int ncase)    //輸出資料
{
    int i = 0;
    printf("name=");
    while(input[ncase][i] != ',')
    {
        printf("%c", input[ncase][i]);
        i++;
    }
    printf(",age=");
    i++;
    while(input[ncase][i] != ',')
    {
        printf("%c", input[ncase][i]);
        i++;
    }
    printf(",sex=");
    for (i++; i < len; i++)
        printf("%c", input[ncase][i]);
    printf("\n");
}
void LARGE(char input[][NAME], char temp[][NAME])           //若輸入資料過多
{
    int i, j;
    for (i = 0; i < CASE; i++)
        for (j = 0; j < NAME; j++)
            temp[i][j] = input[i][j];
    input = malloc((CASE * CASE) * NAME * sizeof(char));    //取得更多空間
    for (i = 0; i < CASE; i++)
        for (j = 0; j < NAME; j++)
            input[i][j] = temp[i][j];
}
int main()
{
    int i, flag, len, ncase = 0;
    char line[NAME];
    char **input;
    input = malloc(CASE * NAME * sizeof(char));
    while(gets(line) != NULL)
    {
        if (ncase == CASE)
        {
            printf("queue/stack full, allocate double size NN\n");
            char **temp;
            temp = malloc(CASE * NAME * sizeof(char));
            LARGE(input, temp);
        }
        len = strlen(line);
        flag = JUDGE(line, len);
        if (flag == -1)
        {
            printf("wrong input\n");
            continue;
        }
        COPY(line, input, len, ncase);
        PRINTF(input, len, ncase);
        ncase++;
    }
    return 0;
}
