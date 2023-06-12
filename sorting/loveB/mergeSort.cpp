
#include <bits/stdc++.h>
using namespace std;

void MergeCon(int *arr, int start, int mid, int end)
{
    int n = end - start + 1;
    int merged[n];
    int index = 0;

    // first array ka index
    int ind1 = start;
    // second array ka index
    int ind2 = mid + 1;

    while (ind1 <= mid && ind2 <= end)
    {
        if (arr[ind1] <= arr[ind2])
        {
            merged[index] = arr[ind1];
            index++;
            ind1++;
        }
        else
        {
            merged[index] = arr[ind2];
            index++;
            ind2++;
        }
    }

    // agar pehla array bada ho to
    while (ind1 <= mid)
    {
        merged[index] = arr[ind1];
        index++;
        ind1++;
    }
    
    // agar dusra array bada ho to
    while (ind2 <= end)
    {
        merged[index] = arr[ind2];
        index++;
        ind2++;
    }


    // copy entire array(merged) to main array
    for (int i = start; i <=end; i++)
    {
        arr[i] = merged[i - start];
    }
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
    MergeCon(arr, start, mid, end);
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