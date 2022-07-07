/***************************************
 * 22S - Lab05 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347 *
 ************************************** **/

/* Passing an array to a function. */

#include <stdio.h>

#define MAX_INPUT 22

void display(int *);
int largest(int *);

int main(int argc, char *argv[])
{
    int array[MAX_INPUT], count;

    /* Input MAX_INPUT values from the stdin keyboard. */
    int i;
    count = 0;

    while (scanf("%d", &i) != EOF)
    {
        /* store in array[count] without using [] */
        *(array + count) = i;
        count++;
    }

    /* Adding a placeholder to the last value in the array
    to let the program know that it ends here. */
    *(array + count) = '-';

    /* Call function and display the return value. */
    printf("Inputs: ");
    display(array);

    printf("\nLargest value: %d\n", largest(array));

    return 0;
}

/* displays the content of int array */
void display(int *arr)
{
    int i;
    /* Print all the elements one by on up until the value - */
    for (i = 0; *(arr + i) != '-'; i++)
        printf("%d ", *(arr + i));
}

/* This function returns the largest value */
/* in the int array */
int largest(int *arr)
{
    int i;
    /* Set the largest value as the start index of the array. */
    int largest = *(arr);
    for (i = 0; *(arr + i) != '-'; i++)
    {
        /* If the next index in the array is larger than
        the current largest, set it as the new largest. */
        if (*(arr + i) > largest)
            largest = *(arr + i);
    }
    return largest;
}
