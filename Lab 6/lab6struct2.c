#include <stdio.h>
#include <stdlib.h>

struct ints
{
  int data1;
  int data2;
};

/* functions that take a struct as argument */
int getSum(struct ints);
int getSum2(struct ints *);

void processStruc(struct ints *);

/* function that returns a structure */
struct ints getSumDiff(int, int);

main()
{

  struct ints a = {100, 4};
  printf("-------- structs and functions -----------------\n");
  /* function that takes structures as argument(s) */ 
  printf("elements sum of a: %d\n", getSum(a));

  /* function that takes structure pointer as argument(s) */
  printf("elements sum of a: %d\n\n", getSum2(&a));

  /* print a's members */
  printf("struct a before process: %d %d\n", a.data1, a.data2);
  processStruc(&a);
  /* ptint a's members again */
  printf("struct a after  process: %d %d\n\n", a.data1, a.data2);

  /* functions that return a struct, encapsulating multiple values */
  /**********************************  */
  int num1, num2;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);
  struct ints s = getSumDiff(num1, num2);
  int sum = s.data1;  /*  get sum via s */
  int diff = s.data2; /*  get diff via s */
  printf("sum is: %d, diff is %d\n", sum, diff);

  /********************************** */

  printf("--------- array of structs ----------------\n");
  struct ints structArr[3] = {{1, 2}, {3, 4}};
  /* set the 3rd element structures's int1 and int2 to be 5 and 6 */
  structArr[2].data1 = 5;
  structArr[2].data2 = 6;

  int i;
  for (i = 0; i < 3; i++)
  {
    printf("arr[%d]: %d %d\n", i, structArr[i].data1, structArr[i].data2);
  }

  /***********malloc/calloc for structure*********************** */
  printf("--------- pointer to structs with malloc() ----------------\n");
  struct ints *p = malloc(sizeof(struct ints));
  (*p).data1 = 777; /* via p, store data1 with value 777 */
  (*p).data2 = 888; /* via p, store data2 with value 888 */
  printf("two member values: %d %d\n", (*p).data1, p->data2);

  /**********************************/
  printf("--------- array of pointers to structs, with malloc() --------\n");
  struct ints *structArrP[3]; /* array of 3 (uninitilized) pointers */
  structArrP[0] = malloc(sizeof(struct ints));
  structArrP[1] = malloc(sizeof(struct ints));

  /* set the first element to point to a struct of element 22,33 */
  (*structArrP[0]).data1 = 22;
  structArrP[0]->data2 = 33;

  /* set 2nd element to point to a struct of element 44,55, another way */
  struct ints tmp = {44, 55};
  *structArrP[1] = tmp; /* copy from a structure */

  for (i = 0; i < 2; i++)
  {
    printf("pArr[%d] -*-> {%d, %d}\n", i, structArrP[i]->data1, structArrP[i]->data2);
  }
}

/* call/pass by value  */
int getSum(struct ints s)
{
  return s.data1 + s.data2;
}

/* call/pass by pointer  */
int getSum2(struct ints *s)
{
  return s->data1 + s->data2;
}

/* call by value  */
void processStruc(struct ints *x)
{
  x->data1++;
  x->data2 += 100;
}

struct ints getSumDiff(int a, int b)
{
  struct ints s;
  s.data1 = a + b;
  s.data2 = a - b;

  return s;
}
