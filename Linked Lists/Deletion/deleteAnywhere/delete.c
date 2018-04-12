//the delete function can delete from front, end, or middle

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertNode(struct Node *myList, int value);
struct Node *deleteNode(struct Node *myList, int number);
void print(struct Node *myList);

int main()
{
    int numNodes;
    int number;
    int deleteValue;

    struct Node *myList = NULL; //start with empty list

    FILE *ifp;
    ifp = fopen("linkedList.txt", "r");
    fscanf(ifp, "%d", &numNodes);

    int i;
    for(i=0; i<numNodes; i++)
    {
        fscanf(ifp, "%d", &number);
        myList = insertNode(myList, number);
    }

    print(myList);

    printf("\nEnter node value to delete: ");
    scanf("%d", &deleteValue);
    myList = deleteNode(myList, deleteValue);

    print(myList);

    return 0;
}

//does an add to end approach
struct Node *insertNode(struct Node *myList, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    struct Node *helper = myList;  //make helper pointer since we need to traverse

    if(myList == NULL)  //if list is empty, newNode becomes first and only node
        return newNode;

    while(helper->next != NULL)  //go to last node
    {
        helper = helper->next;
    }
    helper->next = newNode;  //point last node to new node

    return myList;
}

struct Node *deleteNode(struct Node *myList, int target)
{
    struct Node *helper = myList; //helper pointer
    struct Node *node2delete;  //used if we're deleting a node in middle or end

    if(helper != NULL)  //checks if list is empty or not
    {
        if(helper->data == target)  //only used if we're deleting first node
        {
            myList = helper->next;  //make head pointer point to second node OR NULL if list had 1 node
            free(helper);           //free deleted node
            return myList;
        }

        while(helper->next != NULL)  //used if we're deleting a node in middle or end
        {
            //looks at data value of node that's right after the one helper points to
            //Ex: if helper points to node 5, helper->next->data looks at data value of node 6
            if(helper->next->data == target)
            {
                //Lets say we have nodes 5,6,7.
                //helper points to 5. helper->next points to 6. helper->next->next points to 7
                //we want to delete node 6.

                node2delete = helper->next;  //save address in "next" of 6 into node2delete
                helper->next = helper->next->next;  //save address of 7 into "next" of 5. how??
                free(node2delete);  //free deleted node
                return myList;

                /*
                helper->next = helper->next->next; is same as
                helper->next = node2delete->next;
                */
            }
            helper = helper->next;
        }
    }

    return myList;  //executes if list is empty or node isn't found
}

void print(struct Node *myList)
{
    struct Node *helper = myList;

    //traverse the list
    printf("List is: ");
    while(helper != NULL)
    {
        printf("%d ", helper->data); //print data value of the node
        helper = helper->next;       //use the "next" field of the same node to move over one.
    }
    printf("\n");

    return;
}





