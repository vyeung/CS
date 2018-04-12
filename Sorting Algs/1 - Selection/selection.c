#include <stdio.h>

#define SIZE 10

void selectionSort(int array[SIZE]);

int main()
{
    int array[SIZE] = {4,3,9,2,1,5,8,6,0,7};
    int i,j;

    printf("Before: ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    selectionSort(array);

    printf("\nAfter:  ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    return 0;
}

void selectionSort(int array[SIZE])
{
    int i,j, temp;

    for(i=0; i<SIZE; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return;
}

