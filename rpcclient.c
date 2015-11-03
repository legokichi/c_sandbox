#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>

#define HOST "127.0.0.1"

enum {
  PROG=0x20000000L,
  VERS=1L,
  PROC_NUM=1L
};

int main(void){
  double in, out;
  in = 0.3;
#if defined(rpc_call)
  if (rpc_call(HOST, PROG, VERS, PROC_NUM, xdxdr_double, &in, xdr_double, &out, NULL)!=0){
#else
  if (callrpc(HOST, PROG, VERS, PROC_NUM, xdr_double, &in, xdr_double, &out)!=0){
#endif
    printf("RPC call error!\n");
    exit(EOF);
  }
  printf("out=%f\n", out);
  return 0;
}
