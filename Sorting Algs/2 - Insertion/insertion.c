#include <stdio.h>

#define SIZE 10

void insertionSort(int array[SIZE]);

int main()
{
    int array[SIZE] = {4,3,9,2,1,5,8,6,0,7};
    int temp;
    int i,j;

    printf("Before: ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    insertionSort(array);

    printf("\nAfter:  ");
    for(i=0; i<SIZE; i++)
        printf("%d ", array[i]);

    return 0;
}

void insertionSort(int array[SIZE])
{
    int i,j, temp;

    for(i=1; i<SIZE; i++)
    {
        temp = array[i];
        j = i-1;

        while((temp<array[j]) && (j>=0))
        {
            array[j+1] = array[j];
            j = j-1;  //same as j--
        }
        array[j+1] = temp;
    }

    return;
}

/*another implementation

    int i,j;

    for (i=1; i<size; i++)
    {
        j = i;

        while (array[j] < array[j-1] && j>0)
        {
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
*/
