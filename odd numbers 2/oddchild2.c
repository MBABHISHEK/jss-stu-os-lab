/* Child program to print n odd numbers using shmget and shmat system calls.*/

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
    int i = 1, n;
    void *shmptr;
    int shmid = shmget((key_t)1122, 4096, 0666);
    shmptr = shmat(shmid, NULL, 0666);

    printf("\nChild Printing:\n");
    n = atoi(argv[1]);

    while(n != 0) {
        if(i%2 != 0) {
            sprintf(shmptr, "%d ", i);
            printf("%d ", i);
            shmptr += strlen(shmptr);
            n--;
        }
        i++;
    }

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}