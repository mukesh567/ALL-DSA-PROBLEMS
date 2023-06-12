
#include <bits/stdc++.h>
using namespace std;

void RotateTheArray(int arr[], int n, int k)
{
    int temp[n];

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int k = 2;
    RotateTheArray(arr, 6, 2);
    printArray(arr, 6);
    return 0;
}