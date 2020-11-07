#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//builtin commands:
int sh_help(char **args);
int sh_exit(char **args);

char *builtin_str[] =
{
  "help",
  "exit"
};

int (*builtin_func[]) (char **) =
{
  &sh_help,
  &sh_exit
};

int sh_num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}

//builtin command implementations.

//shell's "manual"
int sh_help(char **args)
{
  int i;
  printf("karapnaran's shell\n");
  printf("type commands with arguments, and hit enter.\n");
  printf("the following commands are built in:\n");
  for (i = 0; i < sh_num_builtins(); i++)
     printf("  %s\n", builtin_str[i]);
  return 1;
}

//returns 0 to terminate the program
int sh_exit(char **args)
{
  return 0;
}

/////////////////////////////////////////////////////
//launches a program and waits for it to terminate,
//returns 1 so that shell keeps running
int sh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    //child process
    if (execvp(args[0], args) == -1)
    {
      perror("sh");
    }
    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    //error forking
    perror("sh");
  }
  else
  {
    //parent process
    do
    {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

//executes commands, returns 1 if the shell should continue running, 0 if it should stop
int sh_execute(char **args)
{
  int i;

  if (args[0] == NULL)
  {
    //an empty command was entered.
    return 1;
  }

  //check if the entered command is builtin
  for (i = 0; i < sh_num_builtins(); i++)
  {
    if (strcmp(args[0], builtin_str[i]) == 0)
    {
      return (*builtin_func[i])(args);
    }
  }

  return sh_launch(args);
}

//reads a line
char *sh_read_line(void)
{
  int bufsize = 1024;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer)
  {
    fprintf(stderr, "sh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  while (1)
  {
    //read a character
    c = getchar();
    //c is EOF or \n, replaces it with a null character and returns.
    if (c == EOF || c == '\n')
    {
      buffer[position] = '\0';
      return buffer;
    } else
    {
      buffer[position] = c;
    }
    position++;
    //reallocate buffer
    if (position >= bufsize)
    {
      bufsize += 1024;
      buffer = realloc(buffer, bufsize);
      if (!buffer)
      {
        fprintf(stderr, "sh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

//splits a line into tokens
char **sh_split_line(char *line)
{
  int bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens)
  {
    fprintf(stderr, "sh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " \t\r\n\a");
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens)
      {
        fprintf(stderr, "sh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[position] = NULL;
  return tokens;
}

int main(int argc, char **argv)
{
  char *line;
  char **args;
  int status;

  // loop getting input and executing it.
  do {
    printf("> ");
    line = sh_read_line();
    args = sh_split_line(line);
    status = sh_execute(args);
    free(line);
    free(args);
  } while (status);

  return EXIT_SUCCESS;
}
