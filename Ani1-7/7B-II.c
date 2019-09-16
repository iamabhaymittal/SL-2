// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd1; 
	int char_count = 0;
	int word_count = 1;
	int sent_count = 1;
	int i = 0;
	char *result[3];
	char * myfifo = "/home/nllab14/33131/myfifo"; 
	mkfifo(myfifo, 0666); 
	char str1[80], str2[80]; 
	while (1) 
	{
		printf("\n Waiting for file 1 to write \n");
		wait(NULL);
		fd1 = open(myfifo,O_RDONLY); 
		read(fd1, str1, 80); 

		printf("\n User1: %s\n", str1); 
		while(str1[i] != '\0')
		{
			if((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= '0' && str1[i] <= '9'))
				char_count++;
			if(str1[i] == ' ')
				word_count++;
			if(str1[i] == '.' && str1[i+1] == ' ')
				sent_count++;
			i++;
		}
		close(fd1);
		sprintf(str2, "Number of characters = %d \n Number of words = %d \n Number of sentences = %d \n",char_count, word_count, sent_count);  
		printf("\n file 2 to write \n");
		fd1 = open(myfifo,O_WRONLY); 
		write(fd1, str2, strlen(str2)+1); 
		close(fd1); 
	} 
	return 0; 
} 
