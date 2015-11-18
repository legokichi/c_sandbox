#include <stdio.h>
#include <stdlib.h>
#include <main.h>

void b_t(){
  char z = 0b11111110;
  printf("signed int char: %d\n", z);
  printf("unsigned int char: %u\n", z);
  printf("unsigned octet char: %o\n", z);
  printf("unsigned Hex char: %x\n", z);
  printf("bit:"); printBin(z); printf("\n");

  char x = 123,
       y = 0;
  y = x & 0xf0;
  // 123  = 0b01111011
  printf("x\t%d", x); printf("\t"); printBin(x); printf("\n");
  // 0xf0 = 0b11110000
  printf("0xf0\t%d", 0xf0); printf("\t"); printBin(0xf0); printf("\n");
  // y = 112 = 0b01110000
  printf("y\t%d", y); printf("\t"); printBin(y); printf("\n");
}
