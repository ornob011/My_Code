#include <bits/stdc++.h>
using namespace std;

void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printarray(int arr[], int size);

int main()
{
    int size, i;
    cout << "Enter size: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements: ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    mergesort(arr, 0, size - 1);
    printarray(arr, size);

    return 0;
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, n1, n2, k;

    n1 = mid - left + 1;
    n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printarray(int arr[], int size)
{
    cout << "After sorting: " << endl;

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    cout << endl;
}