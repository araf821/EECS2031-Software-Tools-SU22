/***************************************
 * 22S - Lab03 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * Yorku Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <stdlib.h> /* for atoi */
#include <string.h>

#define SIZE 10

int isQuit(char[]);
int pawar(int, int);
int my_atoi(char[], int);

int main()
{
  int base, b;
  char arr[SIZE];

  printf("Enter a word of positive number and a base, or 'quit': ");
  scanf("%s %d", arr, &base);

  while (!isQuit(arr))
  {
    printf("%s\n", arr);

    b = my_atoi(arr, base);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n\n", b, b, b, b * 2, b * b);

    printf("Enter a word of positive number and a base, or 'quit': ");
    scanf("%s %d", arr, &base);
  }

  return 0;
}

int my_atoi(char c[], int base)
{
  int result = 0;
  int i, exp = 0;

  for (i = strlen(c) - 1; i >= 0; i--)
  {
    result += (c[i] - 48) * pawar(base, exp);
    exp++;
  }

  return result;
}

int pawar(int base, int exp)
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

int isQuit(char arr[])
{
  char str[] = "quit";
  int result = strcmp(str, arr);
  if (result == 0)
  {
    return 1;
  }
  return 0;
}
