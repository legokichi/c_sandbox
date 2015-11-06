#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
enum {
  PROG=0x20000000L,
  VERS=1L,
  PROC_NUM=1L
};
char *func();

int main(void){
#if defined(rpc_reg)
  if(rpc_reg(PROG, VERS, PROC_NUM, func, xdr_double, xdr_double, NULL)!=0){
#else
  if(registerrpc(PROG, VERS, PROC_NUM, func, xdr_double, xdr_double)!=0){
#endif
    printf("RPC register error!\n");
    exit(EOF);
  }
  svc_run();
  exit(EOF);
}

char *func(double *in){
  static double out;
  out = 3.8*(*in)*(1-(*in));
  return((char *)&out);
}
