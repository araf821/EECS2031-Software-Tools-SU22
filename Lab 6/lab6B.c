/* Reads in a list of strings from the keyboard, re-organize them */
/* and then displays them on the screen. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINES 35
#define MAX_COLS 50

void exchange2D(char[][MAX_COLS], int);
void print2D(char[][MAX_COLS], int);

int main()
{
    char inputs[MAX_LINES][MAX_COLS];
    printf("sizeof inputs: %ld\n\n", sizeof inputs);
    int i = 0;

    /* Read in the lines from the keyboard now, using function fgets() */
    printf("Enter string: ");
    fgets(inputs[i], MAX_LINES, stdin);

    while (strcmp(inputs[i++], "xxx\n"))
    {
        printf("Enter string: ");
        fgets(inputs[i], MAX_LINES, stdin);
    }
    printf("\n");

    /* Decrement i so that that the line("xxx") won't be printed. */
    i--;

    /* display the array by calling function print2D(...) */
    print2D(inputs, i);

    /* swap the first and second row here */
    char tempString[35];
    strcpy(tempString, inputs[0]); /* Store first row in the temporary string */
    strcpy(inputs[0], inputs[1]);  /* Replace row 1 with row 2 */

    /* Replace contents of row 2 with the initial contents of row 1 */
    strcpy(inputs[1], tempString);

    /* call sub-function exchange2D() to swap some other rows */
    exchange2D(inputs, i);

    printf("\n== after swapping ==\n");

    /* display the exchanged array by calling function print2D() */
    print2D(inputs, i);

    return 0;
}

/* do exchange of rows. have to involve data movement */
void exchange2D(char p[][MAX_COLS], int n)
{
    int i;
    char tempString[35];
    for (i = 2; i < n - 1; i += 2)
    {
        strcpy(tempString, p[i]);
        strcpy(p[i], p[i + 1]);
        strcpy(p[i + 1], tempString);
    }
}

/* print the 2D array, row by row */
void print2D(char p[][MAX_COLS], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("[%d]: %s", i, p[i]);
    }
}
