#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* CURRENT_DIR = "./";

int ls(){
  DIR *d;
  if((d = opendir(CURRENT_DIR)) == NULL) {
    fprintf(stderr, "cannot open current directory.");
    exit(EXIT_FAILURE);
  }
  
  struct dirent* dirent;
  while((dirent = readdir(d))) {
    /*if(strcmp(dirent->d_name, "")) {
      continue;
    }*/
    printf("%s ", dirent->d_name);
  }
  printf("\n");
  
  closedir(d);
  return 0; 
}

int main(int argc, char** argv) {
  ls();
  return 0;
}
