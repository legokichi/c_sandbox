#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DIVIDE 10000000
#include "mpi.h"

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
  MPI_Status status;
  MPI_Init(&argc, &argv);
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  long range = DIVIDE/size;
  double _sum = 0;
  for(long i=range*rank; i<=range*(rank+1); i++){
    double a = sin(step*rank);
    double b = sin(step*(rank+1));
    double h = step;
    double S = (a+b)*h/2;
  }
  MPI_Reduce(&_sum, &sum, 1, MPI_DOUBLE_PRECISION, MPI_SUM, 0, MPI_COMM_WORLD, &status);
  end = clock();
  printf("result: %f\n", sum);
  printf("%f[sec]\n", (double)(end - start)/CLOCKS_PER_SEC);
  return 0;
}
