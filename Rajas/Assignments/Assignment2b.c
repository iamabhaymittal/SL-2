#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void quickSort(int [],int ,int );
int partition(int [],int ,int );


int main()
{
	static int count;
	int i,j,n;
 	int *status=NULL;
 	int arr[30];
 	int choice;
       char *arg[30];
       
      here:
       if(count!=0)
       {
       	printf("\nDo you want to store more nos.?");
       	printf("\n1.Yes\n2.No\n");
       	scanf("%d",&choice);
       	if(choice==2)
       	{
       	   return 0;
       	}
       
       }
	 printf("\nEnter the number of elements:");
 	scanf("%d",&n);
	char *str[15];
	//char str;
 	for(i=0;i<n;i++)
 	{ 
  		scanf("%d",&arr[i]);
 	}
 	quickSort(arr,0,n-1);
      
	pid_t pid;
 	pid=fork();

 	if(pid==0)
 	{
 		 printf("\n\t This is child process. ");
 		 printf("\n\t My process id is : %d", getpid());
  		printf("\n\t My Parent process id is : %d", getppid());
  		 printf("\nSorted nos. in main are:");  
 		for(i=0;i<n;i++)
  	 		printf("    %d",arr[i]);
  		for(i=0;i<n;i++)
 		{
 			//printf("%d",arr[i]);
 			sprintf(str,"%d",arr[i]);
 			arg[i]=(char*)malloc(sizeof(str));
 			strcpy(arg[i],str);
 		}
 		arg[i]=NULL;
 		printf("\nI am here 2");
 		
  		execve("./op1",arg,NULL);
  		
  		printf("\nI am here 3");
 	 printf("\n\n");
 	}
 	else
 	{
 	
  		printf("\n\n\t Parent process resumed after the execution of child process with PID %d", pid);
  		printf("\n\t My process id is : %d", getpid());
  		printf("\n\t My Parent process id is : %d", getppid());
  		printf("\nSorted nos. in main are:");  
 		for(i=0;i<n;i++)
  	 		printf("    %d",arr[i]);
  	 		
  	 	
  		printf("\n\n");
  		
  		pid=wait(status);
  		printf("\nBAck to parent process");
  		count++;
  		goto here;
 	}
 	
 
 return 0;
}


void quickSort(int arr[],int low,int high)
{
	int j;
	if(low<high)
 	{
  		j=partition(arr,low,high);
  		quickSort(arr,low,j-1);
  		quickSort(arr,j+1,high);  
 	}
}

int partition(int arr[],int low,int high)
{
	int i,j,temp,pivot;
	pivot=arr[low];
	i=low;
	j=high+1;
 
 	do
 	{
  		do
   			i++;
  		while(arr[i]<pivot && i<=high);
  		do
   			j--;
  		while(arr[j]>pivot);

  		if(i<j)
  		{
   			temp=arr[i];
   			arr[i]=arr[j];
   			arr[j]=temp;  
  		}
 	}while(i<j);
 
 	arr[low]=arr[j];
 	arr[j]=pivot;
 
 return(j);
}


