/***************************************
 * 22S - Lab4 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/
#include <stdio.h>

/* Extern is used to include global variables from other c files */
extern int count, sum;

int main(int argc, char *argv[])
{
  int input;

  printf("Enter number (-1 to quit): ");
  scanf("%d", &input);

  while (input != -1)
  {
    count++;
    sum += input;
    r_avg();

    printf("\nEnter number (-1 to quit): ");
    scanf("%d", &input);
  }

  return 0;
}
