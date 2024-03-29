// C program to implement one side of FIFO 
// This side writes first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd; 

	// FIFO file path 
	char * myfifo = "/home/nllab14/33131/myfifo"; 
	int i = 0;
    FILE *fp;
	// mkfifo(<pathname>, <permission>) 
	mkfifo(myfifo, 0666); 

	char arr1[80], arr2[80]; 
	while (1) 
	{ 
		// Open FIFO for write only 
		fd = open(myfifo, O_WRONLY); 

		// Take an input arr2ing from user. 
		// 80 is maximum length
		printf("\n file 1 to write \n\n"); 
		fgets(arr2, 80, stdin); 
		fp = fopen("fifo.txt","w");
      	while (arr2[i] != '\0')
      	{
        	fputc(arr2[i],fp);
      		i++;
      	}
		// Write the input arr2ing on FIFO 
		// and close it 
		write(fd, arr2, strlen(arr2)+1); 
		close(fd);
		printf("\n Waiting for file 2 to write \n"); 
		wait(NULL);
		// Open FIFO for Read only 
		fd = open(myfifo, O_RDONLY); 

		// Read from FIFO 
		read(fd, arr1, sizeof(arr1)); 

		// Print the read message 
		printf("\n User2:\n %s\n", arr1); 
		close(fd); 
	} 
	return 0; 
} 


