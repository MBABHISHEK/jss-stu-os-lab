

/*program to implement using shmopen and mmap this is parent creating child and distributing wrok to child*/
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
    int i, k, n1, n2, n3;
    const int SIZE = 4096;
    pid_t pid;
    int shm_fd;
    void *shmptr;

    if (argc > 1) {
        sscanf(argv[1], "%d", &i);
        if(i<1) {
            printf("\nWrong input given!!\n");
            return 0;
        }
    } else {
        printf("\nN is not passed in the command line!!\n");
        exit(0);
    }

    pid = fork();
    if(pid == 0) {
        //This is the child part
        execlp("./fib", "fib", argv[1], NULL);
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