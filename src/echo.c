#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_line_feed = 1;

static void usage(){

  fprintf(stderr,
          "Usage: minish-echo <args>"
          "\n"
          "-e No Line Feed");

  exit(EXIT_FAILURE);
}

int parse_arg(int argc, char** argv){
  int opt, opt_cnt = 0;
  opterr = 0;
  
  while((opt = getopt(argc, argv, "e:")) != -1){
    switch(opt){
      case 'n':
        opt_cnt++;
        is_line_feed = 0;
        break;
      case 'b':
        opt_cnt++;
        break;
      default:
        usage();
        break;
    }
  }
  return opt_cnt;
}

int main(int argc, char** argv){

  int opt_cnt = parse_arg(argc, argv);
  
  for(char **p = argv + 1 + opt_cnt; *p; p++){
    printf("%s ", *p);
  }

  if(is_line_feed){
    printf("\n");
  }
  
  return 0;
}
