/***************************************
 * 22S – Lab2 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ****************************************/

#include <stdio.h>
#define MAX_SIZE 5

int length(char[]);
int indexOf(char[], char);
int occurrence(char[], char);
void displayStr(char[]);
int isQuit(char[]);

main()
{

   char word[MAX_SIZE];
   char c;

   char helloArr[] = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0';
   helloArr[3] = 'X';
   helloArr[7] = 'Y';
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));

   /********** Fill in your code here. **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);

   while (1)
   {
      /* don't change the first two lines */
      printf("Input word is \"");
      displayStr(word);
      printf("\"\nContains %d characters\n", length(word));
      printf("'%c' appears %d times in the word\n", c, occurrence(word, c));
      printf("Index of '%c' in the word is %d\n", c, indexOf(word, c));
      printf("\nEnter a word and a character separated by blank: ");
      scanf("%s %c", word, &c);
      if (isQuit(word))
      {
         break;
      }
   }
}

int length(char arr[])
{
   int i = 0;
   while (arr[i] != '\0')
   {
      i++;
   }
   return i;
}

int indexOf(char arr[], char c)
{
   int i = 0;
   while (arr[i] != '\0')
   {
      if (c == arr[i])
      {
         return i;
      }
      i++;
   }
   return -1;
}

int occurrence(char arr[], char c)
{
   int i = 0;
   int counter = 0;
   while (arr[i] != '\0')
   {
      if (c == arr[i])
      {
         counter++;
      }
      i++;
   }
   return counter;
}

void displayStr(char arr[])
{
   int i = 0;
   while (arr[i] != '\0')
   {
      putchar(arr[i]);
      i++;
   }
}

int isQuit(char arr[])
{
   int i;

   for (i = 0; i < length(arr); i++)
   {
      if (arr[i] == 'q')
      {
         if (arr[i + 1] == 'u')
         {
            if (arr[i + 2] == 'i')
            {
               if (arr[i + 3] == 't')
               {
                  return 1;
               }
            }
         }
      }
   }

   return 0;
}
