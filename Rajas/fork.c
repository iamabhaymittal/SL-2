    #include<stdio.h>      // printf()
    #include<stdlib.h>     // exit()
    #include<sys/types.h>  // pid_t
    #include<sys/wait.h>   // wait()
    #include<unistd.h>     // fork
     
     
    int main(int argc, char **argv)
    {
    	pid_t pid;
    	pid = fork();
    	if(pid==0)
    	{
    		printf("It is the child process..with pid %d\n",getpid());
    		//int i=0;
    		/*for(i=0;i<100000;i++)
    		{
    			printf("%d\n",i);
    		}*/
		sleep(10);
    		exit(0);
    	}
    	else if(pid > 0)
    	{
    		printf("It is the parent process..with pid %d\n",getpid());
    		int status;
    		wait(&status);

      	}
    	else
    	{
    		printf("Error in forking..\n");
    		exit(EXIT_FAILURE);
    	}
    	return 0;
    } 
