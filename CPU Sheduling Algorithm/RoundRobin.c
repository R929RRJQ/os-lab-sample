#include <stdio.h>

void main() {
    // Initialize variables
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    // Input total number of processes
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of processes to variable y

    // Input arrival and burst time for each process
    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Store the burst time in temp array
    }

    // Input the Time Quantum for the processes
    printf("Enter the Time Quantum for the processes: ");
    scanf("%d", &quant);

    // Display the process No, burst time, Turn Around Time, and the waiting time
    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time ");

    // Process the scheduling
    sum = 0;
    i = 0;
    while(y != 0) {
        if (temp[i] <= quant && temp[i] > 0) 
        { // Check if process can finish in this quantum
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } 
        else if (temp[i] > 0) 
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1) 
        {
            y--; // Decrement the number of processes left
            printf("\nProcess No[%d] \t\t %d \t\t\t %d \t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1) 
        {
            i = 0;
        } 
        else if (at[i + 1] <= sum) 
        {
            i++;
        }
        else 
        {
            i = 0;
        }
    }

    // Calculate and display average waiting time and Turn Around Time
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\nAverage Turn Around Time: \t%f", avg_wt);
    printf("\nAverage Waiting Time: \t%f", avg_tat);
}

