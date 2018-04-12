#include <stdio.h>

#define SIZE 10

void bubbleSort(int array[SIZE]);

int main()
{
    int array[SIZE] = {4,3,9,2,1,5,8,6,0,7};
    int i;

    printf("Before: ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    bubbleSort(array);

    printf("\nAfter:  ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    return 0;
}

void bubbleSort(int array[SIZE])
{
    int i,j, temp;

    for(i=0; i<SIZE-1; i++)
    {
        for(j=0; j<SIZE-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    return;
}

