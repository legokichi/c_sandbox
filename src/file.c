/*
ref
  http://www9.plala.or.jp/sgwr-t/c/sec17.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#define READ_FILE_CHAR_NUM 256

void f_le(void){
  FILE *fp;
  //FILE *fopen(const char *filename, const char *mode)
  if ((fp = fopen("test.txt", "r")) == NULL) {
    printf("file open error!!\n");
    exit(EXIT_FAILURE);
  }
  char s[READ_FILE_CHAR_NUM];
  //malloc()
  //char *fgets(char *s, int n, FILE *stream);
  while (fgets(s, READ_FILE_CHAR_NUM, fp) != NULL) {
    printf("%s", s);
  }
  fclose(fp);
}
