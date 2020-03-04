///////Giovanni Vittozzi
///////CSC 290Z
///////Due date: //2020

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define BUFFERSIZE 4096

// int main(void){
	
// 	char buff[BUFFERSIZE];	
// 	int size;	

// 	strcpy(buff,"HELLO WORLD!!!!!!!!!\n");	
// 	size = strlen(buff);	size = size + 1;
    
// 	write(STDOUT_FILENO,buff,size);
// }


int main(void){
	
	int fd;	
	char buf[BUFFERSIZE];	
	int size;	

    fd = open("MyFile.txt", O_WRONLY | O_APPEND | O_CREAT,0666);	

	if (fd < 0)	{		
		printf("There was an error opening the file\n");		
		return -1;	
	}	
	strcpy(buf,"Hello World!!!!!!!\n");		
	size = strlen(buf);		
	size = size +1;		
	write(fd,buf,size);	
	close(fd);	
	return 0;
}
