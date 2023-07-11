/* Program to stimulate the ls command of Linux operating system.IT  lists all the files present in the given directory.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

void main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    if(argc < 2) {
        printf("\nThe directory name is not being passed.\n");
        exit(1);
    }

    if((dp = opendir(argv[1])) == NULL) {
        printf("\nDirectory does not exist, and therefore cannot be opened.\n");
        exit(1);
    }

    while((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}
