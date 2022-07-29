/***************************************
 * 22S - Lab06 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <stdlib.h>

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
    /* The function calloc() allocates the specified amount of memory,
    that is 4 bytes in our case since we are storing an int value. */
    arr[index] = calloc(1, sizeof(int));
    *(arr[index]) = vv;
}
