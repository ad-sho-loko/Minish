#define BUF_SIZE 256
#define MAX_COMMAND_NUM 64
#define TOKEN_DELIM " \t\r\n\a"

bool is_line_end(char ch);
int cmd_help();
int cmd_exit();
