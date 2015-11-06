#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pvm3.h"
enum { MAXNODES=32, };
char *CLIENTNAME="pvm_client";
int main(int argc, char *argv[]){
  int mytid, tids[MAXNODES];
  int numt, n, nproc, msgtype;
  double val, work, result;
  double xs[10000];
  double ys[10000][10000];
  for(int i=0; i<10000; i++){
    xs[i] = rand();
    for(int j=0; i<10000; j++){
      ys[i][j] = rand();
    }
  }
  mytid = pvm_mytid();
  nproc=4;
  numt = pvm_spawn(CLIENTNAME, NULL, PvmTaskDefault, NULL, nproc, tids);
  if (numt != nproc){
    fprintf(stderr, "numt = %d, nproc = %d\n", numt, nproc);
    fprintf(stderr, "error: pvm_spawn()\n");
    pvm_exit();
    exit(1);
  }
  msgtype=11;
  for(n=0; n<nproc; n++){
    pvm_initsend(PvmDataDefault);
    pvm_pkint(&n, 1, 1);
    pvm_pkdouble(&xs, 10000, 1);
    pvm_pkdouble(&ys, 10000, 1);
    pvm_send(tids[n], msgtype);
  }
  msgtype=22; result=0.0;
  for(n=0; n<nproc; n++){
    pvm_recv(-1, msgtype);
    pvm_upkdouble(&work, 1, 1);
    result += work;
  }
  printf("Result = %25.15lf\n", result);
  return 0;
}
