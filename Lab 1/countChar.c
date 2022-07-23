/***************************************
* 22SU - Lab01 *
* Author: Alam, Araf A *
* Email: araf821@my.yorku.ca *
* eecs_username: araf821 *
* York Student #: 218124347
****************************************/

#include <stdio.h> /* define EOF */

int main(){
  int c;
  int count = 0;
 
  c = getchar();
  while(c != EOF) /* no end of file*/
  { 
    count++; /* include spaces and '\n' */

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n",count);

}

