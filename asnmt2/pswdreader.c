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
    // Open the file for WRITE and READ only.
    // int f_read = open("MyFile.txt", O_RDONLY);
    int f_read = open("/../../../../etc/passwd", O_RDONLY);
    int f_write = open("output.txt", O_WRONLY); //save outputted stuff to file
    int i = 0;
    char *str = ",";
    int comma = 0;

        if (f_read < 0) //base case
    {
        printf("There was an error opening the file\n");
        return -1;
    }

    int length = lseek(f_read, 0, SEEK_END); //seeks to the end of file and returns integer
    printf("Length of file is: %d\n", length);
    length = length + 1; //to create size of character array

    int beg = lseek(f_read, 0, SEEK_SET); //sets read back to the beginning
    printf("Should be back at beg: %d\n", beg);

    char arr[length]; //array to parse through
    arr[1] = '\0';    //array needs to be null terminated to prevent junk
    int fd_1 = open("MyFile.txt", O_RDONLY);
    printf("value of *str is: %d\n", *str);
    while ((length = read(f_read, arr, 1)) > 0)
    {
        // //prints out buffer
        // arr[1] = '\0';
        // printf("%s\n", arr);

        // //debugging:
        // printf("i is: %d\n", i);
        // printf("arr[i] is: %d\n", arr[i]);
        // printf("%s\n", arr); //prints entire thing
        // if (arr == str)
        //NEEDED TO USE STRNCMP because its a null terminated buffer
        if (strncmp(arr, str, length) == 0)
        {
            printf("Found A at: %d\n", i);
            comma++; //reach 12
            if(comma == 12){
                // printf("DONE\n");
                printf("%s\n", arr);
            }

            i++;
        }
        else
        {
            i++;
        }
    }
    printf("Number of commas: %d\n", comma);

    close(f_read);
    close(f_write);
    return 0;
}
