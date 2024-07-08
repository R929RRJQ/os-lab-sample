#include <stdio.h>

void main() {
    int pno, bno;

    // Block
    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    int bsizes[bno];
    printf("Enter block sizes:\n");
    for(int i = 0; i < bno; i++) {
        scanf("%d", &bsizes[i]);
    }

    // Process
    printf("Enter number of processes: ");
    scanf("%d", &pno);

    int psizes[pno];
    printf("Enter process sizes:\n");
    for(int i = 0; i < pno; i++) {
        scanf("%d", &psizes[i]);
    }

    // Initialize
    int allocation[pno];
    int flag[bno];
    int fragment[pno];

    for(int i = 0; i < bno; i++) {
        flag[i] = 0;
    }

    for(int i = 0; i < pno; i++) {
        allocation[i] = -1;
    }

    // Allocation
    int i,j;
    for(i = 0; i < pno; i++) {
        int worstIdx = -1;
        for(j = 0; j < bno; j++) {
            if(flag[j] == 0 && bsizes[j] >= psizes[i]) {
                if(worstIdx == -1 || bsizes[j] > bsizes[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if(worstIdx != -1) {
            fragment[j] = psizes[i] - bsizes[worstIdx];
            printf("%d",fragment[j]);
            allocation[i] = worstIdx;
            flag[worstIdx] = 1;
        }
    }

    // Printing
    printf("Process no.\tProcess size\tBlock no.\tBlock size \tFragment\n");
    for(int i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i, psizes[i]);
        if(allocation[i] != -1) {
            printf("%d\t\t%d \t%d\n", allocation[i], bsizes[allocation[i]], fragment[i]);
        } else {
            printf("Not allocated\n");
        }
    }
}

