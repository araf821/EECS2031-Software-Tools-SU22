#include <stdio.h>

int main()
{

    int age = 10;
    int age2 = 100;

    /* Make pointer1 point to age1. */
    int *ptr = &age;

    printf("age: %d %d\n", age, *ptr);

    /* Use pointer1 to change the value of age1 to 14. */
    *ptr = 14; /* or *ptr += 4; */

    printf("age: %d %d\n", age, *ptr);

    /* Make pointer2 point to age 2. */
    int *ptr2 = &age2;

    /* Assign the value of age2 to triple the value of age1 using pointer2 */
    *ptr2 = *ptr * 3;

    printf("age2: %d %d\n", age2, *ptr2);

    /* Let pointer2 point to age1 also. */
    ptr2 = ptr;

    printf("ptr2's current pointee: %d\n", *ptr2);

    printf("age: %d %d %d\n", age, *ptr, *ptr2);

    /* Use pointer2 to decrease the value of age1 by 1. */
    *ptr2 = *ptr2 - 1;

    printf("age: %d %d %d\n", age, *ptr, *ptr2);

    /* Display the address of age along with pointer1 and pointer2. They should all be the same. */
    printf("%p %p %p\n", &age, ptr, ptr2);

    return 0;
}
