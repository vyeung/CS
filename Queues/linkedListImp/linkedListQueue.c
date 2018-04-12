#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct queue
{
    struct Node *front;
    struct Node *rear;
};

//prototypes
void initialize(struct queue *qPtr);
int enqueue(struct queue *qPtr, int value);
int dequeue(struct queue *qPtr);
int isEmpty(struct queue *qPtr);
int peek(struct queue *qPtr);
void print(struct queue *qPtr);
int menu();

int main()
{
    int selection;
    int num;

    struct queue myQueue;
    initialize(&myQueue);

    selection = menu();

    while(selection != 5)
    {
        if(selection == 1)
        {
            printf("Enter a number: ");
            scanf("%d", &num);
            enqueue(&myQueue, num);
            print(&myQueue);
        }

        else if(selection == 2)
        {
            dequeue(&myQueue);
            print(&myQueue);
        }

        else if(selection == 3)
        {
            isEmpty(&myQueue);
            print(&myQueue);
        }

        else if(selection == 4)
        {
            peek(&myQueue);
            print(&myQueue);
        }

        else if(selection == 5)
            return;

        selection = menu();
    }


    return 0;
}

void initialize(struct queue *qPtr)
{
    qPtr->front = NULL;
    qPtr->rear = NULL;

    return;
}

int enqueue(struct queue *qPtr, int value)
{
    //make a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //if queue is empty
    if(qPtr->front == NULL && qPtr->rear == NULL)
    {
        //point front and rear equal to the new node
        qPtr->front = newNode;
        qPtr->rear = newNode;
        return;
    }

    //queue not empty
    else  //(front and rear != NULL)
    {
        qPtr->rear->next = newNode;  //point old "last" node to the new node
        qPtr->rear = newNode;  //update rear to be our newly created node
    }

    return 1;
}

int dequeue(struct queue *qPtr)
{
    struct Node *temp = qPtr->front;

    //if queue is empty
    if(qPtr->front == NULL)
    {
        printf("Queue is empty \n");
        return;
    }

    //if there's one element left
    if(qPtr->front == qPtr->rear )
    {
        qPtr->front = NULL;
        qPtr->rear = NULL;
    }

    //normal case
    else
        qPtr->front = qPtr->front->next;  //make front point to next node in queue

    free(temp);  //delete temp

    return;
}

int isEmpty(struct queue *qPtr)
{
    if(qPtr->front == NULL)
        printf("Queue is empty \n");

    if(qPtr->front != NULL)
        printf("Queue not empty \n");

    return;
}

int peek(struct queue *qPtr)
{
    if(qPtr->front != NULL)
        printf("Front of queue is: %d \n", qPtr->front->data);

    else
        printf("No front. Queue is empty \n");

    return;
}

void print(struct queue *qPtr)
{
    struct Node *helper = qPtr->front;

    printf("Queue is: ");
    while(helper != NULL)
    {
        printf("%d ", helper->data);
        helper = helper->next;
    }
    printf("\n");
}

int menu()
{
    int selection;

    printf("\nEnter selection: \n");
    printf("1 - Enqueue a number \n");
    printf("2 - Dequeue a number \n");
    printf("3 - Check if empty \n");
    printf("4 - Peek what's at front \n");
    printf("5 - Quit \n");
    scanf("%d", &selection);

    return selection;
}





