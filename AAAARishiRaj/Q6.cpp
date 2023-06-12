
// Q6. Write a program to search an element in array using binary search?

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter arrays elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter key who you want to search : ";
    cin >> key;

    if (BinarySearch(arr, n, key))
    {
        cout << "Key is present!" << endl;
    }
    else
    {
        cout << "Key is not present!" << endl;
    }
    return 0;
}