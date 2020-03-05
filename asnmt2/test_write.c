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
    char buf[BUFFERSIZE];
    int size;

    fd = open("MyFile.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);

    if (fd < 0)
    {
        printf("There was an error opening the file\n");
        return -1;
    }
    // strcpy(buf,"Hello World!!!!!!!\n");
    // size = strlen(buf);
    // size = size +1;

    strcpy(buf, "ABC\n");
    lseek(fd, 7, SEEK_SET);

    write(fd, buf, 3);//writes 3 of the buffer to fd (new file)
    close(fd);



    int fd_1 = open("MyFile.txt", O_RDONLY); 
    while ((size = read(fd_1, buf, 1)) > 0)
    {
        buf[1] = '\0';
        printf("%s\n", buf);
    }
    close(fd_1);
    return 0;
}
