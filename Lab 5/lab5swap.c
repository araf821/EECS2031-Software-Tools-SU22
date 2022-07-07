/***************************************
 * 22S - Lab05 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347 *
 ************************************** **/

#include <stdio.h>

void swapIncres(int*, int*, int*);

int main()
{
   int a, b, c;

   /* Read in three integers */
   scanf("%d %d %d", &a, &b, &c);
   while (a != -1)
   {
      printf("Original inputs:   a:%-4d  b:%-4d  c:%-4d\n", a, b, c);
      swapIncres(&a, &b, &c);
      printf("Rearranged inputs: a:%-4d  b:%-4d  c:%-4d\n\n", a, b, c);

      /* read again */
      scanf("%d %d %d", &a, &b, &c);
   }
}

// swaps and also increments a,b,c
void swapIncres(int *x, int *y, int *z)
{
   int temp = *x;
   *x = *z;
   *z = temp;

   *x += 100;
   *y *= 2;
}
