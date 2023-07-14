//Program to create two threads seperate for addition and Multiplication

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *sum(void* arg);
void *mul(void* arg);

int sm = 0,prod = 1;

void main(int argc,char *argv[])
{
	pthread_t T1,T2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&T1,&attr,sum,argv[1]);
	pthread_create(&T2,&attr,mul,argv[1]);
	pthread_join(T1,NULL);
	pthread_join(T2,NULL);
	
	printf("Inside Main Thread\n");
	printf("Sum = %d\n",sm);
	printf("Product = %d\n",prod);
}

void *sum(void *parm)
{
	int i,n;
	n = atoi(parm);
	printf("Inside Sum Thread\n");
	for(i = 1;i<=n;i++)
	{
		sm +=i;
	}
	printf("Sum Thread Completed\n");	
}

void *mul(void *parm)
{
	int i,n;
	n = atoi(parm);
	printf("Inside Mul Thread\n");
	for(i = 2;i<=n;i++)
	{
		prod *=i;
	}
	printf("Mul Thread Completed\n");	
}
