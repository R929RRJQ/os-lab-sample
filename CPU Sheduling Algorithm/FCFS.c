#include<stdio.h>
void main()
{
  int n,i;
  float averageWaitingTime, averageTurnaroundTime;
  
  printf("Enter number of process: ");
  scanf("%d",&n);
  
  int burstTime[n], waitingTime[n], turnaroundTime[n];
  
  printf("Enter burst time for each process\n");
  for(i=0; i<n; i++)
  {
    printf("P[%d]:",i);
    scanf("%d",&burstTime[i]);
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
    printf("%d\t\t%d\t\t%d\t\t%d\n",i,burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
  
  //Printing Averages
  printf("Average Waiting Time = %f\n", averageWaitingTime/(float)n);
  printf("Average Turnaround Time = %f\n", averageTurnaroundTime/(float)n);
}
