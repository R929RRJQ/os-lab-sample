#include<stdio.h>
#include<unistd.h>

void main()
{
  printf("Process ID = %d\n",getpid());
  printf("parent process ID = %d\n",getppid());
}
