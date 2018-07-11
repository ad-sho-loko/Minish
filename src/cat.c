#include <stdio.h>
#include <stdlib.h>

static int cat(FILE* fp){
  char buf[4096];

  fread(buf, sizeof(buf), 10, fp);
  printf("%s", buf);

  return 0;
}

int main(int argc, char** argv){

  FILE *fp;

  for(char** p = argv+1; *p ; p++){
    if((fp = fopen(*p, "r")) == NULL){
      fprintf(stderr, "Cannot read %s", *p);
      exit(EXIT_FAILURE);
    }
    cat(fp);
  }
  return 0;
}
