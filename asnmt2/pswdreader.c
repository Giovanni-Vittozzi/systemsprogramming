// /Giovanni Vittozzi
// /CSC 290Z
// /Due date: //2020

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFERSIZE 4096


int main(void)
{
    // Open the file for WRITE and READ only.
    // int f_read = open("MyFile.txt", O_RDONLY);
    int f_read = open("/../../../../etc/passwd", O_RDONLY);
    int f_write = open("output.txt", O_WRONLY); //save outputted stuff to file
    int i = 0;
    char *str = ":";
    int colon = 0;
    char printbuff1[BUFFERSIZE];
    char printbuff2[BUFFERSIZE];
    int size = 0;

    if (f_read < 0) //base case
    {
        return -1;
    }

    int length = lseek(f_read, 0, SEEK_END); //seeks to the end of file and returns integer
    length = length + 1; //to create size of character array

    int beg = lseek(f_read, 0, SEEK_SET); //sets read back to the beginning

    char arr[length]; //array to parse through
    arr[1] = '\0';    //array needs to be null terminated to prevent junk
    printbuff1[1] = '\0';    //array needs to be null terminated to prevent junk
    printbuff2[1] = '\0';    //array needs to be null terminated to prevent junk
    int fd_1 = open("MyFile.txt", O_RDONLY);

            strcat(printbuff2, str);
    // reader(f_read, length, arr, str);

    while ((length = read(f_read, arr, 1)) > 0)
    {
        int size1;
        int size2;

        if (strncmp(arr, str, length) != 0 && colon % 6 == 0)
        {
            strcat(printbuff1, arr);
            size1 = strlen(printbuff1);
            size1 = size1 + 1;
        }
        else if (strncmp(arr, str, length) != 0 && colon % 6 == 1)
        {
            size2 = strlen(printbuff2);
            size2 = size2 + 1;
            strcat(printbuff1, printbuff2);
        }
        else if (strncmp(arr, str, length) == 0)
        {
            colon++;
        }
        size = size1 + size2;
    }
    write(STDOUT_FILENO, printbuff1, size);

    close(f_read);
    close(f_write);
    return 0;
}
