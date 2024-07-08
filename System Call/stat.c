#include <stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

void main()
{
  char path[100];
  
  struct stat *nfile = malloc(sizeof(struct stat));
  
  printf("Enter file name: ");
  scanf("%s",path);
  
  stat(path, nfile);
  printf("user id = %d\n",nfile->st_uid);
  printf("block size = %ld bytes\n",nfile->st_blksize);
  printf("last access time = %ld\n",nfile->st_atime);
  printf("last modified time = %ld\n",nfile->st_mtime);
  printf("file size = %ld bytes\n",nfile->st_size);
  printf("number of links = %ld\n",nfile->st_nlink);
}

