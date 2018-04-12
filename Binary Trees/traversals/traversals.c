#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    char data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(char data);
struct treeNode *Insert(struct treeNode *rootPtr, char data);
void preorder(struct treeNode *rootPtr);
void inorder(struct treeNode *rootPtr);
void postorder(struct treeNode *rootPtr);

//can use a queue to implement breadthFirst

int main()
{
    struct treeNode *rootPtr;
    rootPtr = NULL;

    char data;
    FILE *ifp;
    ifp = fopen("treeValues.txt", "r");

    int i;
    for(i=0; i<11; i++)
    {
        fscanf(ifp, "%c", &data);
        rootPtr = Insert(rootPtr, data);
    }
/*
    rootPtr = Insert(rootPtr, 'F');
    rootPtr = Insert(rootPtr, 'D');
    rootPtr = Insert(rootPtr, 'J');
    rootPtr = Insert(rootPtr, 'B');
    rootPtr = Insert(rootPtr, 'E');
    rootPtr = Insert(rootPtr, 'G');
    rootPtr = Insert(rootPtr, 'K');
    rootPtr = Insert(rootPtr, 'A');
    rootPtr = Insert(rootPtr, 'C');
    rootPtr = Insert(rootPtr, 'I');
    rootPtr = Insert(rootPtr, 'H');
*/
    printf("Preorder:  ");
    preorder(rootPtr);

    printf("\nInorder:   ");
    inorder(rootPtr);

    printf("\nPostorder: ");
    postorder(rootPtr);

    printf("\n");

    return 0;
}

struct treeNode *createNode(char data)
{
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct treeNode *Insert(struct treeNode *rootPtr, char data)
{
    if(rootPtr == NULL)  //if tree is empty
        rootPtr = createNode(data);

    //if data is < root, insert in left subtree recursively
    else if(data <= rootPtr->data)
        rootPtr->left = Insert(rootPtr->left, data);

    //if data is > root, insert in right subtree recursively
    else
        rootPtr->right = Insert(rootPtr->right, data);

    return rootPtr;  //putting statement just here is sufficient
}

void preorder(struct treeNode *rootPtr)
{
    if(rootPtr != NULL)
    {
        printf("%c ", rootPtr->data);
        preorder(rootPtr->left);
        preorder(rootPtr->right);
    }

    return;
}

void inorder(struct treeNode *rootPtr)
{
    if(rootPtr != NULL)
    {
        inorder(rootPtr->left);
        printf("%c ", rootPtr->data);
        inorder(rootPtr->right);
    }

    return;
}

void postorder(struct treeNode *rootPtr)
{
    if(rootPtr != NULL)
    {
        postorder(rootPtr->left);
        postorder(rootPtr->right);
        printf("%c ", rootPtr->data);
    }

    return;
}

