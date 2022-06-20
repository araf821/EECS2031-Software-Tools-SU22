#include <stdio.h>

#define AlphaVal 100

#define SIZE 32

int main()
{

  int r, g, b, i;
  unsigned int rgb_pack;
  int r_unpack, g_unpack, b_unpack;
  int alpha = AlphaVal;

  printf("enter R value (0~255): ");
  scanf("%d", &r);
  printf("enter G value (0~255): ");
  scanf("%d", &g);
  printf("enter B value (0~255): ");
  scanf("%d", &b);

  while (!(r < 0 || g < 0 || b < 0))
  {
    printf("A: %d\t", alpha);
    printBinary(alpha);
    printf("\n");
    printf("R: %d\t", r);
    printBinary(r);
    printf("\n");
    printf("G: %d\t", g);
    printBinary(g);
    printf("\n");
    printf("B: %d\t", b);
    printBinary(b);
    printf("\n");

    /* ---------------------------- PACKING ---------------------------------- */

    /*
      Take each value and assign it to the packing variable.
      Shift them to the left as needed.
    */
    alpha = AlphaVal << 24;
    r_unpack = r << 16;
    g_unpack = g << 8;
    b_unpack = b;

    rgb_pack = r_unpack + g_unpack + b_unpack + alpha;

    printf("\nPacked:\t");
    printBinary(rgb_pack);
    printf(" (%d)\n", rgb_pack);

    printf("\nUnpacking  ......\n");

    /* ---------------------------- UNPACKING ---------------------------------- */

    /*
      Shift the required values to the right as needed.
    */
    r_unpack = r_unpack >> 16;
    g_unpack = g_unpack >> 8;

    printf("R: ");
    printBinary(r_unpack);
    printf(" (%d, %#o, %#X)\n", r_unpack, r_unpack, r_unpack);
    printf("G: ");
    printBinary(g_unpack);
    printf(" (%d, %#o, %#X)\n", g_unpack, g_unpack, g_unpack);
    printf("B: ");
    printBinary(b_unpack);
    printf(" (%d, %#o, %#X)\n", b_unpack, b_unpack, b_unpack);
    printf("------------------------------------\n");

    printf("enter R value (0~255): ");
    scanf("%d", &r);
    printf("enter G value (0~255): ");
    scanf("%d", &g);
    printf("enter B value (0~255): ");
    scanf("%d", &b);
  }
}
