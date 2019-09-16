#include <stdio.h>
int main()
{
	int id;
	printf("\nBefore forking\n");
	id=fork();
	if(id!=0)
	{
		printf("\nParent process is running \n parent process id is %d\n parent's parent id is (i.e bash id) %d \n",getpid(),getppid());
		sleep(5);
		printf("Parent wakes up and started a infinite task \n");
		while(1)
		{
			
		}
		printf("Parent is terminating \n");
		exit(-1);
	}
	else
	{
		printf("Child process is running \n child process id is %d\n child's parent id is %d \n",getpid(),getppid());
		printf("Child is terminating \n");
		exit(0);
	}
}	
