#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>


int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) 
	{ 
       	int mid = l + (r - l) / 2; 
  
      		// If the element is present at the middle 
       	// itself 
      		if (arr[mid] == x) 
            		return mid; 
  
        	// If element is smaller than mid, then 
        	// it can only be present in left subarray 
        	if (arr[mid] > x) 
              	return binarySearch(arr, l, mid - 1, x); 
  
       	// Else the element can only be present 
        	// in right subarray 
        	return binarySearch(arr, mid + 1, r, x); 
       } 
  
       // We reach here when element is not 
       // present in array 
       return -1; 
} 
int main(int argc,char *argv[])
{

	int result ;
	
	int i,j,c,ele,key;
	int arr[argc];

	for(i=0;i<argc-1;i++)
 	{
  		int n=atoi(argv[i]);
  		arr[i]=n;
 	}

 	printf("\nEnter the element to search :");
	scanf("%d",&key);

 	result=binarySearch(arr,0,argc-1,key);

       (result == -1) ? printf("Element is not present"
                            " in array") 
                   	 : printf("Element is present at "
                            "index %d", 
                            result); 
	return 0;
}

   


