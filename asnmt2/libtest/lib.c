#include <math.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


extern void printa(char printbuff1[], int size)
{
    write(STDOUT_FILENO, printbuff1, size);
}


