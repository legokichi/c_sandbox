#include <stdio.h>
#include <stdlib.h>

void s_zeof(){
  char a = 0;
  int b = 0;
  short int c = 0;
  long int d = 0;
  unsigned short int e = 0;
  unsigned long int f = 0;
  printf("char, %lu\n", sizeof(a));
  printf("int, %lu\n", sizeof(b));
  printf("short int, %lu\n", sizeof(c));
  printf("unsigned short int, %lu\n", sizeof(e));
  printf("unsigned long int, %lu\n", sizeof(f));
  printf("hello world, %lu\n", sizeof("hello world"));
  // h e l l o   w o r l d \0
}
