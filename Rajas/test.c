//C++ program to demonstrate sorting in parent and 
// printing result in child processes using fork() 
//#include <iostream> 
#include <unistd.h> 
//#include <algorithm> 
//using namespace std; 
 #include<stdio.h>
// Driver code 
int main() 
{ 
    int a[] = { 1, 6, 3, 4, 9, 2, 7, 5, 8, 10 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    int id = fork(); 
  
    // Checking value of process id returned by fork 
    if (id > 0) { 
        printf("Parent process \n"); 
  
       // sort(a, a+n); 
    
        // Displaying Array 
        printf(" sorted numbers are "); 
        for (int i = 0; i < n; i++)  
            printf("\t",a[i]); 
  
        printf("\n"); 
  
    } 
  
    // If n is 0 i.e. we are in child process 
    else { 
        printf("Child process \n"); 
        printf("\n  numbers to be sorted are "); 
        for (int i = 0; i < n; i++)  
            printf("\t",a[i]);        
    } 
  
    return 0; 
} 
