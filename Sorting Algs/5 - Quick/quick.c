#include<stdio.h>

#define SIZE 10

void quickSort(int array[SIZE],int first,int last);

int main(){

    int array[SIZE] = {4,3,9,2,1,5,8,6,0,7};
    int temp;
    int i,j;

    printf("Before: ");
    for(i=0; i<10; i++)
        printf("%d ", array[i]);

    quickSort(array, 0, SIZE-1);

    printf("\nAfter:  ");
    for(i=0; i<10; i++)
        printf("%d ", array[i]);

   return 0;
}

void quickSort(int array[SIZE],int first,int last)
{
    int pivot;
    int temp;
    int i,j;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(array[i]<=array[pivot] && i<last)
                 i++;

            while(array[j] > array[pivot])
                 j--;

            if(i<j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quickSort(array, first, j-1);
        quickSort(array, j+1, last);
    }

    return;
}

