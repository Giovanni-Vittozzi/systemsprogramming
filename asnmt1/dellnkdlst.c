///////Giovanni Vittozzi
///////Submission date:
///////Due date: 2/21/2020

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data; //each node has data and a next pointer
    struct Node *next;

} NODE;

// print node pass reference to node to be printed like print n times
void Add_At_End(NODE *head, int num);                  // function adds new node at end of linked list
NODE *Insert_Node(NODE *head, int num, int putbefore); // function adds new node at end of linked list
NODE *findNode(NODE *head, int value);                 //function finds nodebased on given value and returns address of that node
NODE *deleteNode(NODE *head, int data);                //function deletes node based on given value and uses findeNode to do so
void print_list(NODE *head);                           //function prints the entire list
void delete_list(NODE *head);

int main(int argc, char *argv[])
{
    NODE *head;

    head = (NODE *)malloc(sizeof(NODE)); //creating first node
    head->data = 0;                      //data for the first node
    head->next = NULL;                   //and pointer to null because there aren't any other nodes for now
    printf("%d\n", head->data);

    Add_At_End(head, 1);
    Add_At_End(head, 2);
    Add_At_End(head, 3);
    Add_At_End(head, 4);
    Add_At_End(head, 5);
    Add_At_End(head, 6);
    print_list(head);

    head = deleteNode(head, 3);
    print_list(head);

    delete_list(head);
    // print_list(head);
    free(head);
}

//CHALLENGE: delete list should be recursive

void Add_At_End(NODE *head, int num)
{
    printf("Adding %d to end of list\n", num);
    NODE *nodeNew, *save; //create the new node and a temporary node

    nodeNew = (NODE *)malloc(sizeof(NODE));
    nodeNew->data = num;  //sets up new node and adds correct data
    nodeNew->next = NULL; //creates next pointer which goes to NULL

    save = head; //temporary pointer to head, used to put this new node at the end of the list

    while (save->next != NULL) //moves to the end of the list
    {
        save = save->next; //move this temp pointer to the next Node in the list
        // printf("current here is: %d\n", *save);
    }
    save->next = nodeNew;                      //points the last Node in the list to this new last node
    printf("Node added: %d\n", nodeNew->data); //prints value that was added
}

NODE *Insert_Node(NODE *head, int num, int putbefore)
{
    printf("Insert_Node is inserting %d before %d\n", num, putbefore);
    // NODE *tempy = NULL; //temporary pointer to head
    NODE *tempy = head; //temporary pointer to head
    NODE *newNode;      //new node to be added before our value
    newNode = (NODE *)malloc(sizeof(NODE));

    NODE *addr_putbefore = findNode(head, putbefore);

    if (head != NULL) //checks if list is empty
    {
        if (head->data == putbefore)
        {
            newNode->data = num;
            newNode->next = tempy;
            head = newNode;
            return head;
        }
        else
        {
            while (tempy->data != putbefore) //loop to move pointer before the value we're searching for
            {
                // printf("tempy: %d\n", *tempy); //temporary print statement for debugging
                if (tempy->next == addr_putbefore)
                {
                    // tempy2 = tempy->next;
                    // printf("tempy2: %d\n", *tempy2); //temporary print statement for debugging

                    break;
                }
                tempy = tempy->next; //
            }
            tempy->next = newNode;
            newNode->data = num;
            // printf("addr_putbefore is: %d\n", *addr_putbefore); //temporary debugging statement
            newNode->next = addr_putbefore;
            return head;
        }
        printf("Node inserted\n");
    }
}

NODE *findNode(NODE *head, int value) //find function returns pointer to the given node value
{
    NODE *current = NULL; //current pointer that we're initializing to 0
    current = head;       //this current pointer starts at head
    int found = 0;
    // printf("Value: %d\n", value);
    if (head != NULL) //checks if list is empty
    {
        while (current != NULL) //moves through the linked list to the end
        //NOTE: did this instead of doing current->next != NULL (this doesn't do the last element)
        {

            if (current->data == value) //if the data at current node is equal to the searched for value, return 1
            {
                found = 1;
                break;
            }
            current = current->next; //if it's not equal then move to the next node
        }
        if ((current->next == NULL) && (found == 0)) //if the current Node is Null (at the end) and didnt find anything
        {
            printf("No such node found\n");
            current = NULL;
        }
    }
    return current; //return the found node
}

NODE *deleteNode(NODE *head, int value)
{
    NODE *current = head;       //pointer to head
    if (current->data == value) //if the value that we want to delete is head
    {
        printf("Deleting head %d from the list\n", value);
        head = current->next; //move the head forward
        printf("head here is %d\n", *head);
        current->next = NULL; //Delete the old head
        free(current);        //pretty sure I have to do this here
        return head;          //return the new head
    }
    else //if we arent deleting the head
    {
        printf("Deleting %d from the list\n", value);
        NODE *foundNode;
        foundNode = findNode(head, value);
        if (foundNode != NULL)
        {
            printf("Found node %d\n", foundNode->data);
        }
        else
        {
            printf("Node not found\n");
        }

        NODE *temp = head;
        //check to see if list is empty
        if ((head != NULL) && (foundNode != NULL))
        {
            while (temp->next != foundNode)
            {
                temp = temp->next;
            }
            temp->next = foundNode->next;
            foundNode->next = NULL;
            printf("Node %d deleted\n", value);

            free(foundNode);
            return head;
            //return 1; //1 on success
            //return ;//head? idk
        }
        else
        {
            return head;
            //return ;//head? idk
            // return 0; //0 on failure
        }
    }
}

void print_list(NODE *head)
{
    NODE *temp;  //temporary node
    temp = head; //temporary node points to head
    printf("Print function is printing list: \n");
    while (temp != NULL) //starting at head, while the list isnt empty; or later on why the list isn't yet at the end
    {
        printf("%d\n", temp->data); //print the data at that node
        temp = temp->next;          //move the pointer forward
    }
}

// NODE *delete_list(NODE *head)
// {
//     printf("Deleting List!!!\n");
//     NODE *temp = head;
//     printf("temp predelete: %d\n", temp->data);
//     if (temp == NULL)
//     {
//         printf("Nullllllll");
//         return temp;
//     }
//     else
//     {
//         printf("head in dellist is %d\n", temp->data);
//         delete_list(temp->next);

//         free(temp);
//         return head;
//     }
// }

void delete_list(NODE* head) 
{ 
    if (head == NULL) 
        return; 
    delete_list(head->next);  
    free(head); 
} 

//OLD DELETE VERSION

// void delete_list(NODE *head)
// {
//     printf("Deleting List\n");
//     NODE *temp = head;
//     if (temp != NULL)
//     {
//         printf("temp predelete: %d\n", temp->data);
//         temp = deleteNode(temp, temp->data);
//         temp = temp->next;
//         printf("head in dellist is %d\n", temp->data);
//         delete_list(temp);
//     }
//     else
//     {
//         printf("Nell else");
//         free(temp);
//         return head;
//     }
// }