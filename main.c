#include <stdio.h>
#include <stdlib.h>

int main() {
    int day, month, year;
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    if (year < 2024 || (year == 2024 && month < 3) || (year == 2024 && month == 3 && day < 14))
    {
        if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    f = f % 7;
    int weekday = (f + 5) % 7 + 1;

    if (month > 12) {
        month -= 12;
        year += 1;
    }

    printf("Day of the week: ");
    switch (weekday) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
    }

    int cday = day, cmonth = month, cyear = year;
    printf("All dates on the same weekday:\n");

    while (!(cyear > 2024 || (cyear == 2024 && cmonth > 3) || (cyear == 2024 && cmonth == 3 && cday > 14)))
    {
        int m = cmonth, y = cyear;
        if (m < 3)
        {
            m += 12;
            y -= 1;
        }
        int h = cday + (13 * (m + 1)) / 5 + (y % 100) + (y % 100) / 4 + (y / 100) / 4 + 5 * j;
        h = h % 7;
        int cweekday = (h + 5) % 7 + 1;

        if (cweekday == weekday)
        {
            printf("%02d/%02d/%04d\n", cday, cmonth, cyear);
        }

        cday++;
        int leapyear = cyear % 4 == 0 && (cyear % 100 != 0 || cyear % 400 == 0);
        int days = 31;
        if (cmonth == 2)
        {
            if (leapyear)
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
        }
        else if (cmonth == 4 || cmonth == 6 || cmonth == 9 || cmonth == 11)
        {
            days = 30;
        }
        if (cday > days)
        {
            cday = 1;
            cmonth++;
            if (cmonth > 12)
            {
                cmonth = 1;
                cyear++;
            }
        }
    }
    }
    else
    {
        printf("Incorrect date");
    }

    return 0;
}
