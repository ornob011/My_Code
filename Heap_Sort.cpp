#include <bits/stdc++.h>
using namespace std;

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}

int parent(int i)
{
    return i / 2;
}

void max_heapify(int heap[], int heap_size, int i)
{
    int largest, l, r;
    l = left(i);
    r = right(i);

    if (l <= heap_size && heap[l] > heap[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && heap[r] > heap[largest])
        largest = r;

    if (largest != i)
    {
        heap[i] = heap[i] ^ heap[largest];
        heap[largest] = heap[i] ^ heap[largest];
        heap[i] = heap[i] ^ heap[largest];

        max_heapify(heap, heap_size, largest);
    }
}

void build_max(int heap[], int heap_size)
{
    int i;

    for (i = heap_size / 2; i >= 1; i--)
        max_heapify(heap, heap_size, i);
}

void heap_sort(int heap[], int heap_size)
{
    int i;

    build_max(heap, heap_size);

    for (i = heap_size; i > 1; i--)
    {
        heap[1] = heap[1] ^ heap[i];
        heap[i] = heap[1] ^ heap[i];
        heap[1] = heap[1] ^ heap[i];

        heap_size--;
        max_heapify(heap, heap_size, 1);
    }
}

void printarray(int heap[], int heap_size)
{
    cout << "After Sorting:" << endl;

    for (int i = 1; i < heap_size; i++)
        printf("%d ", heap[i]);

    cout << endl;
}

int main()
{
    int heap[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};
    int heap_size = sizeof(heap) / sizeof(heap[0]);
    heap_size -= 1;

    heap_sort(heap, heap_size);

    printarray(heap, heap_size);
}