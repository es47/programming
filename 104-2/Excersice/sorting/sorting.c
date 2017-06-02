#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N 1000
void number_swap(int *a, int *b)                 //數字交換
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int number_partion(int number[], int p, int r)       //數字的分割
{
    int pivotIndex, pivot, i, j;
    pivotIndex = p + rand()%(r - p + 1);             //基準為隨機數
    i = p - 1;
    pivot = number[pivotIndex];
    number_swap(&number[pivotIndex], &number[r]);     //將基準與最後一個交換
    for (j = p; j < r; j++)
        if (number[j] < pivot)                         //若是第j個小於基準
        {
            i++;
            number_swap(&number[i], &number[j]);       //將第i個與第j個交換
        }
    number_swap(&number[i + 1], &number[r]);           //將第i+1個與最後一個交換
    return i + 1;
}
void number_quick_sort(int number[], int p, int q)     //數字的quicksort
{
    int j;
    if (p < q)                                         //如果兩者都不是最後一個
    {
        j = number_partion(number, p, q);             //進入數字的分割
        number_quick_sort(number, p, j - 1);          //右邊進入數字的quicksort
        number_quick_sort(number, j + 1, q);          //左邊進入數字的quicksort
    }
}
void letter_swap(char *a, char *b)                    //字母交換
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int letter_partion(char letter[][N], int p, int r, int row)     //字母的分割
{
    int pivotIndex, pivot, i, j, max, k;
    pivotIndex = p + rand()%(r - p + 1);
    i = p - 1;
    pivot = letter[pivotIndex][row];                            //基準為隨機數
    max = (strlen(letter[pivotIndex]) > strlen(letter[r]))? strlen(letter[pivotIndex]): strlen(letter[r]);
    for (j = 0; j < max; j++)                                    //將基準與最後一個交換
        letter_swap(&letter[pivotIndex][j], &letter[r][j]);
    for (j = p; j < r; j++)
        if (letter[j][row] < pivot)                              //若是第j個小於基準
        {
            i++;
            max = (strlen(letter[i]) > strlen(letter[j]))? strlen(letter[i]): strlen(letter[j]);
            for (k = 0; k < max; k++)                            //將第i個與第j個交換
                letter_swap(&letter[i][k], &letter[j][k]);
        }
    max = (strlen(letter[i + 1]) > strlen(letter[r]))? strlen(letter[i + 1]): strlen(letter[r]);
    for (k = 0; k < max; k++)
        letter_swap(&letter[i + 1][k], &letter[r][k]);              //將第i+1個與最後一個交換
    return i + 1;
}
void letter_quick_sort(char letter[][N], int p, int q, int row)        //字母的quicksort
{
    int j;
    if (p < q)                                            //如果兩者都不是最後一個
    {
        j = letter_partion(letter, p, q, row);             //進入字母的分割
        letter_quick_sort(letter, p, j - 1, row);          //右邊進入字母的quicksort
        letter_quick_sort(letter, j + 1, q, row);          //左邊進入字母的quicksort
    }
}
int main()
{
    int i, n, number[N], flag, j, k, temp, max, c;
    char letter[N][N];
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("file1", "r");
    assert(fp1 != NULL);
    fp2 = fopen("file2", "w");
    assert(fp2 != NULL);
    while((fscanf(fp1, "%d", &flag)) != EOF)          //判斷是數字或字母
    {
        if (flag == 0) break;
        if (flag == 1)                               //若是1進入數字的quicksort
        {
            fscanf(fp1, "%d", &n);                         //輸入多少case
            for (i = 0; i < n; i++)
                fscanf(fp1, "%d", &number[i]);
            number_quick_sort(number, 0, n - 1);     //進入數字的quicksort
            for (i = 0; i < n; i++)
                fprintf(fp2, "%d\n", number[i]);
            fprintf(fp2, "\n");
        }
        else                                         //若不是1進入字母的quicksort
        {
            fscanf(fp1, "%d", &n);                         //輸入多少case
            max = 0;
            for (i = 0; i < n; i++)
            {
                fscanf(fp1, "%s", letter[i]);
                max = (strlen(letter[i]) > max)? strlen(letter[i]): max;
            }
            letter_quick_sort(letter, 0, n - 1, 0);  //進入字母的quicksort
            for (i = 0; i < max; i++)                  //第i行
            {
                for (j = 0; j < n; j++)
                {
                    temp = 0;
                    k = j;
                    while (letter[j][i] == letter[j + 1][i])    //temp
                    {
                        temp = 1;
                        j++;
                    }
                    if (temp == 1)                               //如果temp等於1
                        letter_quick_sort(letter, k, j, i + 1);   //進入字母的quicksort
                }
                if (temp == 0) break;                          //如果temp等於0
            }
            for (i = 0; i < n; i++)
                fprintf(fp2, "%s\n", letter[i]);
            fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
