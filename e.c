#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int intArray[] = {34, 23, 47, 54};
    int *ptr = intArray;
    printf("%d\n", *(ptr++));
    printf("%d\n", *(ptr++));
    printf("%d\n", *(++ptr));
}