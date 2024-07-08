#include<stdio.h>
#include<dirent.h>

void main()
{
  
  struct dirent *entry;
  DIR *dir = opendir(".");
  
  if(dir == NULL)
  {
    printf("Could not open the directory\n");
    return;
  }
  
  while((entry=readdir(dir))!=NULL)
  {
    printf("%s\n",entry->d_name);
  }
}
