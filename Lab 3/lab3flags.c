/***************************************
 * 22S - Lab03 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * Yorku Student #: 218124347
 ************************************** **/

#include <stdio.h>

#define SIZE 16
#define SIZE2 10

void printBinary(short int);
int power(int, int);

/*counting digits*/

int main()
{
   int c, i;
   short flags = 0;
   printf("flags: ");
   printBinary(flags);
   printf("\n");

   short flagTracker[SIZE2] = {0};

   while ((c = getchar()) != EOF)
   {
      if (c >= 48 && c <= 57)
      {
         /* if c is a digit with numerical value k, turn bit-k of flags on */
         for (i = 48; i < 58; i++)
         {
            if (c == i)
            {
               /* If c is a particular digit, the index(digit)
               of flagTracker is changed to 1 */
               flagTracker[i - 48] = 1;
            }
         }
      }
   }

   for (i = 0; i < 10; i++)
   {
      /*
         If the index i of flagTracker is a 1,the
         value of the bit at 1 is added to flags.
      */
      if (flagTracker[i] == 1)
      {
         flags += power(2, i);
      }
   }

   printf("\nflags: ");
   printBinary(flags);
   printf("\n");

   /*
      Outputting a 'Yes' or 'No' based on whether or not the
      digit 0-9 exists within the input string.
   */
   for (i = 0; i <= 9; i++)
   {
      int check = flagTracker[i]; /* is bit i is on or off, i.e., 0 or 1? */
      if (check)                  /* if check != 0 */
         printf("%d: %s\n", i, "Yes");
      else
         printf("%d: %s\n", i, "No");
   }

   return 1;
}

void printBinary(short int n)
{

   int cou = SIZE - 1;
   int k[SIZE] = {0};

   while (n && cou >= 0)
   {
      if (n & 1)
         /* Assign a 1 to the bit if n is 1 */
         k[cou] = 1;
      else
         /* Assign a 0 to the bit if n is 0 */
         k[cou] = 0;

      n >>= 1;
      cou--;
   }

   int i;
   for (i = 0; i < SIZE; i++)
   {
      /* Print the bits */
      printf("%d", k[i]);

      /* Leave a gap in between after every 8th bit */
      if ((i + 1) % 8 == 0)
      {
         printf(" ");
      }
   }
}

int power(int base, int exp)
{
   if (exp == 0)
   {
      return 1;
   }
   else if (exp == 1)
   {
      return base;
   }
   int i, result = base;
   for (i = 2; i <= exp; i++)
   {
      result *= base;
   }
   return result;
}