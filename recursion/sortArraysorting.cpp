
#include <bits/stdc++.h>
using namespace std;

void isSorted(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return;
    }

    // solve one case
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call
    isSorted(arr, n - 1);
}

int main()
{
    int arr[] = {5, 4, 6, 7, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    isSorted(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}