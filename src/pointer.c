#include <stdio.h>
#include <main.h>

void pointer(){
  char x = 0b10101010;
  char y = 1;
  char * _x;
  _x = & x;
  printf("\nobject value:\n");
  printX(x);
  printf("\naddress:\n");
  printX((char)_x);
  printf("\nreference:\n");
  printX(* _x);
}
