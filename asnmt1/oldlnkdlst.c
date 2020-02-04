#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;

} NODE;

void Add_At_End(int num, NODE *head){
    NODE *current = head;
    while(current->next !=NULL){
        current=current->next;
    }//check to make sure at the end
    /*current = (NODE *)malloc(sizeof(NODE));
    current->next=NULL;
    current->data = num;
    
    printf("%d\n", current->data);*/
    //free(current);

    current->next = (NODE *) malloc(sizeof(NODE));
    current->next->data= num;
    current->next->next = NULL;
    
}

int main(int argc, char *argv[])
{
    NODE *head, *current;

    head = (NODE *)malloc(sizeof(NODE));
    head->data = 3;
    head->next = NULL;

    printf("%d\n", head->data);
/*

    head->next = (NODE *)malloc(sizeof(NODE));
    head->next->next = NULL;

    current = head->next;

    current->data = 4;

    printf("%d\n", current->data);

    head->next->next = (NODE *)malloc(sizeof(NODE));
    head->next->next->next = NULL;

    current = head->next->next;
    current->data = 5;
    printf("%d\n", current->data);
*/

    Add_At_End(1, head);
    Add_At_End(2, head);
    Add_At_End(3, head);
    free(current);
    free(head);
}