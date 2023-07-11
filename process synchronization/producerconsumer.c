/*pogram to implement producerconsumer problem with semaphore solution*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define MAXITEMS 5
#define BUFFER_SIZE 5

pthread_mutex_t mutex;
sem_t empty;
sem_t full;
int in =0, out = 0, buffer[BUFFER_SIZE];

void * producer(void *pno) {
    int item;
    for(int i=0; i<MAXITEMS; i++) {
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("\nProducer %d: Insered item %d at %d\n", *((int *)pno), item, in);
        in = (in+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void * consumer(void *cno) {
    int item;
    for(int i=0; i<MAXITEMS; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buffer[out];
        printf("\nConsumer %d: Removed item %d from %d\n", *((int *)cno), item, out);
        out = (out+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

void main() {
    pthread_t pro[5], con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    int a[] = {1, 2, 3, 4, 5};
    for(int i=0; i<5; i++)
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    for(int i=0; i<5; i++)
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    for(int i=0; i<5; i++)
        pthread_join(pro[i], NULL);
    for(int i=0; i<5; i++)
        pthread_join(con[i], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return;
}