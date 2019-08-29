// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping 
// when child process exits. 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// Fork returns process id 
	// in parent process 
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid ==0)
	{
		printf("It is the parent process..with pid %d\n",getpid()); 
		sleep(1); 
	}
	// Child process 
	else
	{
		printf("It is the child process..with pid %d\n",getpid());		
		sleep(10); 
	}
	return 0; 
} 

