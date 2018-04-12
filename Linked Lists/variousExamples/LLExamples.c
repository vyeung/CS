

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertNode(struct Node *front, int value);
struct Node *getNumOdd(struct Node *front);
struct Node *deleteLast(struct Node *front);
struct Node *doubleList(struct Node *front);
struct Node *swapEvery2(struct Node *front);
struct Node *reverseList(struct Node *front);
void printReverse(struct Node *front);
int aboveThreshold(struct Node *front, int limit);
int inOrder(struct Node *front);
void print(struct Node *front);
int menu();

int main()
{
    int numNodes, data;
    int num;
    int selection;

    struct Node *front = NULL; //start with empty list
    struct Node *temp;

    FILE *ifp;
    ifp = fopen("linkedList.txt", "r");
    fscanf(ifp, "%d", &numNodes);

    int i;
    for(i=0; i<numNodes; i++)
    {
        fscanf(ifp, "%d", &data);
        front = insertNode(front, data);
    }

    selection = menu();
    while(selection != 10)
    {
        print(front);

        if(selection == 1)
        {
            printf("List is: ");
            printReverse(front);
        }

        if(selection == 2)
            print(reverseList(front));

        if(selection == 3)
        {
            temp = getNumOdd(front);
            print(temp);
            //2 lines same as print(getNumOdd(front))
        }

        if(selection == 4)
            printf("Numbers above limit: %d", aboveThreshold(front,5));

        if(selection == 5)
            print(deleteLast(front));

        if(selection == 6)
        {
            if(inOrder(front) == 1)
                printf("Yes \n");

            else
                printf("No \n");
        }

        if(selection == 7)
            print(doubleList(front));

        if(selection == 8)
            print(swapEvery2(front));


        printf("\n\n");
        selection = menu();
    }

    return 0;
}

//does an add to end approach
struct Node *insertNode(struct Node *front, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    struct Node *helper = front;  //make helper pointer since we need to traverse

    if(front == NULL)  //if list is empty, newNode becomes first and only node
        return newNode;

    while(helper->next != NULL)  //go to last node
    {
        helper = helper->next;
    }
    helper->next = newNode;  //point last node to new node

    return front;
}

//counts number of odd values in list.
//then, inserts a new node at front to indicate number of odd values.
//finally, returns a pointer to updated list.
struct Node *getNumOdd(struct Node *front)
{
    struct Node *helper = front;
    int count = 0;

    while(helper != NULL)
    {
        if((helper->data)%2 != 0)
            count++;

        helper = helper->next;
    }

    helper = malloc(sizeof(struct Node));  //don't need to typecast (struct Node*)
    helper->data = count;
    helper->next = front;

    return helper;
}

//deletes last node in list
struct Node *deleteLast(struct Node *front)
{
    struct Node *helper = front;

    if(front == NULL)  //if list is empty
        return NULL;

    if(front->next == NULL)  //if list has 1 node left
    {
        free(front->next);
        return NULL;
    }

    while(helper != NULL)
    {
        if(helper->next->next == NULL)  //go to second to last node
        {
            free(helper->next->next);
            helper->next = NULL;
            return front;
        }

        helper = helper->next;
    }
    return front;

/*
    while(helper->next->next != NULL)
    {
        helper = helper->next;
    }

    free(helper->next->next);
    helper->next = NULL;

    return front;
*/
}

//takes a list and makes a duplicate of each node
//Ex: a,b,c -> a,a,b,b,c,c
struct Node *doubleList(struct Node *front)
{
    struct Node *helper = front;

    if(front == NULL)  //if list is empty
        return NULL;

    while(helper->next != NULL)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = helper->data;
        newNode->next = helper->next;
        helper->next = newNode;

        helper = helper->next->next;

        //if the list has an odd number of nodes
        if(helper->next == NULL)
        {
            struct Node *newNode = malloc(sizeof(struct Node));
            newNode->data = helper->data;
            newNode->next = helper->next;
            helper->next = newNode;
            break;
        }
    }

    return front;
}

//very famous linked list question
struct Node *reverseList(struct Node *front)
{
    struct Node *current = front;  //current starts at front
    struct Node *previous = NULL;
    struct Node *next;

    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    front = previous;

    return front;
}

//we can use recursion
void printReverse(struct Node *front)
{
    if(front == NULL)
        return;

    if(front != NULL)
        printReverse(front->next);  //go to end of list

    printf("%d ", front->data);

    return;
}

//doesn't work
struct Node *swapEvery2(struct Node *front)
{
    struct Node *helper = front;
    struct Node *helper2 = front->next;

    if(front == NULL)
        return NULL;

    int count = 1;
    while(helper->next != NULL)
    {
        if(count = 1)
        {
            front = helper2;
            helper->next = helper->next->next;
            helper2->next = helper;
            count++;
        }

        else
        {
            helper->next = helper->next->next;
            helper2->next = helper2->next->next;
            //helper2->next = helper2;
        }

        helper = helper->next;
        helper2 = helper2->next;
    }

    return front;
}


//uses recursion
//returns the number of values that are strictly greater than limit
int aboveThreshold(struct Node *front, int limit)
{
    if(front == NULL)
        return;

    if(front != NULL)
    {
        if(front->data > limit)
            return 1 + aboveThreshold(front->next, limit); //count and move to next

        aboveThreshold(front->next, limit);  //move to next
    }
}

//determines if list is in order from smallest to largest
//return 1 if yes, return 0 if no
int inOrder(struct Node *front)
{
    struct Node *helper = front;

    if(front == NULL)
        return 1;

    //need helper->next in while to compare current node with its next node
    while(helper->next != NULL)
    {
        if(helper->data > helper->next->data) //compare 1 pair at a time
            return 0;

        helper = helper->next;
    }

    return 1;
}


void print(struct Node *front)
{
    struct Node *helper = front;

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

int menu()
{
    int selection;
    printf("1 - Print list in reverse \n");
    printf("2 - Reverse the list \n");
    printf("3 - Number of odd values \n");
    printf("4 - Above threshold \n");
    printf("5 - Delete last node \n");
    printf("6 - Is in order? \n");
    printf("7 - Double List \n");
    printf("8 - Swap Every 2 \n");
    printf("10 - Quit \n");
    scanf("%d", &selection);

    return selection;
}





