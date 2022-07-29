/***************************************
 * 22S - Lab06 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>

void setArr(int, int);

int *arr[10]; /* array of 10 int pointers. Global variable */

int main(int argc, char *argv[])
{
     int i;

     setArr(0, -10);
     setArr(1, 100);
     setArr(2, 200);
     setArr(3, 300);
     setArr(4, 400);

     for (i = 0; i < 5; i++)
          printf("arr[%d] -*-> %d %d\n", i, *arr[i], **(arr + i)); /* should be -10, 100, 200, 300, 400 */

     return 0;
}

/* set arr[index], which is a pointer, to point to an integer of value vv */
void setArr(int index, int vv)
{
     int i = vv;
     *arr[index] = i;
}

/*
     Compiling this program results in a Segmentation fault (core dump).

     This is because a local variable's lifetime ends whenever the 
     function exists. In our case, there are 3 local variables in 
     the function setArr(). As soon as their lifetime has ended,
     the memory gets deallocated, i.e. the memory allocated in
     *arr[index] is freed up, resulting in a segmentation fault.
*/
