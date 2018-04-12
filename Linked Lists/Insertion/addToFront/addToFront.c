#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//prototype
struct Node *addToFront(struct Node *myList, int value);
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
            myList = addToFront(myList, num);

        print(myList);
    }

    return 0;
}

struct Node *addToFront(struct Node *myList, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //if list is empty, make head pointer (myList) point to new node.
    if(myList == NULL)
        myList = newNode;

    //list is not empty
    else
    {
        newNode->next = myList;  //makes address of newNode = address of head pointer (myList)
        myList = newNode;        //makes head pointer (myList) point to new node
    }

    return myList;
}

void print(struct Node *myList)
{
    struct Node *helper;
    helper = myList;

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

