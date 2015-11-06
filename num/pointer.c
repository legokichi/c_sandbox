#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(void){
  char x = 0b10101010;
  char y = 1;
  char * _x;
  _x = & x;
  printf("\nobject value:\n");
  printX(x);
  printf("\naddress:\n");
  printX(_x);
  printf("\nreference:\n");
  printX(* _x);
  return 0;
}
