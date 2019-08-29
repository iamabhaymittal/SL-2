#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
        pid_t pid, p;
        int n, *num, i, j, temp,n1,*num1;
        pid = getpid();
        printf("Enter the length of the array for child: ");
        scanf("%d",&n);
        num = (int*)malloc(sizeof(int)*n);
        printf("Enter the array:\n");
        for(i = 0 ; i < n ; i++)
                scanf("%d",&num[i]);
                
        printf("Enter the length of the array for Parent: ");
        scanf("%d",&n1);
        num1 = (int*)malloc(sizeof(int)*n1);
        printf("Enter the array:\n");
        for(i = 0 ; i < n1 ; i++)
                scanf("%d",&num1[i]);
        p = fork();
        if(p == 0 )
        {
                printf("Child process exucuting\n");
                for(i = 0 ; i < n ; i++ )
                {
                        for(j = 0 ; j < n-i-1 ; j++)
                        {
                                if(num[j] > num[j+1])
                                {
                                        temp = num[j];
                                        num[j] = num[j+1];
                                        num[j+1] = temp;
                                }
                        }
                }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n ; i++)
                {
                        printf("%d ",num[i]);
                }
                printf("\n");
        }
        else
        {
        	printf("Parent process exucuting\n");
                for(i = 0 ; i < n1 ; i++ )
                {
                        for(j = 0 ; j < n1-i-1 ; j++)
                        {
                                if(num1[j] > num1[j+1])
                                {
                                        temp = num1[j];
                                        num1[j] = num1[j+1];
                                        num1[j+1] = temp;
                                }
                        }
                }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n1; i++)
                {
                        printf("%d ",num1[i]);
                }
                printf("\n");
        
        
        }
return 0;
}
