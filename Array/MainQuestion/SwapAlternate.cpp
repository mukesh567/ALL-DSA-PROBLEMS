
#include <bits/stdc++.h>
using namespace std;

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SwapAlter(int arr[], int size)
{

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];

    cout << "Input the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SwapAlter(arr, n);

    cout << "Your Alternate array is : ";

    PrintArray(arr, n);

    return 0;
}