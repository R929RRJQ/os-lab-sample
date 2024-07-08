#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

void main()
{
  pid_t pid = fork();
  if(pid == 0)
  {
    printf("Child process\n");
  }
  else if(pid > 0)
  {
    printf("parent process\n");
    wait(NULL);
    printf("Child terminated\n");
  }
  else
  {
    perror("fork");
  }
}
