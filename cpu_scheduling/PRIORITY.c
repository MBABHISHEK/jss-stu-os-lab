/*program to implement the priority scheduling algorithm */
#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT, isCompl, priority; 
} pro;

pro p[15];

void main() {
    int n, total_WT=0, total_TAT=0;
    float avg_WT=0, avg_TAT=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time, burst time and priority of the process:\n");
    printf("AT BT P\n");
    for(int i=0; i<n; i++) {
        p[i].Id = (i+1);
        scanf("%d%d%d", &p[i].AT, &p[i].BT, &p[i].priority);
        p[i].isCompl = 0;
    }

    int minIndex, minPriority, completed = 0, curTime = 0;

    printf("\nGantt Chart:\n\n");
    while(completed != n) {
        minIndex = -1;
        minPriority = 9999;
        for(int i=0; i<n; i++) {
            if(p[i].AT <= curTime && p[i].isCompl == 0) {
                if(p[i].priority < minPriority || (p[i].priority == minPriority && p[i].AT < p[minIndex].AT)) {
                    minPriority = p[i].priority;
                    minIndex = i;
                }
            }
        }

        if(minIndex == -1) {
            curTime++; //If no process which is not completed is present at the current time increment it.
        } else {
            //As the process is not preempted, the process executes till it is completed, i.e., for it's full BT.
            curTime += p[minIndex].BT;
            p[minIndex].CT = curTime;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
            total_TAT += p[minIndex].TAT;
            total_WT += p[minIndex].WT;
            p[minIndex].isCompl = 1;
            completed++;
            printf("| P%d (%d) %d", p[minIndex].Id, p[minIndex].BT, p[minIndex].CT);
        }

    }
    printf("|\n");
    avg_TAT = (float)total_TAT/n;
    avg_WT = (float)total_WT/n;

    //Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tP\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].priority);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);

}
