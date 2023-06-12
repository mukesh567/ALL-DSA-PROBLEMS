
#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}

int binarySearch(int arr[], int n, int start, int end, int key)
{
    int s = start, e = end;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int findPos(int arr[], int n, int k)
{
    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarySearch(arr, n, pivot, n - 1, k);
    }
    else
    {
        return binarySearch(arr, n, 0, pivot - 1, k);
    }
}

int main()
{
    int arr[5] = {12, 15, 18, 2, 4};

    cout << "Search element at Index Number : " << findPos(arr, 5, 4) << endl;
    cout << "Search element at Index Number : " << findPos(arr, 5, 4) << endl;

    return 0;
}