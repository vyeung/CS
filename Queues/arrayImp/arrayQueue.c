#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct queue
{
    int elements[SIZE];
    int front;
    int rear;
};

void initialize(struct queue *qPtr);
int enqueue(struct queue *qPtr, int value);
int dequeue(struct queue *qPtr);
int emptyQueue(struct queue *qPtr);
int peek(struct queue *qPtr);
int menu();
void print(struct queue qPtr);

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
            print(myQueue);
        }

        else if(selection == 2)
        {
            dequeue(&myQueue);
            print(myQueue);
        }

        else if(selection == 3)
        {
            emptyQueue(&myQueue);
            print(myQueue);
        }

        else if(selection == 4)
        {
            peek(&myQueue);
            print(myQueue);
        }

        else if(selection == 5)
            return;

        selection = menu();
    }

    return 0;
}

void initialize(struct queue *qPtr)
{
    qPtr->front = -1;
    qPtr->rear = -1;

    return;
}

int enqueue(struct queue *qPtr, int value)
{
    //check if queue is full
    if((qPtr->rear + 1) % SIZE == qPtr->front)
    {
        printf("Queue is full \n");
        return;
    }

    //if queue is empty
    if(qPtr->front == -1 && qPtr->rear == -1)
    {
        qPtr->front = 0;
        qPtr->rear = 0;
        qPtr->elements[qPtr->rear] = value;
    }

    //normal case
    else
    {
        qPtr->rear = (qPtr->rear + 1) % SIZE;
        qPtr->elements[qPtr->rear] = value;
    }

    return 1;
}

int dequeue(struct queue *qPtr)
{
    //check if queue is empty
    if(qPtr->front == -1 && qPtr->rear == -1)
    {
        printf("Queue is empty. No elements to dequeue \n");
        return;
    }

    //when there is 1 element left in queue.
    if(qPtr->front == qPtr->rear)
    {
        //mark the queue as empty now
        qPtr->front = -1;
        qPtr->rear = -1;
    }

    //normal case
    else
    {
        qPtr->front = (qPtr->front+1) % SIZE;
    }

    return 1;
}

int emptyQueue(struct queue *qPtr)
{
    qPtr->front = -1;
    qPtr->rear = -1;

    printf("Queue emptied \n");

    return;
}

int peek(struct queue *qPtr)
{
    if(qPtr->front == -1)
        printf("No front, queue is empty \n");

    else
        printf("Front of queue is: %d \n", qPtr->elements[qPtr->front]);

    return;
}

void print(struct queue qPtr)
{
    int numElements;
    int index;

    if(qPtr.front == -1 && qPtr.rear == -1)
    {
        numElements = (qPtr.rear + SIZE - qPtr.front) % SIZE;

        printf("Queue is: ");

        int i;
        for(i=0; i<numElements; i++)
        {
            index = (qPtr.front + i) % SIZE;
            printf("%d ", qPtr.elements[index]);
        }
        printf("\n");
    }

    else
    {
        numElements = (qPtr.rear + SIZE - qPtr.front) % SIZE + 1;

        printf("Queue is: ");

        int i;
        for(i=0; i<numElements; i++)
        {
            index = (qPtr.front + i) % SIZE;
            printf("%d ", qPtr.elements[index]);
        }
        printf("\n");;
    }

    return;
}

int menu()
{
    int selection;

    printf("\nEnter selection: \n");
    printf("1 - Enqueue a number \n");
    printf("2 - Dequeue a number \n");
    printf("3 - Empty queue \n");
    printf("4 - Peek what's at front \n");
    printf("5 - Quit \n");
    scanf("%d", &selection);

    return selection;
}
