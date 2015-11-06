#include <stdio.h>
#include <math.h>
#include <main.h>

void printBin(char n){
  for(int i=7;i>=0;i--)
    printf( n &  (int)pow(2, (double)i) ? "1": "0");
}

void printX(char x){
  printf("signed int char: %d\n", x);
  printf("unsigned int char: %u\n", x);
  printf("unsigned octet char: %o\n", x);
  printf("unsigned Hex char: %x\n", x);
  printf("bit:"); printBin(x); printf("\n");
}
