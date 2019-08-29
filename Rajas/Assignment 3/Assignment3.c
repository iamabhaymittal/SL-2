#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int mat1[5][5], mat2[5][5];
int k = 0;
int r1,c1,r2,c2;

void *thread_function(void *arg)
{
	int i;
	int result = 0;
	int *a = arg;

	if(*a%c2 == 0)
		k++;
		
	for(i=0;i<r2;i++)
	{
		result = result + mat1[k][i] * mat2[i][*a%c2];
	}
	
	pthread_exit((int *)result);
};

int main() 
{

	int res;
	pthread_t thread[20];
	void *thread_result;
	int mat3[5][5],a = 0,b = 0;
	int i,j;
		
	while(1)
	{
		printf("\nEnter number of rows and columns of Matrix 1: ");
		scanf("%d%d",&r1,&c1);

		printf("\nEnter number of rows and columns of Matrix 2: ");
		scanf("%d%d",&r2,&c2);
		
		if(c1 == r2)
			break;
			
		else
			printf("\nMultiplication cannot be performed\nPlease Enter Again: ");	
	}
	
	printf("Enter Matrix 1: ");	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}		

	printf("\nEnter Matrix 2: ");		
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
		
	int n = r1*c2;
	
	for(i=0;i<n;i++) 
	{
		res = pthread_create(&(thread[i]), NULL, thread_function,(void *)&i);

		if (res != 0) 
		{
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	
	printf("Waiting for threads to finish...\n");
	
	for(i=0;i<n;i++)
	{
		res = pthread_join(thread[i],&thread_result);
	
		if (res == 0) 
		{
			printf("Picked up a thread\n");
		}
		else
		{
			perror("pthread_join failed");
		}
		b = (b+1)%c2;
		if(b==0)
			a++;
		mat3[a][b]=(int *)thread_result;

	}
	
	for(i=0;i<r1;i++)
	{
	printf("\n");
		for(j=0;j<c2;j++)
		{
			printf("%d\t",mat3[i][j]);
		}
	}
	exit(EXIT_SUCCESS);
}


