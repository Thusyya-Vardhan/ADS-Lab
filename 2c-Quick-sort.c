#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

        j++;
    }

    swap(&arr[i + 1], &arr[pivot]);

    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {1, 21, 51, 5, 123, 115, 94, 3324, 8853, 553, 13, 25};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    QuickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}