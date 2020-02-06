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

// int Delete_Node(NODE *head, int num)
// {
//     //1)Go to node we want to delete
//     //2)Save the node we want to delete in a temp pointer
//     //3)Set previous node's next pointer to point toh the node we wish to delete
//     //4)Delete node using the temp pointer

//     int i = 0;
//     int retval = -1;
//     NODE *current = head;
//     NODE *temp = NULL;
//     if (num == 0)
//     {
//         return head->data;
//     }
//        for (i = 0; i < num-1; i++) {
//         if (current->next == NULL) {
//             return -1;
//         }
//         current = current->next;
//     }
//     temp=current->next;
//     retval=temp->data;
//     current->next=temp->next;
//     free(temp);
//     return retval;

// }


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

    head->next->next = (NODE *)malloc(sizeof(NODE));
    head->next->next->next = NULL;

    current = head->next->next;

    current->data = 9;

    printf("%d\n", current->data);

    Add_At_End(1, head);
    Add_At_End(2, head);
    Add_At_End(3, head);
    free(current);
    free(head);
}