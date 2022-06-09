/***************************************
 * 22S - Lab03 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * Yorku Student #: 218124347
 ************************************** **/

#include <stdio.h>

int countDays(int, int, int);
int isLeap(int);

int main()
{

    int year, month, day, elapsed;

    printf("Enter date ('YYYY MM DD'): ");
    scanf("%d %d %d", &year, &month, &day);

    while (year >= 0)
    {
        /* Getting the total number of days elapsed */
        elapsed = countDays(month, day, isLeap(year));

        if (!isLeap(year))
        {
            printf("%d days of the year %d have elapsed\n\n", elapsed, year);
        }
        else
        {
            printf("%d days of the year %d have elapsed [leap year]\n\n", elapsed, year);
        }

        /* Restarting the program */
        printf("Enter date ('YYYY MM DD'): ");
        scanf("%d %d %d", &year, &month, &day);
    }

    return 0;
}

int countDays(int month, int days, int isLeap)
{
    int i, totalDays = 0;

    /* Initiating the number of days each month has. */
    int daysInAMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (i = 0; i < month - 1; i++)
    {
        /* Only upto the second last 'month', the days are added to the totalDays. */
        totalDays += daysInAMonth[i];
    }

    /* Checking for leap year */
    if (month > 2)
    {
        if (isLeap == 1)
        {
            /* One extra day is added to the totalDays if it is a leap year
            and if the month provided is already past February. */
            totalDays++;
        }
    }

    /* Adding the remainder days to the totalDays */
    totalDays += days;
    return totalDays;
}

int isLeap(int year)
{
    if (year % 4 == 0)
    {
        return 1;
    }
    return 0;
}