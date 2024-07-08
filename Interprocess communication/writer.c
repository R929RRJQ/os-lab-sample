#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/shm.h>
#include <string.h>

#define SHM_KEY 2000
#define SHM_SIZE 1024

void main()
{
  void *shared_memory;
  char word[SHM_SIZE];
  
  int shm_id = shmget((key_t)SHM_KEY,SHM_SIZE,IPC_CREAT | 0666);
  shared_memory = shmat(shm_id,NULL,0);
  
  printf("Shared memory key: %d\n",SHM_KEY);
  printf("Process attached at %p\n",shared_memory);
  
  printf("Enter string:");
  gets(word);
  
  
  strcpy(shared_memory,word);
  
  printf("You wrote %s\n",(char *)shared_memory);
}
