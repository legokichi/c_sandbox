#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mpi.h"
#define DIVIDE 10000000


int main(int argc, char **argv){
  clock_t start, stop;
  double a, b;
  printf("a: ");printf("%f\n", a=0);
  printf("b: ");printf("%f\n", b=M_PI);
  start = clock();
  double step = (b-a)/DIVIDE;
  double allsum = 0;
  int size, rank;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  double begin = (b-a)/size*rank+a;
  double end = (b-a)/size*(rank+1)+a;
  double step = (b-a)/DIVIDE;
  double sum = 0;
  for(double i=begin; i<=end; i+=step){
    double a = sin(i);
    double b = sin(i+step);
    double h = step;
    double S = (a+b)*h/2;
    sum += S;
  }
  MPI_Reduce(&sum, &allsum, 1, MPI_DOUBLE_PRECISION, MPI_SUM, 0, MPI_COMM_WORLD, &status);
  MPI_Finalize(&status);
  stop = clock();
  printf("result: %f\n", allsum);
  printf("%f[sec]\n", (double)(stop - start)/CLOCKS_PER_SEC);
  return 0;
}

/*
$ mpicc -o hoge hoge.c
$ mpirun -np 4 hoge
*/
