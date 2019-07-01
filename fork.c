#include<stdio.h>

int main()
{
	int id;
	printf("\nBefore fork()\n");
	id = fork();
	
	if(id == 0)
	{
		//wait();
		printf("Parent process is running\nParent process id is: %d %d\n",getppid(),getpid());
		wait();	
	}
	else
	{
		printf("Child process is running\nChild process id is %d %d\n",getppid(),getpid());
		sleep(25);
		exit(0);
	}
	printf("After fork()\n");
	return 0;
}
