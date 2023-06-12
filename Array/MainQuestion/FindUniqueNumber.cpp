
#include <bits/stdc++.h>
using namespace std;

int FindUniqueN(int arr[], int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the arrays elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Your unique number is : ";
    cout << FindUniqueN(arr, n) << endl;
    return 0;
}