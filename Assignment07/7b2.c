// \n is extremely important.



#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd1; 

	int c_w=0,c_s=0;
	char * myfifo = "/tmp/myfifo"; 

	mkfifo(myfifo, 0666); 

	char str1[80]; 
	while (1) 
	{ 
		c_w=0;
		c_s=0;
		fd1 = open(myfifo,O_RDONLY); 
		read(fd1, str1, 80); 
		
		for(int i=0;i<(strlen(str1)-1);i++)
		{
			if(str1[i] == ' ')
				c_w++;
		}
		for(int i=0;i<(strlen(str1)-1);i++)
		{
			if(str1[i] == '.')
				c_s++;
		}
		printf("Number of characters: %d  ",(strlen(str1)-1));
		printf("Number of words: %d  ",c_w+1);
		printf("Number of sentences: %d\n\n",c_s);
		
		
		
	} 
	return 0; 
} 

