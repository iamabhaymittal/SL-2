#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//#include <bits/stdc++.h> 

// maximum size of matrix 
#define MAX 4 

// maximum number of threads 
#define MAX_THREAD 4 

int r1,r2,c1,c2,i,j;
int step = 0; 
int i,j,k;

int acceptmat(int A[10][10],int B[10][10])
{
	printf("\nEnter row1: ");
	scanf("%d",&r1);
	
	printf("\nEnter column1: ");
	scanf("%d",&c1);
	
	
	
	printf("\nEnter row2: ");
	scanf("%d",&r2);
	
	printf("\nEnter column2: ");
	scanf("%d",&c2);
	
	
	
	printf("\nEnter the elements for matrix A");
	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("\nA[%d][%d] : ",i,j);
			scanf("%d",A[i][j]);
		}
	}


	
	printf("\nEnter the elements for matrix B");
	
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("\nB[%d][%d]",i,j);
			scanf("%d",B[i][j]);
		}
	}
	// Displaying matA 
	printf("\nMatrix A is:\n");
	 
	for (int i = 0; i < r1; i++)
	{ 
		for (int j = 0; j < c1; j++) 
			printf("%d",A[i][j]);
	} 

	// Displaying matB 
	printf("\nMatrix B is:\n");
	
	for (int i = 0; i < r2; i++) 
	{ 
		for (int j = 0; j < c2; j++) 
			printf("%d",B[i][j]); 
	} 
}
	
	
 
 
int C[10][10];


/*void* multi(void* arg)
{
	int core=step++;
	
	for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) 
		for (j = 0; j < MAX; j++) 
			for ( k = 0; k < MAX; k++) 
				matC[i][j] += matA[i][k] * matB[k][j]; 
	
}*/

int multi(int A[10][10],int B[10][10],int r1,int c1,int r2)
{
	int i,j,k;
	
	for(i=0; i<r1; ++i)
       	 for(j=0; j<c2; ++j)
       	      for(k=0; k<c1; ++k)
            		{
                		C[i][j]+=A[i][k]*B[k][j];
            		}
}

int main() 
{ 
	/*// Generating random values in matA and matB 
	for (int i = 0; i < MAX; i++)
	{ 
		for (int j = 0; j < MAX; j++)
		{ 
			matA[i][j] = rand() % 10; 
			matB[i][j] = rand() % 10; 
		} 
	} */
	int A[10][10],B[10][10],C[10][10];
	acceptmat(A,B);
	// declaring four threads 
	pthread_t threads[MAX_THREAD]; 

	// Creating four threads, each evaluating its own part 
	for (int i = 0; i < MAX_THREAD; i++) 
	{ 
		int* p; 
		pthread_create(&threads[i], NULL, multi, (void*)(p)); 
	} 

	// joining and waiting for all threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL);	 

	// Displaying the result matrix 
	printf("\nResult of multiplication is : ");
	for (int i = 0; i < r1; i++) 
	{ 
		for (int j = 0; j < c2; j++) 
			printf("%d",C[i][j]); 
	} 
	return 0; 
} 

