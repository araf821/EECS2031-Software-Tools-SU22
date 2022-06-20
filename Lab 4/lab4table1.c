#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define numROWS 20
#define numCOLUMNS 30

int main(int argc, char *argv[])
{
    char inputs_table[numROWS][numCOLUMNS];
    char name[10];
    char ageS[10];
    char rateS[10];
    int age, i, counter = 0;
    float rate;

    printf("Enter name, age and rate: ");
    scanf("%s %s %s", name, ageS, rateS);

    while (strcmp(name, "xxx") != 0)
    {
        /* Step 1: Add the default inputs to the next available row */
        sprintf(inputs_table[counter], "%s %s %s", name, ageS, rateS);
        counter++; /* Increment counter to proceed to the next row. */

        /* Step 2: Convert and modify the values to be added to the next row. */
        age = (int)atof(ageS);          /* String ageS to int age. */
        rate = (float)atof(rateS);      /* String rateS to float rate. */

        for (i = 0; i < strlen(name); i++)
            name[i] = toupper(name[i]); /* Set the characters in the name to uppercase. */
        age += 10;                      /* Add 10 to the age. */
        rate *= 1.5;                    /* Increate the rate by 50%. */

        /* Step 3: Add the new values to the string for the next available row. */
        sprintf(inputs_table[counter], "%s %d %.2f", name, age, rate);
        counter++;

        /* Read the inputs again. */
        printf("Enter name, age and rate: ");
        scanf("%s %s %s", name, ageS, rateS);
    }

    printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);

    /* Now display the input_table row-by-row. */
    for (i = 0; i < counter; i++)
    {
        printf("row[%d]: %s\n", i, inputs_table[i]);
    }

    return 0;
}
