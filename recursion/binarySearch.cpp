
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int start, int end, int key)
{
    // base case
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter your key : ";
    cin >> key;

    if (binarySearch(arr, 0, 4, key))
    {
        cout << "Element are found ! " << endl;
    }
    else
    {
        cout << "Element are not found ! " << endl;
    }

    return 0;
}