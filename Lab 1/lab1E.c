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
   
   /* Looping based on the number of times the user wants to loop the program */
   int i, num;
   printf("Enter the number of interactions: ");
   scanf("%d", &num);
   float x, y;
   for (i = 0; i < num; i++)
   {
   	printf("Enter two float numbers separated by ##: ");
   	scanf("%f##%f", &x, &y);
	float su = sum(x, y);
	printf( "%.3f + %.3f = %f (%.2f)\n", x, y, su, su);
   }

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
