
#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];

    // ki kitne elements pivet se chote hai
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // than pivot ko eski right pos pe daal do
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // left part pivot se chhota or right part bada hona chahiye
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // partition karne par
    int p = partition(arr, start, end);

    // left arr ko sort karne par
    quickSort(arr, start, p - 1);

    // right part sort karne par
    quickSort(arr, p + 1, end);
}

int main()

{
    int arr[] = {3, 4, 1, 2, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}