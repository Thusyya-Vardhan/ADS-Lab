#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parent(int index)
{
    return (index - 1) / 2;
}

int granparent(int index)
{
    if (index < 3)
        return -1;

    return (index - 3) / 4;
}

int level(int index)
{
    return floor(log2(index + 1));
}

int isMin(int level)
{
    return level % 2 == 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleMax(int heap[], int p, int gp)
{
    if (gp >= 0 && heap[p] > heap[gp])
    {
        swap(&heap[p], &heap[gp]);

        p = gp;
        gp = granparent(gp);

        bubbleMax(heap, p, gp);
    }
}

void bubbleMin(int heap[], int p, int gp)
{
    if (gp >= 0 && heap[p] < heap[gp])
    {
        swap(&heap[p], &heap[gp]);

        p = gp;
        gp = granparent(gp);

        bubbleMin(heap, p, gp);
    }
}

void insertion(int heap[], int index)
{

    if (index < 1)
        return;

    int p = parent(index);
    int temp = level(p);
    int ItsMin = isMin(temp);

    if (ItsMin == 1)
    {

        if (heap[index] < heap[p])
        {

            swap(&heap[index], &heap[p]);

            int gp = granparent(p);
            bubbleMin(heap, p, gp);
        }

        int gp = granparent(index);
        bubbleMax(heap, index, gp);
    }

    if (ItsMin == 0)
    {

        if (heap[index] > heap[p])
        {

            swap(&heap[index], &heap[p]);

            int gp = granparent(p);
            bubbleMax(heap, p, gp);
        }

        int gp = granparent(index);
        bubbleMin(heap, index, gp);
    }
}

void search(int heap[], int key, int n)
{

    int found = 0;

    for (int i = 0; i < n; i++)
    {

        if (heap[i] == key)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
        printf("\nKey Found");
    else
        printf("\nKey not found");
}

/* ---------------- TRICKLE DOWN ---------------- */

void TrickleDown(int heap[], int n, int index)
{

    int minLevel = isMin(level(index));

    int childAndGrand[] = {
        2 * index + 1,
        2 * index + 2,
        4 * index + 3,
        4 * index + 4,
        4 * index + 5,
        4 * index + 6};

    int size = sizeof(childAndGrand) / sizeof(childAndGrand[0]);

    int bestIndex = -1;

    /* MIN LEVEL */
    if (minLevel == 1)
    {

        int minValue = heap[index];

        for (int i = 0; i < size; i++)
        {

            int current = childAndGrand[i];

            if (current < n && heap[current] < minValue)
            {

                minValue = heap[current];
                bestIndex = current;
            }
        }

        if (bestIndex == -1)
            return;

        swap(&heap[index], &heap[bestIndex]);

        /*
           If bestIndex is a grandchild,
           check the new element against its parent.
        */
        if (bestIndex >= 4 * index + 3)
        {

            int p = parent(bestIndex);

            if (heap[bestIndex] > heap[p])
            {
                swap(&heap[bestIndex], &heap[p]);
            }
        }

        TrickleDown(heap, n, bestIndex);
    }

    /* MAX LEVEL */
    else
    {

        int maxValue = heap[index];

        for (int i = 0; i < size; i++)
        {

            int current = childAndGrand[i];

            if (current < n && heap[current] > maxValue)
            {

                maxValue = heap[current];
                bestIndex = current;
            }
        }

        if (bestIndex == -1)
            return;

        swap(&heap[index], &heap[bestIndex]);

        /*
           If bestIndex is a grandchild,
           check the new element against its parent.
        */
        if (bestIndex >= 4 * index + 3)
        {

            int p = parent(bestIndex);

            if (heap[bestIndex] < heap[p])
            {
                swap(&heap[bestIndex], &heap[p]);
            }
        }

        TrickleDown(heap, n, bestIndex);
    }
}

/* ---------------- DELETION ---------------- */

void deletion(int heap[], int *n, int index)
{
    if (index < 0 || index >= *n)
        return;

    // Replace deleted element with last element
    heap[index] = heap[*n - 1];
    (*n)--;

    // Nothing to fix
    if (index >= *n)
        return;

    // Root has no parent
    if (index == 0)
    {
        TrickleDown(heap, *n, index);
        return;
    }

    int p = parent(index);

    // Current node is on MIN level
    if (isMin(level(index)))
    {
        // Current node is MIN level
        // It must be <= its MAX parent

        if (heap[index] > heap[p])
        {
            swap(&heap[index], &heap[p]);

            int gp = granparent(p);
            bubbleMax(heap, p, gp);
        }
        else
        {
            TrickleDown(heap, *n, index);
        }
    }
    else
    {
        // Current node is MAX level
        // It must be >= its MIN parent

        if (heap[index] < heap[p])
        {
            swap(&heap[index], &heap[p]);

            int gp = granparent(p);
            bubbleMin(heap, p, gp);
        }
        else
        {
            TrickleDown(heap, *n, index);
        }
    }
}

int main()
{

    int arr[] = {
        2, 12, 52, 75, 1241, 542, 65, 123, 57, 13, 6234};

    int n = sizeof(arr) / sizeof(arr[0]);

    int heap[n];

    /* Build Min-Max Heap */
    for (int i = 0; i < n; i++)
    {

        heap[i] = arr[i];

        insertion(heap, i);
    }

    printf("Original heap:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    search(heap, 7, n);

    /* Delete element at index 1 */
    deletion(heap, &n, 1);

    printf("\n\nAfter deletion:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    return 0;
}