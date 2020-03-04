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
    fd = open("MyFile.txt", O_RDONLY);

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
