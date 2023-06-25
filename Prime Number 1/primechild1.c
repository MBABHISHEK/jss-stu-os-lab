
 /* Child program to print prime numbers in given range using shm_open and mmap system calls.*/
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
    int flag = 0;
    void *shmptr;
    int shm_fd = shm_open("OS", O_CREAT|O_RDWR, 0666);
    ftruncate(shm_fd, 4096);
    shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    printf("\nChild Printing:\n");
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    for(i=m; i<=n; i++) {
        for(int j=2; j<=i/2; j++) {
            if(i%j == 0){
                flag = 1;
            }
        }
        
        if(flag == 0) {
            sprintf(shmptr, "%d ", i);
            printf("%d ", i);
            shmptr += strlen(shmptr);
        }

        flag=0;
    }

    return 0;
}