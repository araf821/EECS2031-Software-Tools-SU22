/***************************************
 * 22S - Lab06 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>

void setArr(int, int);

int *arr[10];

int main(int argc, char *argv[])
{
     int i;

     setArr(0, -10);
     setArr(1, 100);
     setArr(2, 200);
     setArr(3, 300);
     setArr(4, 400);

     for (i = 0; i < 5; i++)
          printf("arr[%d] -*-> %d %d\n", i, *arr[i], **(arr + i)); /* should be -10,100, 200,300,400 */

     return 0;
}

/* set arr[index], which is a pointer, to point to an integer of value vv */
void setArr(int index, int vv)
{
     int i = vv;
     arr[index] = &vv;
}

/*
     Compiling this code leaves us with the same value for every element
     in the array. That value is 400 and as you can see, 400 is the last
     value we tried to add to the array. 

     The problem here is that in the setArr function, we are setting the
     value of arr[index] to the address of the local variable i over and
     over again. No matter what the value of the i is set to each time
     the function is called, variable i points to the same memory address
     and thus, all the pointers pointing at that address get their value
     set to whatever the value residing in that address currently is.

*/