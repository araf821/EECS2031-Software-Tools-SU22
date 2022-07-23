/***************************************
* 22SU - Lab01 *
* Author: Alam, Araf A *
* Email: araf821@my.yorku.ca *
* eecs_username: araf821 *
* York Student #: 218124347
****************************************/

#include <stdio.h>

float sum(float, float);
void greet(int);

int main()
{  
   int a = 2031;
   greet(a);
   int b = 1012;
   greet(b);
   float x = 2.2, y = 3.3;
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
