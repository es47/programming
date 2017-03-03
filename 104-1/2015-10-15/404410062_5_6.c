#include <stdio.h>
main()
{
    int ncase;
    int year, month, day;
    int total, md;
    scanf("%d", &ncase);
    while (ncase--)
    {
        scanf("%d/%d/%d", &year, &month, &day);
        total = 0;
        if (year < 1970 || month > 12 || month < 1 || day < 1 || day > 31)
            total = 0;
        else
        {
            while (year > 1970)
            {
                if ((year % 400 == 0) || (year % 4 == 0 && (year % 100 != 0)))
                    total += 366;
                else
                    total += 365;
                year--;
            }
            month--;
            while (month > 0)
            {
                switch (month)
                {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                    md = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    md = 30;
                    break;
                case 2:
                    if ((year % 400 == 0) || (year % 4 == 0 && (year % 100 != 0)))
                        md = 29;
                    else
                        md = 28;
                    break;
                }
                total += md;
                month--;
            }
            total += day;
        }
        printf("%d\n", total);
    }
}
