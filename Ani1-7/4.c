#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define buffer_size 10

typedef struct 
{
	int in,out;
	sem_t full,empty;
	int buffer[buffer_size];
	pthread_mutex_t lock;
}BUFFER;

BUFFER b;

int item = 1;

void *producer(void *num)
{
	int i, z, value;
	i = *(int *)num;
	printf("\n\tProducer %d preparing to produce\n",i);
	while(1)
	{
		z = (rand() % 10) + 1;
		sleep(z);
		sem_wait(&b.empty);
		sem_getvalue(&b.empty,&value);
		if(value == 0)
			printf("\n\tBUFFER FULL, producer %d waiting for consumer to consume\n",i);
		pthread_mutex_lock(&b.lock);
		printf("\n\tproducer %d produced item %d\n",i,item);
		b.buffer[(b.in++)%buffer_size] = item++;	
		pthread_mutex_unlock(&b.lock);
		sem_post(&b.full);
	}
}

void *consumer(void *num)
{
	int i, z, value, cons;
	i = *(int *)num;
	printf("\nConsumer %d preparing to consume\n",i);
	while(1)
	{
		z = (rand() % 10) + 1;
		sleep(z);
		sem_wait(&b.full);
		sem_getvalue(&b.full,&value);
		if(value == buffer_size)
			printf("\nBUFFER EMPTY, consumer %d waiting for producer to produce\n",i);
		pthread_mutex_lock(&b.lock);
		cons = b.buffer[(b.out++) % buffer_size];
		printf("\nConsumer %d consumed item %d\n",i,cons);	
		pthread_mutex_unlock(&b.lock);
		sem_post(&b.empty);
	}
}

void init()
{
	b.in = 0;
	b.out = 0;
	sem_init(&b.empty, 0, buffer_size);
	sem_init(&b.full, 0, 0);
	pthread_mutex_init(&b.lock, NULL);
}

int main(int argc, char *argv[])
{
	int i, np, nc;
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	pthread_t p_id[buffer_size], c_id[buffer_size];
	printf("Enter number of producers :: ");
	scanf("%d",&np);
	printf("Enter number of consumers :: ");
	scanf("%d",&nc);
	init();
	for(i = 0; i<np; i++)
	{
		pthread_create(&p_id[i], NULL, *producer, &c[i]);
		printf("\tThread created for producer %d-------------------\n",i+1);
	}
	for(i = 0; i<nc; i++)
	{
		pthread_create(&c_id[i], NULL, *consumer, &c[i]);
		printf("-Thread created for consumer %d-------------------\n",i+1);
	}
	for(i = 0; i<np; i++)
	{
		pthread_join(p_id[i], NULL);
		printf("\tThread joined for producer %d --------------------\n",i+1);
	}
	for(i = 0; i<nc; i++)
	{
		pthread_join(c_id[i], NULL);
		printf("Thread joined for consumer %d ---------------------\n",i+1);
	}
	return 0;
}
