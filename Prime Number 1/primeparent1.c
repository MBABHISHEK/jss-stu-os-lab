/* Parent program to print prime numbers in given range using shm_open and mmap system calls.*/

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
    int i, m, n;
    int flag=0;
    const int SIZE = 4096;
    pid_t pid;
    int shm_fd;
    void *shmptr;

    if (argc > 2) {
        sscanf(argv[1], "%d", &m);
        sscanf(argv[2], "%d", &n);
        if(m<1 || n<1) {
            printf("\nWrong input given!!\n");
            return 0;
        } else if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
    } else {
        printf("\nNo or wrong number of parameters passed in the command line!!\n");
        exit(0);
    }

    pid = fork();
    if(pid == 0) {
        //This is the child part
        execlp("./prime", "prime", argv[1], argv[2], NULL);
    } else if (pid > 0) {
        wait(NULL);
        printf("\n[PARENT] Child process completed\n");
        shm_fd = shm_open("OS", O_RDONLY, 0666);
        shmptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("\nParent printing:\n");
        printf("%s\n", (char *)shmptr);
        shm_unlink("OS");
    }

    return 0;
}
