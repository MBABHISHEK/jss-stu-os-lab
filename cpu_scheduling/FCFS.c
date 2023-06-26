
/* Program to demonstrate the first come first serve cpu scheduling algorithm.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT; 
} pro;

pro p[15];

void swap(pro *a, pro *b) {
    pro temp = *a;
    *a = *b;
    *b = temp;
    return; 
}

void sort(int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].AT > p[j+1].AT) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}



void printGanttChart(int n) {
    for(int i=0; i<n; i++) {
        if(p[i].AT > p[i-1].CT) {
            printf("| Idle (%d) %d", p[i].AT - p[i-1].CT, p[i].AT);
        }

        printf("|P%d (%d) %d", p[i].Id, p[i].BT, p[i].CT);
    }
    printf("|\n");
}

void main() {
    int n, total_WT=0, total_TAT=0;
    float avg_WT=0, avg_TAT=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    for(int i=0; i<n; i++) {
        p[i].Id = (i+1);
          printf("AT:\n"); 
          scanf("%d", &p[i].AT); 
          printf("BT:\n");
          scanf("%d", &p[i].BT);
    }

    sort(n);

    //Finding the completion time of all the processes
    p[0].WT = 0;
    p[0].CT = p[0].AT + p[0].BT;
    for(int i=1; i<n; i++) {
        if(p[i].AT > p[i-1].CT) {
            p[i].CT = p[i-1].CT + (p[i].AT - p[i-1].CT) + p[i].BT;
            continue;
        } 
        p[i].CT = p[i-1].CT + p[i].BT;
    }

    //Finding the turnaround time and waiting time of all the processes
    for(int i=0; i<n; i++) {
        if(p[i].AT > p[i-1].CT) {
            p[i].TAT = p[i].CT - p[i].AT;
            total_TAT += p[i].TAT;
            p[i].WT = 0;
            continue;
        }
        p[i].TAT = p[i].CT - p[i].AT;
        total_TAT += p[i].TAT;
        p[i].WT = p[i].TAT - p[i].BT;
        total_WT += p[i].WT;
    }
    avg_TAT = (float)total_TAT/n;
    avg_WT = (float)total_WT/n;

    //Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
    printf("\nGantt Chart:\n\n");
    printGanttChart(n);
}