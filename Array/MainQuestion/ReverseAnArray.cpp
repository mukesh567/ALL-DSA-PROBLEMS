
#include <bits/stdc++.h>
using namespace std;

void ReverseArray(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 12, 3, 7, 11};
    int n = 5;

    cout << "After reverse the array : ";
    ReverseArray(arr, n);
    return 0;
}