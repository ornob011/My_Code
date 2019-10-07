#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int size, int i)
{
    int largest, l, r;
    largest = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, size, largest);
    }
}

void build_max(int heap[], int size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

void printArray(int *arr, int size)
{
    build_max(arr, size);

    cout << "Heaped Array:\n";
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    cout << endl;
}

void insert(int *arr, int &size)
{
    cout << "Enter new element to insert: ";
    size++;
    cin >> arr[size - 1];
}

void deletion(int *arr, int &size)
{
    int del, i;
    cout << "Enter an element to delete: ";
    cin >> del;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == del)
        {
            break;
        }
    }
    if (i >= size)
    {
        cout << "Element not present." << endl;
        return;
    }
    arr[i] = arr[size - 1];
    size--;
}

int main()
{
    int arr[100], size, i, choice;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter elements: ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter choice:\n";

    while (1)
    {
        cout << "\n1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Display\n\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            insert(arr, size);
            break;

        case 2:
            deletion(arr, size);
            break;

        case 3:
            printArray(arr, size);
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}