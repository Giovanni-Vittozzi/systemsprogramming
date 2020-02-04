#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;

} NODE;

void Add_At_End(NODE *head, int num)
{
    NODE *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    } //check to make sure at the end
    current->next= (NODE *)malloc(sizeof(NODE));
    current->data = num;
    current->next=NULL;

    printf("%d\n", current->data);
}

int main(int argc, char *argv[])
{
    NODE *head, *current;

    head = (NODE *)malloc(sizeof(NODE));
    head->data = 3;
    head->next = NULL;

    printf("%d\n", head->data);

    head->next = (NODE *)malloc(sizeof(NODE));
    head->next->next = NULL;

    current = head->next;

    current->data = 4;

    printf("%d\n", current->data);

    
    Add_At_End(head, 8);
    Add_At_End(head, 9);
    free(current);
    free(head);
}