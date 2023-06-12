
#include <bits/stdc++.h>
using namespace std;

void Merge(int *arr, int start, int mid, int end)
{
    // length of first array is
    int len1 = mid - start + 1;

    // length of second array is
    int len2 = end - mid;

    // create first array
    int *first = new int[len1];

    // create second array
    int *second = new int[len2];

    // value copy to first array (start se mid tak)
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    // value copy to second array(mid+1 se end tak)
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge two array
    k = start;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }

    // agar pehla array bada ho
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    // agar dusra array bada ho
    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

int main()
{

    int arr[] = {5, 4, 7, 6, 2, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}