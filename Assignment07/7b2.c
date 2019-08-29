
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd1; 

	char * myfifo = "/tmp/myfifo"; 

	mkfifo(myfifo, 0666); 

	char str1[80], str2[80]; 
	while (1) 
	{ 
		fd1 = open(myfifo,O_RDONLY); 
		read(fd1, str1, 80); 
		
		
		printf("\nLength of Sentence: %d",(strlen(str1)-1));
		
		
	} 
	return 0; 
} 

