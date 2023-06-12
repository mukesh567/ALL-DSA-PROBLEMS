
// Q2. write a program to insert an element into 1d array at user specific postion?

#include <bits/stdc++.h>
using namespace std;

void insertEle(int *arr, int n, int pos, int element)
{
    if (pos > n)
        cout << "Invalid Input" << endl;
    else
    {
        for (int i = n - 1; i >= pos ; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos ] = element;

        cout << "Array after insertion is : ";

        for (int i = 0; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter arrays elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pos;
    cout << "Enter your position where you want to insert element : ";
    cin >> pos;

    int element;
    cout << "Enter your element : ";
    cin >> element;

    insertEle(arr, n, pos, element);

    return 0;
}