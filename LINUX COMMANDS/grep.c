
 /* Program to stimulate the grep command of linux operating system. itfinds the required pattern in the given file, 
 and prints the lines with the pattern to console.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {
    char file_name[25], pattern[10], temp[200];
    FILE *fp;
    printf("\nEnter the file name:\n");
    scanf("%s", file_name);
    printf("\nEnter the pattern:\n");
    scanf("%s", pattern);
    fp = fopen(file_name, "r");
    while (!feof(fp)) {
        fgets(temp, 100, fp);
        if(strstr(temp, pattern))
            printf("%s", temp);
    }
    fclose(fp);
}