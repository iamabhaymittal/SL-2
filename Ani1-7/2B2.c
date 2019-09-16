#include <stdio.h>

int binary_search(int A[50], int low, int high, int key)
{
	int mid;
	mid = (low+high)/2;
	if(A[mid] == key)
		return mid;
	else if(A[mid] > key && low < high)
	{
		return binary_search(A,low,mid-1,key);
	}
	else if(A[mid] < key && low < high)
	{
		return binary_search(A,mid+1,high,key);	
	}
	else
		return -1;
}

int main(int argc, char *argv[])
{
	int key,i,arr[argc],loc;
	printf("\nEnter key to search \n");
	scanf("%d",&key);
	for(i=0;i<argc;i++)
	{
		arr[i]=atoi(argv[i]);
	}
	loc=binary_search(arr,0,argc-1,key);
	if(loc!=-1)
		printf("\nElement %d found at %d \n",key,loc+1);
	else
		printf("\nElement not found \n");
	return 0;
}
