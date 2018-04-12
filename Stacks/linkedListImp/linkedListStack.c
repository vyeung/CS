#include <stdio.h>
#include <stdlib.h>

//basically the same as Node struct
//don't specify a top because top will always be the first node
struct stack
{
    int data;
    struct stack *next;
};

//prototypes
void initialize(struct stack **head);
int isEmpty(struct stack *head);
int push(struct stack **head, int value);
struct stack *pop(struct stack **head);
int top(struct stack *head);
void print(struct stack *head);
int menu();

int main()
{
    int selection;
    int num;

    struct stack *myStack;
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
            top(myStack);


        else if(selection == 4)
            return;

        selection = menu();
    }

    return 0;
}

//set head pointer to NULL, so stack starts out empty
void initialize(struct stack **head)
{
    *head = NULL;

    return;
}

//check is stack is empty or not
int isEmpty(struct stack *head)
{
    if(head == NULL)
    {
        printf("Stack is empty. \n");
        return 1;
    }

    else
        return 0;
}

int push(struct stack **head, int value)
{
    struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    return 1;  //push was successful
}

struct stack *pop(struct stack **head)
{
    struct stack *temp = *head;  //make temp point to head pointer

    if(*head == NULL)
    {
        printf("No element to pop. \n");
        return;
    }

    //helper = *head;
    *head = (*head)->next;

    free(temp);

}

int top(struct stack *head)
{
    if(head == NULL)
    {
        printf("Stack is empty. \n");
        return;
    }

    if(head != NULL)
    {
        printf("Top is: %d \n", head->data);
        return;
    }
}

void print(struct stack *head)
{
    struct stack *helper = head;

    printf("Stack is: ");
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

    printf("Enter selection: \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Top \n");
    printf("4 - Quit \n");
    scanf("%d", &selection);

    return selection;
}





