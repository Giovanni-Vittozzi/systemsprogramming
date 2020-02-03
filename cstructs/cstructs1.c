#include <stdio.h>
#include<stdlib.h>


typedef struct Node{

    int data;
    struct Node *next;

}NODE;

typedef s;

/*
typedef struct example{
        char data : 1;
        char data2 : 2;
}EXAMPLE;
*/

int main(int argc, char *argv[])
{
    /*
	EXAMPLE Example;
        int size = sizeof(Example);

        printf("The size of example is: %d\n",size);

    */
    
    NODE *head, *current;

	head = (NODE *)malloc(sizeof(NODE));
	
	head->data = 3;
	head->next = NULL;

	printf("%d\n",head->data);

	head->next = (NODE *)malloc(sizeof(NODE));
	head->next->next = NULL;

	current = head->next;

	current->data = 4;

	printf("%d\n",current->data);

	free(current);
	free(head);	
    

}