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
    // Open the file for READ only.
    int f_read = open("/../../../../etc/passwd", O_RDONLY); //location of /etc/passwd file on my system
    char *str = ":";                                        //when reading file I'm going to compare to this variable
    int colon = 0;                                          //colon counter
    char printbuff1[BUFFERSIZE];
    char printbuff2[BUFFERSIZE];
    int size = 0; //size variable used for printing to stdout

    if (f_read < 0) //base case returns -1 when file isnt located
    {
        return -1;
    }

    int length = lseek(f_read, 0, SEEK_END); //seeks to the end of file and returns integer
    length = length + 1;                     //to create size of character array
    char arr[length];                        //array to parse through
    arr[1] = '\0';                           //array needs to be null terminated to prevent junk

    int beg = lseek(f_read, 0, SEEK_SET); //sets read back to the beginning

    printbuff1[1] = '\0'; //array needs to be null terminated to prevent junk
    printbuff2[1] = '\0'; //array needs to be null terminated to prevent junk

    strcat(printbuff2, str); //concatinate : to this buffer (will eventually print buffer1(username):buffer2(shell))

    while ((length = read(f_read, arr, 1)) > 0)
    {
        int size1;
        int size2;

        if (strncmp(arr, str, length) != 0 && colon % 6 == 0) //want to get first and last phrase on each line
        {
            strcat(printbuff1, arr); //add whats there to the buffer
            size1 = strlen(printbuff1);
            size1 = size1 + 1; //get size of this buffer
        }
        else if (strncmp(arr, str, length) != 0 && colon % 6 == 1)
        {
            size2 = strlen(printbuff2); 
            size2 = size2 + 1;
            strcat(printbuff1, printbuff2); //concatinate usernames and shells
        }
        else if (strncmp(arr, str, length) == 0)
        {
            colon++;
        }
        size = size1 + size2;
    }
    write(STDOUT_FILENO, printbuff1, size); //write buffer to stdout

    close(f_read);
    return 0;
}
