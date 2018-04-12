//this function can add nodes to front, end, or middle of the list.
//can also do it in a sorted manner

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//prototype
struct Node *addToSorted(struct Node *myList, int value);
void print(struct Node *myList);

int main()
{
    int num;

    //"head pointer" is called myList.
    //initialized to NULL so we start with an empty list
    struct Node *myList = NULL;

    printf("Enter numbers. Enter -1 to stop. \n\n");
    while(num != -1)
    {
        printf("\nEnter data for next node: ");
        scanf("%d", &num);

        if(num != -1)
            myList = addToSorted(myList, num);

        print(myList);
    }

    return 0;
}

struct Node *addToSorted(struct Node *myList, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //helper pointer
    struct Node *helper = myList;

    //if list is empty OR the newNode is smallest in list, then add to front.
    if(myList == NULL || myList->data > value)
    {
        newNode->next = myList;  //makes address of newNode = address of head pointer (myList)
        myList = newNode;  //makes head pointer (myList) point to newNode, thus making it the new first node
        return myList;  //return the new list
    }


    /*Find the spot to insert. It will be at end or middle of the list.

    while there are nodes in the list and the value of node AFTER the one that
    helper points to is < than value of new node, keep traversing.

    insertion spot found when value of node AFTER the one that helper pointer
    points to is > than value of new node, or we've reached end of list.
    */
    while(helper->next != NULL && (helper->next)->data < value)
    {
        helper = helper->next;
    }

    //helper is now pointing to node before our insertion spot (the predecessor)
    //helper->next is both the predecessor and successor?
    newNode->next = helper->next;  //point newNode to its successor
    helper->next = newNode;        //point predecessor to newNode

    return myList;
}

void print(struct Node *myList)
{
    struct Node *helper = myList;

    //traverse the list
    printf("List is: ");
    while(helper != NULL)
    {
        printf("%d ", helper->data); //print data field of the node
        helper = helper->next;       //use the "next" field of the same node to move over one.
    }
    printf("\n");

    return;
}


