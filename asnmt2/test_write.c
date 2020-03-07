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

    // fd = open("MyFile.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);

    // Open the file for READ only.
    int f_write = open("MyFile.txt", O_RDONLY);

    // Open the file for WRITE and READ only.
    int f_read = open("end.txt", O_WRONLY);

    if (fd < 0)
    {
        printf("There was an error opening the file\n");
        return -1;
    }
    // strcpy(buf,"Hello World!!!!!!!\n");
    // size = strlen(buf);
    // size = size +1;

    // strcpy(buf, "ABC\n");
    // lseek(fd, 7, SEEK_SET);

    // write(fd, buf, 3); //writes 3 of the buffer to fd (new file)
    // close(fd);

    char arr[100];

    int fd_1 = open("MyFile.txt", O_RDONLY);
    while (read(f_write, arr, 1))
    {
        lseek(f_write, 1, SEEK_SET);
        //seek current skips number (1) from the spot that it started reading
        write(f_read, arr, 1);
    }

    close(f_write);
    close(f_read);

    // close(fd_1);
    return 0;
}
