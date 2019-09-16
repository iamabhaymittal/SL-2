#include <iostream.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define buffer_size 10
using namespace std;

int readcount=0,writecount=0;
sem_t x,y,z,rsem,wsem;
pthread_t r[10],w[10];

void *reader();
void *writer();

void *reader()
{
	while(1)
	{
		sem_wait(&z);
			sem_wait(&rsem);
				sem_wait(&x);
					readcount++;
					if(readcount==1)
						sem_wait(&wsem);
				sem_post(&x);
			sem_post(&rsem);
		sem_post(&z);
		//read
		sem_wait(&x);				
	}
}

