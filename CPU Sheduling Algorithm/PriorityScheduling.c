#include<stdio.h>
void main()
{
  int n,i,j,temp;
  float averageWaitingTime, averageTurnaroundTime;
  
  printf("Enter number of process: ");
  scanf("%d",&n);
  
  int processId[n], burstTime[n], waitingTime[n], turnaroundTime[n], priority[n];
  
  printf("Enter burst time and priority\n");
  for(i=0; i<n; i++)
  {
    processId[i] = i+1;
    printf("\nP[%d]:\n",i+1);
    
    printf("Burst Time:");
    scanf("%d",&burstTime[i]);
    
    printf("Priority:");
    scanf("%d",&priority[i]);
  }
  
  //Sorting
  for(i=0; i<n-1; i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(priority[j] > priority[j+1])
      {
        temp = priority[j+1];
        priority[j+1] = priority[j];
        priority[j] = temp;
        
        temp = processId[j+1];
        processId[j+1] = processId[j];
        processId[j] = temp;
        
        temp = burstTime[j+1];
        burstTime[j+1] = burstTime[j];
        burstTime[j] = temp;
      }
    }
  }
  //Waiting time
  waitingTime[0] = 0;
  for(i=1; i<n; i++)
  {
    waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    averageWaitingTime += waitingTime[i];
  }
  
  //Turnaround time
  for(i=0; i<n; i++)
  {
    turnaroundTime[i] = burstTime[i] + waitingTime[i];
    averageTurnaroundTime += turnaroundTime[i];
  }
  
  //Printing Table
  printf("Process\t\tBurst Time\tWaiting Time\tTurnaround time\n");
  for(i=0; i<n; i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\n", processId[i] ,burstTime[i] ,waitingTime[i] ,turnaroundTime[i]);
  }
  
  //Printing Averages
  printf("Average Waiting Time = %f\n", averageWaitingTime/(float)n);
  printf("Average Turnaround Time = %f\n", averageTurnaroundTime/(float)n);
}
