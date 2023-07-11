/*program to implement the cat command which prints the content of the file*/


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    if (argc < 2) {
        printf("\nThe file name is not passed\n");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("\nThe file does not exist.\n");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}