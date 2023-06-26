/*****************************************************************************************************************
  Program to demonstrate the Round Robin cpu scheduling algorithm.
*****************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT, flag; 
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

void main() {
    int n, tempBT[15], total_WT=0, total_TAT=0, quantum;
    float avg_WT=0, avg_TAT=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for(int i=0; i<n; i++) {
        p[i].Id = (i+1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        tempBT[i] = p[i].BT;
        p[i].flag = 0;
    }
    printf("\nEnter the time quantum:\n");
    scanf("%d", &quantum);
    sort(n);

    //A queue is required for demonstrating this algorithm
    int completed = 0, curIndex, curTime = p[0].AT, *waitQueue, front = 0, rear = 0, cnt=0;
    waitQueue = (int *)malloc(n*sizeof(int));
    cnt++;
    waitQueue[rear] = 0;
    p[0].flag = 1;

    while (completed != n) {
        curIndex = waitQueue[front];
        front = (front+1) % n;
        if(p[curIndex].BT > quantum) {
            p[curIndex].BT -= quantum;
            curTime += quantum;
            printf("| P%d(%d) %d", p[curIndex].Id, quantum, curTime);
        } else {
            curTime += p[curIndex].BT;
            printf("| P%d(%d) %d", p[curIndex].Id, p[curIndex].BT, curTime);
            p[curIndex].BT = 0;
        }
        p[curIndex].CT = curTime;
        cnt--;

        for(int i=0; i<n && p[i].AT <= curTime; i++) {
            if(i == curIndex || p[i].flag == 1 || p[i].BT == 0) 
                continue;
            rear = (rear+1) % n;
            p[i].flag = 1;
            waitQueue[rear] = i;
            cnt++;
        }

        if(p[curIndex].BT > 0) {
            rear = (rear+1)%n;
            waitQueue[rear] = curIndex;
            cnt++;
        } else {
            completed++;
        }

    }
    for(int i=0; i<n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        total_TAT += p[i].TAT;
        p[i].WT = p[i].TAT - tempBT[p[i].Id-1];
        total_WT += p[i].WT;
    }
    avg_TAT = (float)total_TAT/n;
    avg_WT = (float)total_WT/n;

    //Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, tempBT[i], p[i].CT, p[i].TAT, p[i].WT);
    }

    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
