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

  bit();
  pointer();
  file();
  function();
  st_rct();
  s_zeof();
}
