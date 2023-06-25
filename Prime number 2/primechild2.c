 /* Child program to print fibonacci numbers using shmget and shmat system calls.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>

int main(int argc, char *argv[]) {
    int i, m, n, flag=0;
    void *shmptr;
    int shmid = shmget((key_t)1122, 4096, 0666);
    shmptr = shmat(shmid, NULL, 0666);

    printf("\nChild Printing:\n");
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    for(i=m; i<=n; i++) {
        for(int j=2; j<=n/2; j++) {
            if(i%j == 0) {
                flag = 1;
            }     
        }

        if(flag == 0) {
        sprintf(shmptr, "%d ", i);
        printf("%d ", i);
        shmptr += strlen(shmptr);
        }

        flag = 0;
    }

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
