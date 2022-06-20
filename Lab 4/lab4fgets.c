#include <stdio.h>
#include <string.h>

#define SIZES 10
#define SIZES2 40

int main(int argc, char *argv[])
{
  char resu[SIZES2];
  char input[SIZES2];
  char name[SIZES];
  int age = 0;
  float rate;

  printf("Enter name, age and rate (or \"exit\"): ");
  fgets(input, 40, stdin);
  while (strcmp(input, "exit\n") != 0)
  {
    printf("%s", input);
    fputs(input, stdout);

    /* Step 1: Seperate the info we got from the user into different variables. */
    sscanf(input, "%s %d %f", name, &age, &rate);

    /*------------- Step 2: Modify the values ---------------*/
    if (name[0] >= 'a' && name[0] <= 'z')
      name[0] = name[0] - 32; /* Capitalize the first letter. */
    age += 10;                /* Add 10 to the age */
    rate *= 2;                /* Increase the rate by 100% */

    /*
      Floor and ceil values without using floor() and ceil() functions.
      This works almost 100% of the time. For this lab, it'll do just fine.
      Otherwise, the functions are better to use.
    */
    int flr = (int)rate;          /* Rate rounded down (floor) */
    int cl = (int)(rate + 0.999); /* Rate rounded up (ceil) */

    /* Step 3: Add everything to char along with the modified values. */
    sprintf(resu, "%s-%d-%.3f-[%d, %d]", name, age, rate, flr, cl);
    /* ----------- Display the new string -----------*/
    printf("%s\n\n", resu);

    /* now use fgets() to read inputs again */
    printf("Enter name, age and rate (or \"exit\"): ");
    fgets(input, 40, stdin);
  }

  return 0;
}
