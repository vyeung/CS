#include <stdio.h>
#include <stdlib.h>  //for malloc
#include <stdbool.h>  //for boolean

#define SIZE 6

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

//Notice not using global variables in this example

/*
Deleting a node requires all these functions:
1: find the node to delete
2: find the parent of that node to be deleted
3: find minVal in the tree
4: find maxVal in the tree
5: determine if node is a leaf
6: determine if node only has a left child
7: determine if node only has a right child
8: the delete function itself
*/


struct treeNode* createNode(int data)
{
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//insert nodes so that tree is a BST
struct treeNode* Insert(struct treeNode *rootPtr, int data)
{
    //if tree is empty
    if(rootPtr == NULL)
        rootPtr = createNode(data);

    //if data is < root, insert in left subtree recursively
    else if(data <= rootPtr->data)
        rootPtr->left = Insert(rootPtr->left, data);

    //if data is > root, insert in right subtree recursively
    else
        rootPtr->right = Insert(rootPtr->right, data);

    return rootPtr;  //return rootPtr of updated tree
}

//search the tree for a value
bool Search(struct treeNode *rootPtr, int data)
{
    //if tree is empty
    if(rootPtr == NULL)
        return false;

    //check if root is the searched for node
    if(rootPtr->data == data)
        return true;

    //recursively search to the left
    if(data < rootPtr->data)
        return Search(rootPtr->left, data);

    //recursively search to the right
    else
        return Search(rootPtr->right, data);
}

//finds min value in the tree.
//min value in the BST will be the farthest left element
int findMin(struct treeNode *rootPtr)
{
    //Iterative Solution
    /*
    if(rootPtr == NULL)
        printf("Tree is empty. \n");

    while(rootPtr->left != NULL)
        rootPtr = rootPtr->left;

    return rootPtr->data;
    */


    //Recursive Solution, could rewrite like findMax function

    //if tree is empty; base case
    if(rootPtr == NULL)
        printf("Tree is empty. \n");

    //farthest left element will point to NULL
    if(rootPtr->left == NULL)
        return rootPtr->data;

    return findMin(rootPtr->left);
}

//finds max value in the tree
//max value in the BST will be the farthest right element
int findMax(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        printf("Tree is empty. \n");

    if(rootPtr != NULL)
    {
        if(rootPtr->right == NULL)
            return rootPtr->data;

        findMax(rootPtr->right);
    }

    //note: if the root node is the largest node, then there will be no rightSubTree
}

//height = length of the longest path from root node to a leaf node
//if longest path is # of edges, do return -1
//if longest path is # of nodes, do return 0
int findHeight(struct treeNode *rootPtr)
{
    int leftHeight;
    int rightHeight;

    if(rootPtr == NULL)  //base case
        return 0;

    leftHeight = findHeight(rootPtr->left);
    rightHeight = findHeight(rootPtr->right);

    //leftSubTree's height is longer
    if(leftHeight > rightHeight)
        return leftHeight + 1;

    //rightSubTree's height is longer
    else
        return rightHeight + 1;
}

//sums together the value of each node in the tree
int sum(struct treeNode *rootPtr)
{
    if(rootPtr == NULL) //base case
        return 0;

    //rootPtr != NULL
    else
        return rootPtr->data + sum(rootPtr->left) + sum(rootPtr->right);
        //adds root + values in leftSubTree + values in rightSubTree
}

//counts the number of nodes in the tree and returns that number.
int numNodes(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return 0;

    if(rootPtr != NULL)
    {
        //root counts as 1, then # in left subtree and # in right subtree
        return 1 + numNodes(rootPtr->left) + numNodes(rootPtr->right);
    }
}

//counts the number of leaf nodes in the tree and returns that number.
int numLeaves(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return 0;

    if(rootPtr != NULL)
    {
        //root node by itself is also considered a leaf node
        if(rootPtr->left == NULL && rootPtr->right == NULL)
            return 1;

        else
            return numLeaves(rootPtr->left) + numLeaves(rootPtr->right);
    }
}

//prints all values that are greater >= to value passed in
void aboveThreshold(struct treeNode *rootPtr, int value)
{
    if(rootPtr == NULL)
        return;

    if(rootPtr != NULL)
    {
        if(rootPtr->data >= value)
            printf("%d ", rootPtr->data);

        aboveThreshold(rootPtr->left, value);  //check left subtree
        aboveThreshold(rootPtr->right, value); //check right subtree
    }

    return;
}

//prints all the even nodes in the tree
void printEven(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return;

    if(rootPtr != NULL)
    {
        if((rootPtr->data)%2 == 0)
            printf("%d ", rootPtr->data);

        printEven(rootPtr->left);
        printEven(rootPtr->right);
    }
}

//prints all the odd nodes, while also being in ASCENDING order (1,4,7,...)
//to get ascending order, do inorder traversal
void printOddAsc(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return;

    if(rootPtr != NULL)
    {
        printOddAsc(rootPtr->left);

        if((rootPtr->data)%2 != 0)
            printf("%d ", rootPtr->data);

        printOddAsc(rootPtr->right);
    }
}

//finds number of nodes with 1 child and returns number
int oneChild(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return 0;

    if(rootPtr != NULL)
    {
        //the child is on the right side of node
        if(rootPtr->left == NULL && rootPtr->right != NULL)
            return 1 + oneChild(rootPtr->right);

        //the child is on the left side of node
        else if(rootPtr->left != NULL && rootPtr->right == NULL)
            return 1 + oneChild(rootPtr->left);

        //adds number of nodes w/ 1 child in leftSubTree and rightSubTree
        else
            return oneChild(rootPtr->left) + oneChild(rootPtr->right);
    }
}

//finds number of nodes with 2 children and returns number
int twoChild(struct treeNode *rootPtr)
{
    if(rootPtr == NULL)
        return 0;

    if(rootPtr != NULL)
    {
        if(rootPtr->left != NULL && rootPtr->right != NULL)
            return 1 + oneChild(rootPtr->left) + oneChild(rootPtr->right);
    }
}

int menu()
{
    int selection;

    printf("1 - Min value \n");
    printf("2 - Max value \n");
    printf("3 - Height of tree \n");
    printf("4 - Sum of tree values \n");
    printf("5 - Search for value \n");
    printf("6 - Values above threshold \n");
    printf("7 - Number of nodes \n");
    printf("8 - Number of leaf nodes \n");
    printf("9 - Print even nodes \n");
    printf("10 - Print ascending odd nodes \n");
    printf("11 - Number of nodes with 1 child \n");
    printf("12 - Number of nodes with 2 child \n");
    printf("13 - Quit \n");
    scanf("%d", &selection);

    return selection;
}

int main()
{
    int data, selection;
    int num, num1;

    struct treeNode *rootPtr;  //store address of root treeNode
    rootPtr = NULL;  //first set tree as empty

    FILE *ifp;
    ifp = fopen("treeValues.txt", "r");

    int i;
    for(i=0; i<SIZE; i++)
    {
        fscanf(ifp, "%d", &data);
        rootPtr = Insert(rootPtr, data);
    }

    selection = menu();
    while(selection != 13)
    {
        if(selection == 1)
            printf("Min value is %d. \n", findMin(rootPtr));

        if(selection == 2)
            printf("Max value is %d. \n", findMax(rootPtr));

        if(selection == 3)
            printf("Height of tree is %d. \n", findHeight(rootPtr));

        if(selection == 4)
            printf("Sum of tree values is %d. \n", sum(rootPtr));

        if(selection == 5)
        {
            printf("Enter value: ");
            scanf("%d", &num);

            if(Search(rootPtr, num) == true)
                printf("Value found \n");
            else
                printf("Value not found \n");
        }

        if(selection == 6)
        {
            printf("Enter threshold value: ");
            scanf("%d", &num1);
            aboveThreshold(rootPtr, num1);
            printf("\n");
        }

        if(selection == 7)
            printf("Number of nodes is %d \n", numNodes(rootPtr));

        if(selection == 8)
            printf("Number of leaf nodes is %d \n", numLeaves(rootPtr));

        if(selection == 9)
        {
            printf("Even nodes: ");
            printEven(rootPtr);
            printf("\n");
        }

        if(selection == 10)
        {
            printf("Odd nodes ascending: ");
            printOddAsc(rootPtr);
            printf("\n");
        }

        if(selection == 11)
            printf("Number of nodes with 1 child: %d", oneChild(rootPtr));

        if(selection == 12)
            printf("Number of nodes with 2 child: %d", twoChild(rootPtr));

        if(selection == 13)
            return;

        printf("\n");
        selection = menu();
    }

    return 0;
}
