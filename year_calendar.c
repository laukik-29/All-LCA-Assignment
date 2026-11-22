#include <stdio.h>

int isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getDaysInMonth(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

/* Returns 0 for Sunday, 1 for Monday, ..., 6 for Saturday. */
int getFirstDayOfYear(int year)
{
    /* 1 January, year 1 was a Monday (1 when Sunday is 0). */
    int day = 1;
    int currentYear;

    for (currentYear = 1; currentYear < year; currentYear++) {
        day = (day + (isLeapYear(currentYear) ? 366 : 365)) % 7;
    }
    return day;
}

int main(void)
{
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    int year, month, firstDay, days, date, column;

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Please enter a valid positive year.\n");
        return 1;
    }

    firstDay = getFirstDayOfYear(year);

    for (month = 1; month <= 12; month++) {
        days = getDaysInMonth(month, year);

        printf("\n\n          %s %d\n", months[month - 1], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (column = 0; column < firstDay; column++) {
            printf("    ");
        }

        for (date = 1; date <= days; date++) {
            printf("%4d", date);
            if ((firstDay + date) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");

        firstDay = (firstDay + days) % 7;
    }

    return 0;
}
