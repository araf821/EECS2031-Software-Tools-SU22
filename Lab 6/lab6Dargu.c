/***************************************
 * 22S - Lab06 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getSum(char *[], int);
int getDiff(char *[], int);

/* argc = # of arguments including a.out */
/* *argv[] = char array of pointers pointing to every argument */
int main(int argc, char *argv[])
{
    printf("There are %d arguments (excluding \"%s\")\n", argc - 1, argv[0]);

    /* Determine whether or not the user wants to find the sum or difference. */
    if (strcmp(argv[1], "sum") == 0)
    {
        getSum(argv, argc);
    }
    else
    {
        getDiff(argv, argc);
    }

    return 0;
}

int getSum(char *pArr[], int n)
{
    int i = 2;
    /* Use atoi to change the arg to an integer */
    int sum = atoi(pArr[i]);

    /* Use atoi to change the arg to an integer */
    printf("%d", atoi(pArr[2]));

    /* Starting from i = 0 (fourth arg) because we've already added
    the first integer (third arg) to our sum and printed it out */
    for (i = 3; i < n; i++)
    {
        /* Add the integer to the sum and then print out what is being added */
        sum += atoi(pArr[i]);
        printf(" + %d", atoi(pArr[i]));
    }
    /* Print the result of the calculation */
    printf("\n= %d\n", sum);
}

int getDiff(char *pArr[], int n)
{
    int i = 2;
    /* Use atoi to change the arg to an integer */
    int diff = atoi(pArr[i]);

    /* Use atoi to change the arg to an integer */
    printf("%d", atoi(pArr[2]));

    /* Starting from i = 0 (fourth arg) because we've already added
    the first integer (third arg) to our diff and printed it out */
    for (i = 3; i < n; i++)
    {
        /* Sub the integer from the diff and print out what is being subtracted */
        diff -= atoi(pArr[i]);
        printf(" - %d", atoi(pArr[i]));
    }

    /* Print the result of the calculation */
    printf("\n= %d\n", diff);
}