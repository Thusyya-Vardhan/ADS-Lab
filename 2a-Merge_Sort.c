#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int l, int m, int h)
{
    int temp[h - l + 1];

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= h)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= h; i++, k++)
        arr[i] = temp[k];
}

void MergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, h);

        Merge(arr, l, m, h);
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

    MergeSort(arr, 0, size - 1);

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}