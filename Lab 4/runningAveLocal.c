#include <stdio.h>

void r_avg(int, int);

int main(int argc, char *argv[])
{

   int input;
   int count = 0;
   int sum = 0;

   printf("Enter number (-1 to quit):  ");
   scanf("%d", &input);

   /* Terminate the program if the input is -1 */
   while (input != -1)
   {
      /* Increment count every time the calculations run */
      count++;
      /* Add the new input to the value of sum */
      sum += input;

      r_avg(sum, count);

      printf("Enter number (-1 to quit):  ");
      scanf("%d", &input);
   }

   return 0;
}

void r_avg(int sum, int count)
{
   /* Either sum or count need to be converted into float or double or else
   we will always get a rounded down number for the result */
   /* double result = (double) sum / count; */
   printf("running average is %d / %d = %.3lf\n\n", sum, count, (double)sum / count);
}
