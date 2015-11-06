#include <stdio.h>
#include <stdlib.h>
#define READ_FILE_CHAR_NUM 256

int main(void){
  FILE *fp;
  //FILE *fopen(const char *filename, const char *mode)
  if ((fp = fopen("test.txt", "r")) == NULL) {
    printf("file open error!!\n");
    exit(EXIT_FAILURE);
  }
  char s[READ_FILE_CHAR_NUM];
  //char *fgets(char *s, int n, FILE *stream);
  while (fgets(s, READ_FILE_CHAR_NUM, fp) != NULL) {
    printf("%s", s);
  }
  fclose(fp);
  return 0;
}
