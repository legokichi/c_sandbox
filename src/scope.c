#include <stdio.h>

int z;

void f_nc(int i){
  static int x=0;
  int y=0;
  x=x+1;
  y=y+1;
  z=z+1;
  i=i+1;
  printf("x=%d,y=%d,z=%d,i=%d\n",x,y,z,i);
}


void sc_pe(){
  int i;
  z=0;
  for(i=0;i<5;i++) f_nc(i);
}
