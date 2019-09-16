#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 4
int num;

void *factorial(void *arg) 
{
	int i, k, lb, ub, *Args, z;
	long int return_value=1; 
	Args = (int *) arg;
	lb = Args[0];
	ub = Args[1];
	printf("\n\tThread No %d-%d joined",lb,ub);
	for(i=lb;i<=ub;i++)
	{
		return_value = return_value * i;
		printf("\n - Thread No %d-%d - Calculated %ld x %d = %ld",lb,ub,(return_value)/i,i,return_value);
		z=rand()%10;
		printf("\n - Thread No %d-%d Paused -- Sleeping for %d units", lb, ub, z);
		sleep(z);
		printf("\n\n\t - Thread No %d-%d .......Resumed",lb,ub);
	}
	printf("\n...........Thread No %d-%d .................exits\n",lb,ub);
	pthread_exit((void *) return_value);
}

int main()
{
	int partition_num, i, j, k;
	pthread_t P[SIZE];
	int Args[2];
	long int return_values[SIZE];
	long int ans;
	int *status;
	printf("Enter a number to find it's factorial :: ");
	scanf("%d", &num);
	partition_num = num/SIZE;
	for(i=0; i<SIZE; i++)
	{
		if(i<3)
		{
			Args[0] = (partition_num*i)+1;
			Args[1] = (partition_num*(i+1));
		}
		else
		{
			Args[0] = (partition_num*i)+1;
			Args[1] = num;
		}
		if(pthread_create(&P[i],NULL,factorial,Args)!=0)
				printf("\n\tCannot create thread.\n");
		else
		{
			printf("\n\n\tThread No %d-%d Created",Args[0], Args[1]);
			sleep(2);
		}
	}
	for(i=0; i<SIZE; i++)
	{
		if(pthread_join(P[i],(void **) &status) != 0)
			perror("\nThread join failed.\n");
		return_values[i] = (long int)status;
	}
	ans = return_values[0]*return_values[1]*return_values[2]*return_values[3];
	printf("\n\nThe answer is %ld\n\n",ans);	
}
