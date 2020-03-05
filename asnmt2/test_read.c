// /Giovanni Vittozzi
// /CSC 290Z
// /Due date: //2020

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFERSIZE 4096


int main(void)
{
    int fd;
    int buff_size = 1;
    char buff[BUFFERSIZE];
    int size;
    // fd = open("MyFile.txt", O_RDONLY);
    fd = open("MyFile.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);

    if (fd < 0)
    {
        printf("Error Opening file\n");
        return -1;
    }
    while ((size = read(fd, buff, 1)) > 0)
    {
        buff[1] = '\0';
        printf("%s\n", buff);
    }
    exit(0);
}



	off_t current_pos;
	current_pos = lseek(fd_1, 0, SEEK_SET);