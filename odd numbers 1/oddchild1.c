
 /*Child program to print n odd numbers using shm_open and mmap system calls.*/
 
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
    int n, i=1;
    void *shmptr;
    int shmid = shm_open("OS", O_CREAT|O_RDWR, 0666);
    ftruncate(shmid, 4096);
    shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmid, 0);
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

    return 0;
}