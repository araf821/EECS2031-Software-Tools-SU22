#include <stdio.h>
#include <string.h>

#define SIZE 36

int isPalindrome(char *);
int isPalindromeR(char *);
int helper(char *, int, int);
void printReverse(char *);

int main()
{
   int result;
   char c;
   int i;
   int count = 0;
   char arr[SIZE];

   fgets(arr, SIZE, stdin);
   while (strcmp(arr, "quit\n") != 0)
   {
      arr[strlen(arr) - 1] = 0;

      // print backward
      printReverse(arr);

      if (isPalindromeR(arr))
         printf("\nIs a palindrome.\n\n");
      else
         printf("\nNot a palindrome.\n\n");

      fgets(arr, SIZE, stdin);
   }
   return 0;
}

// assume char \n has already been removed manually
int isPalindrome(char *str)
{
   int i = 0;               /* Index 0 */
   int j = strlen(str) - 1; /* Last Index */

   /*
      Solution:
         We compare the first and the last index, if it does not
         match, we set pal to false and break the loop. After
         every comparison, i is incremented and j is decremented.
   */
   for (i = 0; i < strlen(str); i++)
   {
      if (*(str + i) != *(str + j))
         return 0; /* Return false(0) */
      j--;
   }

   return 1; /* Return true(1) */
}

// int isPalindromeR(char *str)
// {
//    int end = strlen(str) - 1;

//    /* If the value at current index doesn't equal to the
//    value at the last index, return false(0) */
//    if (*(str) != *(str + end))
//       return 0;

//    /* Set end index to null */
//    *(str + end) = 0;
//    isPalindromeR(str + 1); /* The start index is incremented */
// }

/* Bonus Questions */
int isPalindromeR(char *str)
{
   int start = 0;
   int end = strlen(str) - 1;
   return helper(str, start, end);
}

int helper(char *string, int start, int end)
{
   if (start == end)
      return 1; /* if start index = end index, return true(1) */
   else if (start > end)
      return 1; /* if start index is greater than end index, return true(1) */
   else if (*(string + start) != *(string + end))
      return 0; /* False(0) if the values at the indexes being compared do not match */

   /* Recall the helper function by incrementing the start index and decrementing the end index. */
   helper(string, start + 1, end - 1);
}

/* assume char \n has already been removed manually */
void printReverse(char *str)
{
   int i;

   /*
      Solution:
         Just print the contents of the array starting from its last index.
   */
   for (i = strlen(str) - 1; i >= 0; i--)
      printf("%c", *(str + i));
}
