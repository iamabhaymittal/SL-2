#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void merge(int A[50],int low,int mid,int high,int n);
void merge_sort(int A[50],int low,int high,int n);

void merge(int A[50],int low,int mid,int high,int n)
{
	int i=low,j=mid+1,k=low,comp_no=0,m;
	int temp[50];
	while(i<=mid && j<=high)
	{
		if(A[i]<=A[j])
		{
			temp[k]=A[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=A[j];
			j++;
			k++;
		}
	}
	while(j<=high)
	{
		temp[k]=A[j];
		j++;
		k++;
	}
	
	
	while(i<=mid)
	{
		temp[k]=A[i];
		i++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		A[i]=temp[i];
	}
}

void merge_sort(int A[50],int low,int high,int n)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(A,low,mid,n);
		merge_sort(A,mid+1,high,n);
		merge(A,low,mid,high,n);
	}
}

int main()
{
	int n,A[15],i;
	int id;
	char *arg[15],str[15];
	printf("\nBefore forking\n");
	printf("Enter the number of integers to be sorted :- \n");
	scanf("%d",&n);
	printf("\nEnter the integers :- \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("\nEntered integers are :- \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\nSorting array in ascending order \n");
	merge_sort(A,0,n-1,n);
	printf("\nInvoking fork \n");
	id=fork();
	if(id!=0)
	{
		printf("\n--------------------Parent process is on----------------------- \n");
		printf("\nParent process id is %d",getpid());
		printf("\nParent's parent process id is %d \n",getppid());
		wait();
		printf("\nBack to parent process \n");
		printf("\nParent process exited \n");
		exit(0);
	}
	else
	{
		printf("\n---------------------Child process is on----------------------- \n");
		printf("\nChild process id is %d",getpid());
		printf("\nChild's parent process id is %d \n",getppid());
		printf("\nSorted integers are :: ");
		for(i=0;i<n;i++)
		{
			printf("%d ",A[i]);
			sprintf(str,"%d",A[i]);
			arg[i]= (char*) malloc(sizeof(str));
			strcpy(arg[i],str);
		}
		arg[i]=NULL;
		printf("\n\n------------Switching to new program for searching------------- \n");
		execve("./2B2",arg,NULL);
		printf(" \nChild process exited \n");
		exit(0);
	}
}
