#include <stdio.h>

int main(int argc, char** argv){

  for(char **p = argv + 1; *p; p++){
    printf("%s ", *p);
  }
  
  printf("\n");
  return 0;
}
