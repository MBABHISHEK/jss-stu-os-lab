/*Program to stimulate the rm command of the linux operating system.is used for deleting a file present in the current directory.*/


#include<stdio.h>
void main() {
    char file_name[25];
    printf("\nEnter the source file\n");
    scanf("%s", file_name);
    if(remove(file_name) == 0)
        printf("\nFile successfully removed\n");
    else
        printf("\nFile cannot be removed\n");
}