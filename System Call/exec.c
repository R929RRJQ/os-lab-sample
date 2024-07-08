#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
  char *args[] = {"./stat", NULL};
  execvp(args[0],args);
  printf("Failed to run");
}
