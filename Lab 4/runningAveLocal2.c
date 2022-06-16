/***************************************
 * 22S - Lab4 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>

/* Global Variables */
int count = 0, sum = 0;

void r_avg(int);

int main(int argc, char *argv[])
{
	
   int input;  
   printf("Enter number (-1 to quit): ");
   scanf("%d", &input);

   while (input != -1){
        r_avg(input);

        printf("\nEnter number (-1 to quit): ");
        scanf("%d", &input);
    }
	
    return 0;
}

void r_avg(int input)
{
    sum += input;
    count++;
    double resu = (double) sum / count;
    printf("running average is %d / %d = %.3lf\n", sum, count, resu);
}
