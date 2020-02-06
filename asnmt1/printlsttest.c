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
    // printf("current = %d\n", current->data);
    current->next = (NODE *)malloc(sizeof(NODE));
    current->data = num;
    current->next->next = NULL;

    printf("%d\n", current->data);
}

void print_list(NODE *head)//prints one forward
{
    NODE *temp;
    temp = head;
    printf("Print function is printing list: \n");
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

}

int main(int argc, char *argv[])
{
    NODE *head, *current;

    head = (NODE *)malloc(sizeof(NODE));
    head->data = 3;
    head->next = NULL;
    printf("%d\n", head->data);
    current = (NODE *)malloc(sizeof(NODE));

    Add_At_End(head, 1);
    Add_At_End(head, 2);
    Add_At_End(head, 10);
    Add_At_End(head, 14);

    print_list(head);
    free(current);
    free(head);
}
