/* Parent program to print fibonacci numbers using shmget and shmat system calls.*/
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>

int main(int argc, char *argv[]) {
    int i, m, n, flag = 0;
    pid_t pid;
    const int SIZE = 4096;
    void *shmptr;
    int shmid = shmget((key_t)1122, 4096, 0666|IPC_CREAT);
    shmptr = shmat(shmid, NULL, 0666);

    if(argc > 2) {
        sscanf(argv[1], "%d", &m);
        sscanf(argv[2], "%d", &n);
        if(m < 1 || n < 1) {
            printf("\nWrong input is passed:\n");
            return 0;
        } else if (m > n) {
                int temp = m;
                m = n;
                n = temp;
        }
    } else {
        printf("\nWrong number of parameters passed in the command line\n");
        return 1;
    }

    pid = fork();
    if(pid == 0) {
        //This is the child process part
        execlp("./prime", "prime", argv[1], argv[2], NULL);
    } else if(pid > 0) {
        wait(NULL);
        printf("\n[PARENT] Child completed\n");
        printf("\nParent printing:\n");
        printf("%s\n", (char *)shmptr);
        shmdt(shmptr); 
    } 

    return 0;
}
