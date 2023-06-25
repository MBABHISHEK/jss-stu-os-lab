/* Parent program to print n odd numbers using shm_open and mmap system calls.*/
 

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
    int n, i;
    pid_t pid;
    void *shmptr;
    int shmid;

    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
        if(n<1) {
            printf("\nWrong input given!!\n");
            return 0;
        }
    } else {
        printf("\nN is not passed in the command line!!\n");
        exit(0);
    }

    pid = fork();
    if(pid == 0) {
        //This is the child process
        execlp("./odd", "odd", argv[1], NULL);
    } else if(pid > 0) {
        wait(NULL);
        printf("\n[PARENT] Child process completed\n");
        shmid = shm_open("OS", O_RDONLY, 0666);
        ftruncate(shmid, 4096);
        shmptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shmid, 0);
        printf("\nParent Printing:\n");
        printf("%s\n", (char *)shmptr);
        shm_unlink("OS");
    }

    return 0;
}
