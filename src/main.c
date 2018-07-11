#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

#define BUF_SIZE 256
#define MAX_COMMAND_NUM 64
#define TOKEN_DELIM " \t\r\n\a"

int launch_command(char** commands);

char* buildin_commands[] = {
  "help"
  "exit"
};

int (*buildin_func[])(char** args) = {
  &cmd_help,
  &cmd_exit
};

// read stdin, return string until `\n`.
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

    // TODO: realloc
    if(size >= 256){
      fprintf(stderr, "Minish cannot accept more than 256 chars");
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
    commands[tkn_pos++] = token;
    token = strtok(NULL, TOKEN_DELIM);
  }

  commands[tkn_pos] = NULL;
  return commands;  
}

int exec_commands(char** commands){
  if(commands[0] == NULL){
    return 1;
  }

  // execute buildin commands if exists.
  if(strcmp(commands[0], "help") == 0){
    return cmd_help();
  }
  
  if(strcmp(commands[0], "exit") == 0){
    return cmd_exit();
  }

  // not buildin command, so execute fork, wait.
  return launch_command(commands);
}

int launch_command(char** commands){
  pid_t pid, wpid;
  int status;

  pid = fork();

  if(pid == 0){
    // child process
    if(execvp(commands[0], commands) == -1){
      fprintf(stderr, "Minish : no such a command. \n");
    }
  } else {
    // parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}


int cmd_help(char** args){
  printf("Minish ver 0.0.1\n");
  return 0;
}

int cmd_exit(char** args){
  exit(0);
}

int main(void){
  char buf[50];

  while(1){
    printf(">");
    char* line = read_line();
    char** commands = split_line(line);
    exec_commands(commands);
    free(line);
    free(commands);
  }
  
  return 0;
}
