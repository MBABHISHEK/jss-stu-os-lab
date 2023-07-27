# jss-stu-os-lab
This repository contains the programs for the operating system lab cycle

1
a) Write a shell program to check whether a given number is palindrome
or not
b) Implement SJF Pre-emptive scheduling algorithm by defining process
structure.


2 a) Write a shell program to generate prime numbers in a given range
b) Implement Priority Pre-emptive scheduling algorithm by defining
process structure.


3 a) Write a shell program to find largest of n numbers, storing numbers in
an array.
b) Implement Round Robin scheduling algorithm by defining process
structure.


4 a) Write a shell program to Read two matrices , find addition and display
the input matrices and resultant in matrix format
b) Implement Priority Non-preemptive scheduling algorithm by defining
process structure.


5 a) Write a program to perform the following task using I/O system calls
for file I/O
i. Reading first 10 characters from file
ii. Skipping 5 characters from current position in the file
iii. Going to 5th last character in the file
iv. Going to the 3rd character in the file
b) Implement FCFS scheduling algorithm by defining process structure.


6 a) Write a program to demonstrate zombie and orphan process.
b) Implement SJF Non-preemptive scheduling algorithm by defining
process structure.


7 a) Write a program to simulate grep command using system calls
b) Write a program to generate and print Fibonacci series with the
following requirements:
 - Parent program should create a child and distribute the task of
generating Fibonacci no to its child.
 - The code for generating Fibonacci series should reside in different
program.
 - Child should write the generated Fibonacci series to a shared memory.
 - Parent process has to print by retrieving the Fibonacci series from the
shared memory.
i) Implement the above using shmget and shmat
Note: Shared object should be removed at the end in the program


8 a) Write a program to simulate ls command using system calls.
b) Write a program to generate and print Fibonacci series with the
following requirements:
 - Parent program should create a child and distribute the task of
generating Fibonacci no to its child.
 - The code for generating Fibonacci series should reside in different
program.
 - Child should write the generated Fibonacci series to a shared memory.
 - Parent process has to print by retrieving the Fibonacci series from the
shared memory.
i) Implement the above using shm_open and mmap
Note: Shared object should be removed at the end in the program


9 a) Write a shell program to check whether a given no. is a palindrome or
not
b) Write a program to generate and print N ODD numbers with the
following requirements:
 - Parent program should create a child and distribute the task of
generating odd numbers to its child.
 - The code for generating odd numbers should reside in different
program.
 - Child should write the generated odd numbers to a shared memory.
 - Parent process has to print the odd numbers by retrieving from the
shared memory.
i) Implement the above using shmget and shmat
Note: Shared object should be removed at the end in the program


10 a) Write a program to simulate cat command using system calls.
b) Write a program to generate and print Prime nos. between a given
3
range (between M & N) with the following requirements:
 - M & N should be passed as command line arguments
 - Error checking should be done to verify the required no. of arguments
at the command line
 - Parent program should create a child and distribute the task of
generating Prime numbers to its child.
 - The code for generating Prime numbers should reside in different
program.
 - Child should write the generated Prime numbers to a shared memory.
 - Parent process has to print the Prime numbers by retrieving from the
shared memory.
i) Implement the above using shm_open and mmap
Note: Shared object should be removed at the end in the program.

11 a) Write a program with two threads and a main thread. Schedule the
task of calculating the natural sum upto ‘n’ terms and factorial of ‘n’
on these threads.
Note: The main thread should read ‘n’ from command line and pass it
as parameter to remaining threads. Terminate the threads using system
calls.
b) Write a program that implements solution to Producer – Consumer
problem using mutex and semaphores.


12 a) Write a shell program to find the largest of three numbers
b) Write a program that implements solution to Readers-Writers problem
using mutex and semaphores
