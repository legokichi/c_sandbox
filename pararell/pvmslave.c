#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "pvm3.h"
int main(int argc, char *argv[]){
  int me, parent, msgtype;
  int n;
  double work, result=0.0;
  double xs[10000];
  double ys[10000][10000];
  parent = pvm_parent();
  msgtype=11;
  pvm_recv(parent, msgtype);
  pvm_upkint(&n, 1, 1);
  pvm_upkdouble(&xs, 10000, 1);
  pvm_upkdouble(&ys, 10000, 1);
  me = pvm_mytid();
  for(int j=n/4; j<(n+1)/4; j++){
    for(int i=0; i<10000; i++){
      result += xs[i]*ys[j][i];
    }
  }
  msgtype=22;
  pvm_initsend(PvmDataDefault);
  pvm_pkdouble(&result, 1, 1);
  pvm_send(parent, msgtype);
  pvm_exit();
  return 0;
}
