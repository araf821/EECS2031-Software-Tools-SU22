/***************************************
 * 22S - Lab4 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/
#include <stdio.h>

/* define global variables and a function */
int sum = 0, count = 0;

void r_avg(void)
{
    double result = (double) sum / count;
    printf("running average is %d / %d = %.3lf\n", sum, count, result);
}
