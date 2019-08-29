#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
//#include <cstdlib>
#include <string.h>
void *read(void *val);
void *write(void *val);
int readCounter = 0;
sem_t semReader, semWriter;

void *read(void *val)
{
    while (1)
    {
      //readers wait enable untill reader counter increment
        sem_wait(&semReader);
        readCounter++;
        if (readCounter == 1)
        {
          //wait untill readers finish
            sem_wait(&semWriter);
        }
        sem_post(&semReader);
        printf("reader\n");
        sem_wait(&semReader);
        readCounter--;
        if (readCounter == 0)
        {
          //when readers finish writer can write 
            sem_post(&semWriter);
        }
        sem_post(&semReader);
    }
    
}

void *write(void *val)
{
    while (1)
    {
        sem_wait(&semWriter);
        printf("writer\n");
       
        sem_post(&semWriter);
    }
    
}

int main()
{
                                                                                                                                             
    void *status;
    pthread_t reader1, reader2, writer;
    sem_init(&semReader, 0, 1);
    sem_init(&semWriter, 0, 1);
    pthread_create(&reader1, NULL, read, NULL);
    pthread_create(&reader2, NULL, read, NULL);
    pthread_create(&writer, NULL, write, NULL);
    pthread_join(writer, &status);
    pthread_join(reader1, &status);
    pthread_join(reader2, &status);
    sem_destroy(&semReader);
    sem_destroy(&semWriter);
    return 0;
}

