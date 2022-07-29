#include <stdio.h>
#include <string.h>

main()
{

  /********** recap of pointer basics first **********************/
  int a = 10;
  int *p = &a;
  printf("%d\n\n", *p); 

  int arrI[] = {70, 30, 50};
  int *ptrI = arrI;

  /* different ways to access arrI[0] */ 
  printf("%d %d %d\n", arrI[0], *ptrI, *arrI); /* pointee level */

  /* different ways to access arrI[1] */
  printf("%d %d %d\n", arrI[1], *(ptrI + 1), *(arrI + 1)); /* pointee level */

  /* different ways to access arrI[2] */
  printf("%d %d %d\n\n", arrI[2], *(ptrI + 2), *(arrI + 2)); /* pointee level */

  /**************************/
  char arr[] = "hello";
  char *ptr = arr; /* = &arr[0] */

  /* different ways to pass the array to printf, at "pointer" level, not *arr, *ptr */
  printf("%s %s %s\n", &arr[0], arr, ptr); /* pointer level */
  printf("%ld %ld %ld\n", strlen(&arr[0]), strlen(arr), strlen(ptr));

  /* passing sub-string */
  printf("%s %s %s\n", &arr[2], arr + 2, ptr + 2); /* pointer level */
  printf("%ld %ld %ld\n\n", strlen(&arr[2]), strlen(arr + 2), strlen(ptr + 2));

  /* different ways to access arr[0] */
  printf("%c %c %c\n", arr[0], *ptr, *arr); /* pointee level */

  /* different ways to access arr[1] */
  printf("%c %c %c\n", arr[1], *(ptr + 1), *(arr + 1)); /* pointee level */

  /* different ways to access arr[4] */
  printf("%c %c %c\n\n", arr[4], *(ptr + 4), *(arr + 4)); /* pointee level */

  /*********** array of poniters to int ***************************/
  int i = 1;
  int j = 3;
  int k;
  int n;
  int *arrP[3]; /* declare array of 3 (uninitilized) int pointers */

  /* different ways to initialize the pointers */
  int *pi = &i;
  arrP[0] = pi;
  arrP[1] = &j;
  arrP[2] = &k;

  /* set value of variable k to be 5 via its pointer in the array  arrP */
  **(arrP + 2) = 5;

  /* print pointees of element pointers maintained in array arrP, using both array notation and pointer notation */
  for (n = 0; n < 3; n++)                      /* print elements ; should output 1 1, 3 3, 5 5 */
    printf("%d %d\n", *arrP[n], **(arrP + n)); /* pointee level */

  /************ /***** array of char pointers, each pointer points to an char array ***********/
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};

  /* print the pointee of the very 1st element pointer of planets (i.e., string "Mercury"), */
  /* using both array index notation i.e., planets[i] and pointer notation, */
  printf("\n%s %s %ld %ld\n", planets[0], *(planets + 0), strlen(planets[0]), strlen(*planets));

  /* print the pointee of the 2nd element pointer (i.e., string "Venus"), using both array index notation and pointer notation, */
  printf("\n%s %s %ld %ld\n", planets[1], *(planets + 1), strlen(planets[1]), strlen(*(planets + 1)));

  /* print the pointee of the 5th element pointer (i.e., string "Jupiter"), using both array index notation and pointer notation, */
  printf("\n%s %s %ld %ld\n", planets[4], *(planets + 4), strlen(planets[4]), strlen(*(planets + 4)));

  /* print the pointee of the 6th element pointer (i.e., string "Saturn"), using both array index notation and pointer notation, */
  printf("\n%s %s %ld %ld\n", planets[5], *(planets + 5), strlen(planets[5]), strlen(*(planets + 5)));

  /* print the pointee of the 8th element pointer (i.e., string "Neptune"), using both array index notation and pointer notation, */
  printf("\n%s %s %ld %ld\n", planets[7], *(planets + 7), strlen(planets[7]), strlen(*(planets + 7)));

  /***** print the substring of pointee of the 5th element pointer (i.e., string "iter"), using both array index notation and pointer notation (already done for you) */
  printf("\n%s  %s\n\n", planets[4] + 3, *(planets + 4) + 3);

  /*********finally, access characters in the pointee array *************************/
  /* Access characters in pointee array, using pointer notation */
  printf("%c\n", *(planets[0] + 0));   /* print M   or simiply *planets[0] */
  printf("%c\n", *(planets[4] + 3));   /* print i */
  printf("%c\n", *planets[6]);         /* print U */
  printf("%c\n\n", *(planets[8] + 4)); /* print o */

  /* pure pointer notation, for those of you who love Pointer to Pointer :-) */
  printf("%c\n", **planets);             /* *( *(planets+0) +0)  //  print M */
  printf("%c\n", *(*(planets + 4) + 3)); /* print i */
  printf("%c\n", *(*(planets + 6) + 0)); /* print U */
  printf("%c\n", *(*(planets + 8) + 4)); /* print o */
}
