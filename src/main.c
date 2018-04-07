#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 256
#define MAX_COMMAND_NUM 64
#define TOKEN_DELIM " \t\r\n\a"

// bool is_line_end(char ch);

char* buildin_commands[] = {
  "help"
  "exit"
};

int (*buildin_func[])(char**) = {
};

char* read_line(){
  char* buf;
  buf = malloc(sizeof(char) * BUF_SIZE);

  if(!buf){
    fprintf(stderr, "Allocation Failed.\n");
    exit(EXIT_FAILURE);
  }

  int size = 0;
  while(1){
    char ch = getchar();
    
    // if
    if(ch == EOF || ch == '\n'){
      buf[size] = '\0';
      return buf;
    }
    
    buf[size++] = ch;

    // if 
    if(size >= 256){
      fprintf(stderr, "Minish cannot accept ");
      exit(EXIT_FAILURE);
    }
  }
  
  return buf;
}

char** split_line(char* line){
  char** commands = malloc(sizeof(char) * BUF_SIZE * MAX_COMMAND_NUM);
  int tkn_pos = 0;

  char* token = strtok(line, TOKEN_DELIM);

  while(token != NULL){
    puts(token);
    commands[tkn_pos++] = token;
    token = strtok(NULL, TOKEN_DELIM);
  }

  commands[tkn_pos] = NULL;
  return commands;  
}

void exec_commands(char** commands){
  if(commands[0] == NULL){
    return;
  }
  
  char* cmd = commands[0];

  //char** args = 
  if(strcmp(cmd, "echo")){
    
  }
}


void echo(char** args){
  
}

int main(void){
  char buf[50];

  while(1){
    printf(">");
    char* line = read_line();
    char** commands = split_line(line);
    // printf("%s", line);
    // printf("%s\n", commands[0]);
  }
  
  
  return 0;
}
