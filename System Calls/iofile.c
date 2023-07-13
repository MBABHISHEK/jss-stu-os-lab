#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 25

void main(){
	int fd, n;
	char buffer[BUFFER_SIZE];
	
	fd = open("a.txt",O_RDWR);
	
	if (fd<0){
		printf("Failed to open file\n");
		exit(0);
	}
	
	printf("Reading first 10 characters from file\n");
	n = read(fd, buffer, 10);
	write(1,buffer, n);
	printf("\n");
	
	printf("Skipping 5 characters from current position in the file\n");
	lseek(fd, 5, SEEK_CUR);
	n = read(fd,buffer,10);
	write(1,buffer,n);
	printf("\n");
	
	printf("Going to 5th last character in the file\n");
	lseek(fd,-6,SEEK_END);
	n = read(fd,buffer,5);
	write(1,buffer,n);
	printf("\n");
	
	printf("Going to the 3rd character in the file\n");
	lseek(fd, 3, SEEK_SET);
	n = read(fd,buffer,10);
	write(1,buffer,n);
	printf("\n");
}
