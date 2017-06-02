#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1000
#define CASE 1000
int RECOGNIZE(char email[][CASE], int ncase, char recognize[][CASE],int *r_row)     //辨識是否為email格式
{
    int e_row, e_column;
    int at_flag;
    for (e_row = 0; e_row < ncase; e_row++)
    {
        at_flag = 0;
        for (e_column = 0; e_column < strlen(email[e_row]); e_column++)            //檢查每個信箱有幾個@
        {
            if (email[e_row][e_column] == '@')
                at_flag++;
        }
        if (at_flag == 1)                                                           //若只有一個@
        {
            for (e_column = 0; e_column < strlen(email[e_row]); e_column++)         //將字串複製到recognize內
                recognize[*r_row][e_column] = email[e_row][e_column];
            *r_row += 1;                                                            //紀錄有幾個正確的case
            for (e_column = strlen(email[e_row]); e_column < 30; e_column++)        //將email中正確的字串後輸入到固定位置的空白
                email[e_row][e_column] = ' ';
            printf("%s", email[e_row]);                                             //輸出email的字串至空白
            printf("=> valid\n");                                                   //輸出有效的
        }
        else                                                                        //無效的字串
        {
            for (e_column = strlen(email[e_row]); e_column < 30; e_column++)        //將email中正確的字串後輸入到固定位置的空白
                email[e_row][e_column] = ' ';
            printf("%s", email[e_row]);                                             //輸出email的字串至空白
            printf("=> NOT valid\n");                                               //輸出無效的
        }
    }
}
int COPY(char recognize[][CASE], int r_case, char name[][CASE])            //複製name
{
    int row, column;
    for (row = 0; row < LEN; row++)                                        //將name全部清空
        for (column = 0; column < CASE; column++)
            name[row][column] = 0;
    for (row = 0; row < r_case; row++)                                     //複製recognize內到@前的字串
        for (column = 0; column < strlen(recognize[row]); column++)
        {
            if(recognize[row][column] == '@') break;
            name[row][column] = recognize[row][column];
        }
}
int compare(const void *ptr1, const void *ptr2)                            //比較
{
    return (strcmp((char *) ptr1, (char *) ptr2));
}
int USERNAME_SORT(char recognize[][CASE], int r_case, char name[][CASE])               //username的排序
{
    int n_row, column, r_row, time;
    printf("Sort by Username:\n");
    qsort (name, r_case, sizeof(char) * CASE, compare);                                //比較name的排序
    for (n_row = 0; n_row < r_case; n_row++)
        for (r_row = 0; r_row < r_case; r_row++)
        {
            time = 0;
            for (column = 0; column < strlen(recognize[r_row]); column++)              //比較兩者在@前的字串是否相同
            {
                if (recognize[r_row][column] == '@') break;
                if (name[n_row][column] == recognize[r_row][column])
                    time++;
                else
                    time--;
            }
            if (time == strlen(name[n_row]))                                           //若字串相同
            {
                for (column = strlen(name[n_row]); column < strlen(recognize[r_row]); column++)      //將recognize複製到name
                    name[n_row][column] = recognize[r_row][column];
                for (column = 0; column < strlen(recognize[r_row]); column++)                        //清空被複製的recognize
                    recognize[r_row][column] = 0;
            }
        }
    for (n_row = 0; n_row < r_case; n_row++)                                           //輸出排序及複製後的name
        puts (name[n_row]);
    printf("\n");
}
int DOMAIN_SORT(char recognize[][CASE], int r_case)                        //domain的排序
{
    int r_row;
    printf("Sort by Domain:\n");
    qsort (recognize, r_case, sizeof(char) * CASE, compare);               //比較recognize的排序
    for (r_row = 0; r_row < r_case; r_row++)                               //輸出排序後的recognize
        puts (recognize[r_row]);
}
int main(void)
{
    int ncase, i, r_row, r_case;
    char email[LEN][CASE], recognize[LEN][CASE];
    while(scanf("%d", &ncase) != EOF)
    {
        for (r_case = 0; r_case < ncase; r_case++)
            scanf("%s", email[r_case]);
        r_row = 0;
        RECOGNIZE(email, ncase, recognize, &r_row);
        printf("--------------------------------\n");
        COPY(recognize, r_row, email);
        USERNAME_SORT(recognize, r_row, email);
        DOMAIN_SORT(email, r_row);
    }
}
