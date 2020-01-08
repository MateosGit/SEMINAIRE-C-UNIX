#include <stdio.h>

void swap(int *xp, int *yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)

    for(int j = 0; j < n - i;j++)
        if(arr[j] > arr[j + 1])
            swap(&arr[j], &arr[j + 1]);
}

int main(void) 
{
    int arr[] = {64, 34, 25, 12, 90, 11, 63};
    bubbleSort(arr, 6);
    return 0;
}
