#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;

} NODE;

void Add_At_End(NODE *head, int num)
{
    NODE *nodeNew, *save;

    nodeNew = (NODE *)malloc(sizeof(NODE));
    nodeNew->data = num;  //sets up new node and adds correct data
    nodeNew->next = NULL; //creates next pointer which goes to NULL

    save = head; //temporary pointer used to put this new node at the end of the list

    while (save->next != NULL) //moves to the end of the list
    {
        save = save->next;
        // printf("current here is: %d\n", *save);
    }
    save->next = nodeNew;          //adds node to the end of the list
    printf("%d\n", nodeNew->data); //prints value that was added

    // NODE *current = head; ///This way of doing it kept moving the head pointer up
    // printf("head here is: %d\n", *head);
    // while (current->next != NULL)
    // {
    //     current = current->next;
    //     printf("current here is: %d\n", *current);

    // } //check to make sure at the end
    // // printf("current = %d\n", current->data);
    // current->next = (NODE *)malloc(sizeof(NODE));
    // current->data = num;
    // current->next->next = NULL;

    // printf("%d\n", current->data);

    // printf("head at end of add is: %d\n", *head);
}

void print_list(NODE *head) //prints one forward
{
    NODE *temp;
    temp = head;
    printf("Print function is printing list: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(int argc, char *argv[])
{
    NODE *head, *current = NULL;

    head = (NODE *)malloc(sizeof(NODE));
    head->data = 3;
    head->next = NULL;
    printf("%d\n", head->data);

    Add_At_End(head, 1);
    Add_At_End(head, 2);
    Add_At_End(head, 10);
    Add_At_End(head, 14);

    print_list(head);
    free(head);
}
