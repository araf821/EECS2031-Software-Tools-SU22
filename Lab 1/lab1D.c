#include <stdio.h>

float sum(float, float);
void greet(int);

int main()
{  
   int a = 2031;
   greet(a);
   int b = 1012;
   greet(b);
   float x, y;
   printf("Enter two float numbers separated by ##: ");
   scanf("%f##%f", &x, &y);
   float su = sum(x, y);
   printf( "%f + %f = %f\n", x, y, su);

   return 0;

}

/* function definition */
float sum (float i, float j){
   return i + j;             
}

/* modify this function */
void greet(int i){
  printf("Hello %d!\n", i);
}
