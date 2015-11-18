#include <stdio.h>
#include <main.h>

//int main(int argc, char *argv[]);
// argv = [&"a.out\0", &"test.txt\0", "\0"]
int main(int argc, char **argv){
  printf("[%s", *argv);
  for(int i=1; i<argc; i++){
    printf(", %s", *(argv+i));
  }
  printf("]\n");

  printf("hello world.\n");
  printf("# scope\n");
  sc_pe();
  printf("# bit\n");
  b_t();
  printf("# pointer\n");
  p_inter();
  printf("# file\n");
  f_le();
  printf("# thread\n");
  thr_ad();
  printf("# struct\n");
  str_ct();
  printf("# sizeof\n");
  s_zeof();
  printf("# function\n");
  f_nction();
}
