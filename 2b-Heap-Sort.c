#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int n, int parent)
{
    if (arr == NULL) return;

    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != parent)
    {
        swap(&arr[parent], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }

    // Extract maximum repeatedly
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heap size is now i
        Heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {
        1, 21, 51, 5, 123, 115,
        94, 3324, 8853, 553, 13, 25
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    HeapSort(arr, size);

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}