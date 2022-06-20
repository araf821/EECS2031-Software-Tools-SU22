/***************************************
 * 22S - Lab4 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <string.h>

#define numROWS 20
#define numCOLUMNS 30

int main(int argc, char *argv[])
{
     char input_table[numROWS][numCOLUMNS];
     int current_row = 0;
     char name[10];
     int age, i;
     float rate;

     printf("Enter name, age and rate: ");
     fgets(input_table[current_row], 30, stdin);
     while (1)
     {
          /* Getting rid of the \n that is registered with fgets().
          Format: array[row][length of the row - 1] = 0 */
          input_table[current_row][strlen(input_table[current_row]) - 1] = 0;

          /* Assigning each field in the string to its respective variable. */
          sscanf(input_table[current_row], "%s %d %f", name, &age, &rate);
          
          /* End the program if name is detected to be "xxx" */
          if (strcmp(name, "xxx") == 0)
               break; /* End the loop if name is exit */
          current_row++; /* Increment to the next available row. */

          /* Modify the values to be stored in the next row. */
          for (i = 0; i < strlen(name); i++)
          {
               /* Capitalise the letters in the name if they're lowercase. */
               if (name[i] >= 'a' && name[i] <= 'z')
               {
                    name[i] = name[i] - 32; 
               }
          }
          age += 10;
          rate *= 1.5;

          /* Update the new available row with our modified variables. */
          sprintf(input_table[current_row], "%s %d %.2f", name, age, rate);
          current_row++; /* Increment to the next available row. */

          /* Get new data from the user. */
          printf("Enter name, age and rate: ");
          fgets(input_table[current_row], 30, stdin);
     }

     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
     /* now display the input_table row-by-row */
     for (i = 0; i < current_row; i++)
     {
          printf("row[%d]: %s\n", i, input_table[i]);
     }

     return 0;
}
