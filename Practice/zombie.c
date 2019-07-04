#include<stdio.h>

int main()
{
	int pid = fork();
	
	if (pid > 0)
	{
		
		printf("in parent process...\n");
		printf("pid:%d\n",getpid());
		printf("ppid:%d\n",getppid());
		sleep(5);
		exit(0);
	}
	
	else if(pid == 0)
	{
		
		printf("in child process...\n");
		printf("pid:%d\n",getpid());
		printf("ppid:%d\n",getppid());
		sleep(10);
		printf("in child process...\n");
		printf("pid:%d\n",getpid());
		printf("ppid:%d\n",getppid());
		
	}
	return 0;
}
