/***************************************
 * 22S - Lab4 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <string.h>

#define SIZES 30

void my_strcat(char *, char *);

int main()
{
   char a[SIZES];
   char b[SIZES];
   char c[SIZES];
   char d[SIZES];

   scanf("%s", a);
   scanf("%s", b);

   /* Loop as long as either a is not "xxx" or be is not "xxx"
      Stop if both are "xxx" */
   while (strcmp(a, "xxx") != 0 || strcmp(b, "xxx") != 0)
   {
      strcpy(c, a);
      strcpy(d, b);

      strcat(a, b);
      my_strcat(c, d);

      printf("strcat:   %s\n", a);
      printf("mystrcat: %s\n\n", c);

      scanf("%s", a);
      scanf("%s", b);
   }
}

/* your own version of implmentation goes here */
void my_strcat(char a[], char b[])
{
   int aSize = strlen(a);
   int i = 0;

   /**
    * We add each char from b until we find a null value.
    */ 
   i = 0;
   while (b[i] != '\0') {
      a[aSize + i] = b[i];
      i++;
   }
   /* This is a line we must add to declare the end of the string.
   Otherwise, our function would behave the same way strncat does. */
   a[aSize + i] = '\0';
}
