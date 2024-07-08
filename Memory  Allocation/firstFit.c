#include<stdio.h>

void main()
{
  int pno,bno;
  
  //block
  printf("Enter number of blocks:");
  scanf("%d",&bno);
  
  int bsizes[bno];
  printf("Enter block sizes:\n");
  for(int i=0; i<bno; i++)
  {
    scanf("%d",&bsizes[i]);
  }
  
  //process
  printf("Enter number of process:");
  scanf("%d",&pno);
  
  int psizes[pno];
  printf("Enter process sizes:\n");
  for(int i=0; i<pno; i++)
  {
    scanf("%d",&psizes[i]);
  }
  
  //initialise
  int allocation[bno];
  int flag[bno];
  
  for(int i=0; i<bno; i++)
  {
    flag[i] = 0;
    allocation[i] = -1;
  }
  
  //allocation
  for(int i=0; i<pno; i++)
  {
    for(int j=0; j<bno; j++)
    {
      if(flag[j] == 0 && bsizes[j] >= psizes[i])
      {
        allocation[j] = i;
        flag[j] = 1;
        break;
      }
    }
  }
  
  //printing
  printf("Block no.\tBlock size \tProcess no. \tProcess size\n");
  for(int i=0; i<bno; i++)
  {
    printf("%d \t%d \t",i,bsizes[i]);
    if(flag[i] == 1)
    {
      printf("%d \t%d\n",allocation[i],psizes[allocation[i]]);
    }
    else
    {
      printf("Not allocated\n");
    }
  }
  
  
}
