#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 100
double integrate(double (*f)(double), double a, double b, double t)
{
    double r = 0.0, i;
    for(i = a; i <= b; i+= t)                                  //計算間格內的積分
        r += f(i);
    return r*t;
}
int TRAN(char f[], double number[])
{
    int i, j;
    j = 0;
    for (i = 0; i < strlen(f); i++)
    {
        if (f[i] <= '9' && f[i] >= '0')              //將各項係數分出
        {
            number[j] = f[i] - '0';
            j++;
        }
        if (f[i] == 'x')                               //如果是x的話
        {
            if (f[i - 1] == '+' || f[i - 1] == '-')    //前一項是加減的話
            {
                number[j] = 1;                         //係數訂為1
                j++;
            }
            if (f[i + 1] != '^')                       //後一項不是次方的話
            {
                number[j] = 1;                         //次方訂為1
                j++;
            }
        }
    }
    return j;
}
int POLY(double number[], int len)
{
    int i;
    for (i = 1; i < len; )                          //將函式積分
    {
        number[i] += 1;
        number[i - 1] = number[i - 1] / number[i];
        i += 2;
    }
    if (len % 2 == 1)                              //若有零次方
    {
        number[i] = 1;                             //將次方加一
        i = len + 1;
    }
    return i;
}
double INTEGRAL(double number[], double from, double to, int len)      //計算區間內之質
{
    int i, j;
    double max = 0.0, min = 0.0, temp, answer;
    for (i = 0; i < len; )                               //計算下限
    {
        temp = 1.0;
        for (j = 0; j < number[i + 1]; j++)
            temp *= from;
        temp *= number[i];
        min += temp;
        i += 2;
    }
    for (i = 0; i < len; )                            //計算上限
    {
        temp = 1.0;
        for (j = 0; j < number[i + 1]; j++)
            temp *= to;
        temp *= number[i];
        max += temp;
        i += 2;
    }
    answer = max - min;                              //相減得出答案
    return answer;
}
int main()
{
    int len, i;
    double y, from, to, t;
    char f[N];
    while(1)
    {
        gets(f);
        scanf("%lf,%lf,%lf", &from, &to, &t);
        y = integrate(sin, from, to, t);
        printf("sin from %lf to %lf = %lf\n", from, to, y);        //輸出sin的積分
        y = integrate(cos, from, to, t);
        printf("cos from %lf to %lf = %lf\n", from, to, y);        //輸出cos的積分
        double number[N] = {0};
        len = TRAN(f, number);
        len = POLY(number, len);
        y = INTEGRAL(number, from, to, len);
        printf("%lf\n", y);                                        //輸出函式的積分
    }
    return 0;
}
