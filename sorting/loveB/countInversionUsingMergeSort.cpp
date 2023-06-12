

#include <bits/stdc++.h>
using namespace std;

long long Merge(int arr[], int start, int mid, int end)

{
    long long inv = 0;
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
        if (first[index1] <= second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
            inv += len1 - index1;
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
    return inv;
}

long long mergeSort(int arr[], int start, int end)

{
    long long inv = 0;

    if (start < end)
    {

        long long mid = start + (end - start) / 2;

        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid + 1, end);
        inv += Merge(arr, start, mid, end);
        
    }

    return inv;
}

int main()
{

    int arr[] = {1, 3, 2, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    long long inv = mergeSort(arr, 0, n - 1);

    cout << "Total inversions of this array is : " << inv << endl;

    return 0;
}