//C++ program to demonstrate sorting in parent and 
// printing result in child processes using fork() 
//#include <iostream> 
#include <unistd.h> 
#include<stdio.h>
//#include <algorithm> 
//using namespace std; 
 

void quick(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick(a,l,j-1);
		quick(a,j+1,u);
	}
}
 
int partition(int a[],int l,int u)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	
	do
	{
		do
			i++;
			
		while(a[i]<v&&i<=u);
		
		do
			j--;
		while(v<a[j]);
		
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	
	a[l]=a[j];
	a[j]=v;
	
	return(j);
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */

// Driver code 
int main() 
{ 
    int a[] = { 1, 6, 3, 4, 9, 2, 7, 5, 8, 10 }; 
    int n = sizeof(a)/sizeof(a[0]);
    //int pi;
     
    
    int a1[] = { 11, 16, 13, 14, 19, 12, 17, 15, 18, 110 }; 
    int n1 = sizeof(a1)/sizeof(a1[0]); 
    
    int id = fork(); 
    // Checking value of process id returned by fork 
    if (id > 0) 
    { 
    	 
        printf("Parent process \n"); 
  	  wait(5);
        quick(a,a[0],a[9]); 
    	
        // Displaying Array 
        printf(" sorted numbers in parent: "); 
        for (int i = 0; i < n; i++)  
            printf("\t %d",a[i]); 
  
        printf("\n");
        
  
    } 
  
    // If n is 0 i.e. we are in child process 
    else 
    { 
        printf("Child process \n"); 
        /*printf("\n  numbers to be sorted are "); 
        for (int i = 0; i < n; i++)  
            printf("\t %d",a1[i]); 
            
        printf("\n");  */
            
        quick(a1,a1[0],a1[9]); 
        sleep(5);
    
        // Displaying Array 
        printf(" sorted numbers of child are "); 
        for (int i = 0; i < n1; i++)  
            printf("\t %d",a1[i]); 
  
        printf("\n");        
    } 
  
    return 0; 
}
