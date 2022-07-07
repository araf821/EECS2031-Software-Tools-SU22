/***************************************
 * 22S - Lab05 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347 *
 ************************************** **/

#include <stdio.h>
#include <string.h>

#define SIZE 46

void sortArr(char *string);
void sortArr2(char *string);
void swap(char *, char *);

int main()
{
   char arr[SIZE];
   char arrB[SIZE];
   fgets(arr, SIZE, stdin);
   while (strcmp(arr, "quit\n") != 0)
   {
      /* manually remove the trailing \n */
      arr[strlen(arr) - 1] = 0;

      strcpy(arrB, arr);

      sortArr(arr);
      printf("%s\n", arr);

      sortArr2(arrB);
      printf("%s\n\n", arrB);

      fgets(arr, SIZE, stdin);
   }
   return 0;
}

void sortArr(char *string)
{
   /* ------------------------------ BUBBLE SORT ------------------------------*/
   int i, j;

   for (i = 0; i < strlen(string) - 1; i++)
   {
      for (j = 0; j < strlen(string) - i; j++)
      {
         if (*(string + j) < *(string + (j - 1)))
            swap(string + j, string + (j - 1));
      }
   }
}

void sortArr2(char *string)
{
   /* ----------------------------- SELECTION SORT -----------------------------*/
   int i, j, smollest;

   for (i = 0; i < strlen(string) - 1; i++)
   {
      smollest = i;
      for (j = i + 1; j < strlen(string); j++)
      {
         if (*(string + smollest) > *(string + j))
            smollest = j;
      }
      swap(string + i, string + smollest);
   }
}

void swap(char *x, char *y)
{
   char temp = *x;
   *x = *y;
   *y = temp;
}