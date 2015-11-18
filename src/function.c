#include <stdio.h>
#include <main.h>

void _log(char elm[], char index){
  printf("%d, %s\n", index, elm);
}


void forEach(void (*lambda)(char elm[], char index), char argc, char *argv[]){
  for(int i=0; i<argc; i++){
    (*lambda)(argv[i], i);
  }
}

void f_nction(){
  char **str = {
    &"hello\0",
    &"world\0",
    NULL
  };
  //forEach(&_log, 2, &str);
}
