#include <stdio.h>
int main()
{
	int id;
	printf("\nBefore forking\n");
	id=fork();
	if(id!=0)
	{
		printf("\nParent process is running \n parent process id is %d\n parent's parent id is (i.e bash id) %d \n",getpid(),getppid());
		sleep(1);
		printf("Parent process terminated\n");
		exit(0);
	}
	else
	{
		printf("Child process is running \n child process id is %d\n child's parent id is %d \n",getpid(),getppid());
		printf("Child is going to sleep \n");
		sleep(5);
		printf("\n Child is now orphan \n");
		printf("Child process is running \n child process id is %d\n child's parent id is %d \n",getpid(),getppid());
	}
}
