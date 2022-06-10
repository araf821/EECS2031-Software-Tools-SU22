import java.util.Scanner;

class  Binary
{
    public static void main(String[] args) 
   {
       // four ways to denote an integer number in Java 
       int a = 13;   // decimal
       int b = 0b001101;  // binary
       int c = 0XD;   // hex
       int d = 015;   // oct
       System.out.printf("13's binary rep:\t%s\n", getBinaryRep(a));
       System.out.printf("0b001101's binary rep:\t%s\n", getBinaryRep(b));
       System.out.printf("0XD's binary rep:\t%s\n", getBinaryRep(c));
       System.out.printf("015's binary rep:\t%s\n\n", getBinaryRep(d));
	
       a = 36;   // decimal
       b = 0b100100;  // binary
       c = 0X24;   // hex
       d = 044;   // oct
       System.out.printf("36's binary rep:\t%s\n", getBinaryRep(a));
       System.out.printf("0b100100's binary rep:\t%s\n", getBinaryRep(b));
       System.out.printf("0X24's binary rep:\t%s\n", getBinaryRep(c));
       System.out.printf("044's binary rep:\t%s\n\n", getBinaryRep(d));



       Scanner scan = new Scanner (System.in);
       int data;
       System.out.print("Enter an integer in decimal (-10000 to exit): ");

       while ( (data = scan.nextInt()) != -10000)
       {  
          String s2 = getBinaryRep(data);
          System.out.println(s2);
          System.out.printf("Decimal: %d \t Oct: %#o \t Hex: %#x %#X\n", data, data,data, data);

          // read again
          System.out.printf("\nEnter an integer in decimal (-10000 to exit): "); 

       }

     }

     public static String getBinaryRep(int d){
          String binaryS = Integer.toBinaryString(d);
          String s = String.format("%32s", binaryS).replace(' ', '0'); // padding 0s to the left
          // add space every byte for readability
          String s2 = String.format("%s %s %s %s", s.substring(0,8), s.substring(8,16),s.substring(16,24),s.substring(24));
          return s2;
     }
}
