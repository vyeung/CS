#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//prototypes
struct Node *addToEnd(struct Node *myList, int value);
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
            myList = addToEnd(myList, num);

        print(myList);
    }

    return 0;
}

struct Node *addToEnd(struct Node *myList, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //make helper pointer since we need to traverse
    struct Node *helper = myList;

    //if list is empty, newNode becomes first and only node
    if(myList == NULL)
        return newNode;

    //list is not empty. could just write while loop by itself
    else
    {
        while(helper->next != NULL)  //go to last node
            helper = helper->next;

        helper->next = newNode;  //point last node to new node
    }

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


