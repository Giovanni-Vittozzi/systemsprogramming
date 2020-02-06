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
    current->next = (NODE *)malloc(sizeof(NODE));
    current->data = num;
    current->next->next = NULL;

    printf("%d\n", current->data);
}

NODE *findNode(NODE *head, int value)
{
    NODE *current = NULL;
    current = head;
    int found = 0;
    // printf("Value: %d\n", value);
    if (head != NULL)
    {
        while (current->next != NULL)
        {
            // printf("While loop of found \n");
            // printf("current->data %d\n", current->data);

            if (current->data == value)
            {
                found = 1;
                // printf("Found %d", found);
                break;
            }
            current = current->next;
        }
        if ((current->next == NULL) && (found == 0))
        {
            printf("Nope\n");
            current = NULL;
        }
    }
    return current;
}

int main(int argc, char *argv[])
{
    NODE *head, *current;

    head = (NODE *)malloc(sizeof(NODE));
    head->data = 3;
    head->next = NULL;
    printf("%d\n", head->data);

    current = (NODE *)malloc(sizeof(NODE));
    // current->data = 10;
    // current->next = NULL;
    // head->next = current;
    
    
    Add_At_End(head,1);
    Add_At_End(head, 2);
    Add_At_End(head, 10);
    Add_At_End(head, 14);


    // printf("%d\n", current->data);
    // printf("Address of current (11) %p\n", current);
    // printf("Value of current: %d\n", *current);
    printf("Finding current: %p\n", findNode(head, 1));
    printf("Finding current: %p\n", findNode(head, 2));
    printf("Finding current: %d\n", *findNode(head, 1));
    printf("Finding current: %d\n", *findNode(head, 2));
    printf("Finding current: %p\n", findNode(head, 10));
    printf("Finding current: %p\n", findNode(head, 14));
    printf("Finding current: %d\n", *findNode(head, 10));
    printf("Finding current: %d\n", *findNode(head, 14));

    free(current);
    free(head);
}

// insertbefore(head, current)
// head = current //and you use pointer from search to place value before it
//temp ==search for node
//delete node at current
