//C++ program to demonstrate sorting in parent and 
// printing result in child processes using fork() 
//#include <iostream> 
#include <unistd.h> 
#include<stdio.h>
//#include <algorithm> 
//using namespace std; 
 int pi;
int partition (int arr[], int low,int high)
{
	
    // pivot (Element to be placed at right position)
    int pivot = arr[high];
    int i,j;  
    int k=0;
    int temp;
    int temp1;
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
    	 
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            //swap arr[i] and arr[j]
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        
    }
    //swap arr[i + 1] and arr[high])
    temp1=arr[i+1]; //omfg!!program gave core dumped and all kinds of BS errors when i used temp instead of temp1 for swapping!
    arr[i+1]=arr[high];
    arr[high]=temp1;
    return (i + 1);
}
int quick(int arr[], int low, int high)
{
   // printf("\nHowz it goin bross");
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quick(arr, low, pi - 1);  // Before pi
        quick(arr, pi + 1, high); // After pi
    }
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
    
     
    
    int a1[] = { 11, 16, 13, 14, 19, 12, 17, 15, 18, 110 }; 
    int n1 = sizeof(a1)/sizeof(a1[0]); 
    
    int id = fork(); 
    // Checking value of process id returned by fork 
    if (id > 0) 
    { 
    	 
        printf("Parent process \n"); 
  
        quick(a,a[0],a[9]); 
    	 wait(5);
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


