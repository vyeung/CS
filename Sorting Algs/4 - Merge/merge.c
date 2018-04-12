#include<stdio.h>

#define SIZE 50

void mergeSort(int array[], int low, int mid, int high);
void partition(int array[], int low, int high);

int main(){

    int array[SIZE] = {4,3,9,2,1,5,8,6,0,7};
    int temp;
    int i,j;

    printf("Before: ");
    for(i=0; i<10; i++)
        printf("%d ", array[i]);

    partition(array, 0, 10-1);

    printf("\nAfter:  ");
    for(i=0; i<10; i++)
        printf("%d ", array[i]);

   return 0;
}

void partition(int array[],int low,int high)
{
    int mid;

    if(low < high)
    {
         mid = (low+high)/2;
         partition(array, low, mid);
         partition(array, mid+1, high);
         mergeSort(array, low, mid, high);
    }

    return;
}

void mergeSort(int array[], int low, int mid, int high)
{
    int i, m, k, l, temp[SIZE];

    l = low;
    i = low;
    m = mid+1;

    while((l<=mid) && (m<=high))
    {
        if(array[l] <= array[m])
        {
            temp[i] = array[l];
            l++;
        }

        else
        {
            temp[i] = array[m];
            m++;
        }
        i++;
    }

    if(l > mid)
    {
        for(k=m; k<=high; k++)
        {
            temp[i] = array[k];
            i++;
        }
    }

    else
    {
        for(k=l; k<=mid; k++)
        {
            temp[i]=array[k];
            i++;
        }
    }

    for(k=low; k<=high; k++)
    {
         array[k] = temp[k];
    }

    return;
}
