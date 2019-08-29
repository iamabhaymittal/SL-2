#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


int A[SIZE][SIZE], B[SIZE][SIZE];
long int C[SIZE][SIZE];
int t=1;




void *mult_threads()
{
	
}


void acceptMatrix(int M[SIZE][SIZE], int rows, int cols)
{
	int i,j;
	printf("\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("Value at [%d][%d]:",i+1,j+1)
			scanf("%d",&M[i][j]);
		}
	}
}

void displayMatrix(int M[SIZE][SIZE], int rows, int cols)
{
	int i,j;
	printf("\n");
	for(i=0;i<rows;i++)
	{
		printf("\n");
		for(j=0;j<cols;j++)
		{
			printf("%d  ",M[i][j]);
		}
		printf("\n");
		
	}
}


int main()
{
	int A_rows,A_cols,B_rows,B_cols;
	int rcArgs[3];
	printf("For Matrix A:\n");
	printf("Number of Rows:\n");
	scanf("%d",&A_rows);
	printf("Number of Columns:\n");
	scanf("%d",&A_cols)
	printf("For Matrix B:\n");
	printf("Number of Rows:\n");
	scanf("%d",&B_rows);
	printf("Number of Columns:\n");
	scanf("%d",&B_cols);
	
	if(A_cols != B_rows)
	{
		printf("Matrix Multiplication not possible.");
		printf("For Matrix A:\n");
		printf("Number of Rows:\n");
		scanf("%d",&A_rows);
		printf("Number of Columns:\n");
		scanf("%d",&A_cols)
		printf("For Matrix B:\n");
		printf("Number of Rows:\n");
		scanf("%d",&B_rows);
		printf("Number of Columns:\n");
		scanf("%d",&B_cols);
	}
	acceptMatrix(A,A_rows,A_cols);
	acceptMatrix(B,B_rows,B_cols);
	
	
	

	
	
	return 0;
}


