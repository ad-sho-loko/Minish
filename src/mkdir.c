#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int do_mkdir(char** args){
  for(char** arg = args+1; *arg; arg++){
    mkdir(*arg, 0x777);
  }
  return 0;
}

void usage(){
}

int main(int argc, char** args){
  if(argc < 2){
    usage();
    exit(1);
  }

  do_mkdir(args);
}
