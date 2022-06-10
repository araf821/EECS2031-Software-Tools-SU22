#include<stdio.h>

#define SIZE 32

int main(){
    int data; 
    int b = 0Xd;
    int c = 015;

    printf("int is of %d bytes on your system\n", sizeof (int));
    printf("int is of %d bytes on your system\n", sizeof (b) );
    printf("int is of %d bytes on your system\n\n", sizeof c);
    
    printf("Decimal of 0Xd: %d\n", b);
    printf("Decimal of 015: %d\n\n", c);

    b = 0X24;
    c = 044;
    printf("Decimal of 0X24: %d\n", b);
    printf("Decimal of 044: %d\n\n", c);


    while(1){ // while true inifinte loop
	printf("Enter an integer in decimal (-10000 to exit): ");
        scanf("%d", &data);

	if (data == -10000)
	{
	    break;
	}
	
        printf("Decimal: %d \t Oct: %#o \t Hex: %#x %#X\n", data, data, data, data);   /* # is used to add 0 and 0X  */
		
        printf("\n");
	
     }
     return 0;
}

