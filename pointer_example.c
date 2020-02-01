#include <stdio.h>
#include<stdlib.h>

int add2(int num1, int num2); //gives a footprint of the function so main knows what to do when it sees it

int main(int arg, char **argv){
    int number = 45;
    int *p;
    int **q;
    int list[] = {2,4,6};   

    p = &list;
/*
    printf("The value of the first item in the list is %d\n", list[0]);
    printf("The value of the address of the list is %u\n", &list);
    printf("The value of the pointer is %u\n", p);
    printf("The value of the pointer is %d\n", *(++p)); //u is unsigned integer
    //look at this one again

    //HW PLAY WITH POINTERS 
*/
    p =&number; //pointer p is address of number
    q = &p;     //pointer q is the address of p

                //*p is the value stored at the address that is stored in p
/*
    printf("The value of Number is: %d\n", number);
    printf("The Address of Number is: %u\n", &number);
    printf("The value of the pointer is: %u\n", p);
    printf("The value of dereferenced of p is: %d\n", *p);
    printf("The Address of p is %u\n", &p);
    printf("The value of pointer q is %u\n", q);
    printf("The value of dereferenced of q is %u\n", *q); //will print address of number (3479567716)
  
    */
    //%u is unsigned number and %d is integer value

printf("number value %d\n", number);
printf("p value %u\n", p); //p is the address of number 
printf("address of number: %u\n", &number);
printf("*p value is number :%d\n", *p); //p is the address of number 
printf("p address %u\n", &p);
printf("q value is p address:%u\n", q); //p is the address of number 
printf("*q: %u is number address: %u\n", *q, &number);
printf("**q is %u\n", **q);


}