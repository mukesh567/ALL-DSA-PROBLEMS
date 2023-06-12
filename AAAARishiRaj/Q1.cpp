
// Q1. write a program to create an 1d array and also display the elements of the array?

#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n)
{
    cout << sizeof(arr) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the arrays elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Arrays elements are : ";
    printArray(arr, n);
    return 0;
}