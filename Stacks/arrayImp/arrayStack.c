#include <stdio.h>

#define SIZE 10

struct stack
{
    int items[SIZE];
    int top;
};

//prototypes
void initialize(struct stack *stackPtr);
int isEmpty(struct stack *stackPtr);
int isFull(struct stack *stackPtr);
int push(struct stack *stackPtr, int value);
int pop(struct stack *stackPtr);
int top(struct stack *stackPtr);
void print(struct stack stackPtr);
int menu();

int main()
{
    int selection;
    int num;

    struct stack myStack;
    initialize(&myStack);

    selection = menu();

    while(selection != 4)
    {
        if(selection == 1)
        {
            printf("Enter a number: ");
            scanf("%d", &num);
            push(&myStack, num);
            print(myStack);
        }

        else if(selection == 2)
        {
            pop(&myStack);
            print(myStack);
        }

        else if(selection == 3)
            top(&myStack);


        else if(selection == 4)
            return;

        selection = menu();
    }

    return 0;
}

//initializes stack to be empty
void initialize(struct stack *stackPtr)
{
    stackPtr->top = -1;  //index -1 represents empty stack
                         //index 0 represents first element in stack

    return;
}

//checks if stack is empty
int isEmpty(struct stack *stackPtr)
{
    return stackPtr->top == -1;
}

//checks if stack is full
int isFull(struct stack *stackPtr)
{
    return stackPtr->top == SIZE-1;  //if stack is full, top will be at index size-1
}

int push(struct stack *stackPtr, int value)
{
    if(isFull(stackPtr))
    {
        printf("Stack is full. \n");
        return 0;
    }

    stackPtr->items[stackPtr->top+1] = value;  //copy value into next location of stack
    stackPtr->top++;  //increment top
    return 1;  //push was successful
}

int pop(struct stack *stackPtr)
{
    if(isEmpty(stackPtr))
    {
        printf("No elements to pop. \n");
        return -1;
    }

    return stackPtr->top--;
}

int top(struct stack *stackPtr)
{
    if(isEmpty(stackPtr))
    {
        printf("No elements in stack. \n");
        return -1;
    }

    printf("Top of stack is: %d \n", stackPtr->items[stackPtr->top]);

    return stackPtr->items[stackPtr->top];
}

void print(struct stack myStack)
{
    printf("Stack is: ");

    int i;
    for(i=0; i < myStack.top+1; i++)
    {
        printf("%d ", myStack.items[i]);
    }
    printf("\n");

    return;
}

int menu()
{
   int selection;

    printf("Enter selection: \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Top \n");
    printf("4 - Quit \n");
    scanf("%d", &selection);

    return selection;
}





