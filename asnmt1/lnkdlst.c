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
    printf("current = %d\n", current->data);
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

int deleteNode(NODE *head, NODE *current)
{
    NODE *temp = head;
    //check to see if list is empty
    if ((head != NULL) && (current != NULL))
    {
        while (temp->next != current)
        {
            temp = temp->next;
        }
        temp->next = current->next;
        current->next = NULL;

        free(current);
        return 1; //1 on success
    }
    else
    {
        return 0; //0 on failure
    }
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
    // current->data = 10;
    // current->next = NULL;
    // head->next = current;

    Add_At_End(head, 1);
    Add_At_End(head, 2);
    Add_At_End(head, 10);
    Add_At_End(head, 14);

    // printf("%d\n", current->data);
    // printf("Address of current (11) %p\n", current);
    // printf("Value of current: %d\n", *current);
    printf("Finding current: %p\n", findNode(head, 2));
    printf("Finding current: %d\n", *findNode(head, 2));
    print_list(head);

    NODE *temporary;
    temporary = findNode(head, 2);
    if (temporary != NULL)
    {
        printf("Found node %d\n", temporary->data);
    }
    else
    {
        printf("Node not found\n");
    }
    printf("Success 1, failure 0: %d\n", deleteNode(head, temporary));

    print_list(head);
    free(current);
    free(head);
}

// insertbefore(head, current)
// head = current //and you use pointer from search to place value before it
//temp ==search for node
//delete node at current
