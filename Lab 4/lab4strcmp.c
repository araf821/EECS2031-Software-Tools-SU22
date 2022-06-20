#include <stdio.h>
#include <string.h>

#define SIZES 30

int my_strcmp(char *, char *);

int main()
{
   char a[SIZES];
   char b[SIZES];

   scanf("%s", a);
   scanf("%s", b);

   /* Loop as long as either a is not "xxx" or b is not "xxx"
      Stop if both are "xxx" */
   while ((strcmp(a, "xxx") != 0) || (strcmp(b, "xxx") != 0))
   {

      int resu = strcmp(a, b);
      if (resu < 0)
         printf("strcmp:   \"%s\" appears earlier in dictionary than \"%s\"\n", a, b);
      else if (resu > 0)
         printf("strcmp:   \"%s\" appears later in dictionary than \"%s\"\n", a, b);
      else
         printf("\"%s\" and \"%s\" are same\n", a, b);

      int resu2 = my_strcmp(a, b);
      if (resu2 < 0)
         printf("mystrcmp: \"%s\" appears earlier in dictionary than \"%s\"\n\n", a, b);
      else if (resu > 0)
         printf("mystrcmp: \"%s\" appears later in dictionary than \"%s\"\n\n", a, b);
      else
         printf("\"%s\" and \"%s\" are same\n\n", a, b);

      scanf("%s", a);
      scanf("%s", b);
   }
}

int my_strcmp(char a[], char b[])
{

   /* Get the length of arrays a and b. */
   int lengthA = strlen(a);
   int lengthB = strlen(b);

   /* -------------------- Implementation -------------------------*/
   int i = 0;
   while (i < lengthA && i < lengthB)
   {
      if (a[i] < b[i]) /* (a[i] is lesser) */
         return a[i] - b[i]; /* Returns a negative number */
      else if (a[i] > b[i]) /* (a[i] is greater) */
         return a[i] - b[i]; /* Returns a positive number */
      else
         /* Increment the counter and keep looping till we run out of
         values in either array */
         i++;
   }
   /* If the above loop concludes with no return statements,
   it means that the strings are the same. */
   return 0; 
}
