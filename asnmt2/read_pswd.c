// /Giovanni Vittozzi
// /CSC 290Z
// /Due date: //2020

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFERSIZE 4096
// if doing a function; use prototyping
// int main(void){

// 	char buff[BUFFERSIZE];
// 	int size;

// 	strcpy(buff,"HELLO WORLD!!!!!!!!!\n");
// 	size = strlen(buff);	size = size + 1;

// 	write(STDOUT_FILENO,buff,size);
// }

int main(void)
{

	int fd;
	int fd_1;
	char buf[BUFFERSIZE]; //4096 buffersize
	int buff_size = 1;
	char buff[BUFFERSIZE];
	int size;

	//first I append to the file, then I read the file and print it 
	fd = open("MyFile.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
	fd_1 = open("MyFile.txt", O_RDONLY);

	if (fd < 0)
	{
		printf("There was an error opening the file\n");
		return -1;
	}
	strcpy(buf, "General Kenobi\n");
	size = strlen(buf);
	size = size + 1;
	write(fd, buf, size);
	close(fd);
	//read test
	while ((size = read(fd_1, buff, 1)) > 0)
	{
		buff[1] = '\0';
		printf("%s\n", buff);
	}

	printf("lseeking...");
	off_t current_pos;
	current_pos = lseek(fd_1, 0, SEEK_END);


	close(fd_1);
	return 0;
}
