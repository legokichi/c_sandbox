#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DIVIDE 10000000

int main(int argc, char **argv){
  clock_t start, end;
  double a, b;
  printf("a: ");printf("%f\n", a=0);
  //scanf("%lf", &a);
  printf("b: ");printf("%f\n", b=M_PI);
  //scanf("%lf", &b);
  start = clock();
  double step = (b-a)/DIVIDE;
  double sum = 0;
  for(long i=0; i<=DIVIDE-1; i++){
    double a = sin(step*i);
    double b = sin(step*(i+1));
    double h = step;
    double S = (a+b)*h/2;
    sum += S;
  }
  end = clock();
  printf("result: %f\n", sum);
  printf("%f[sec]\n", (double)(end - start)/CLOCKS_PER_SEC);
  return 0;
}
