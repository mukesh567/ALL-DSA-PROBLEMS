// first bigger element
#include <bits/stdc++.h>
using namespace std;
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void waveSort(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            Swap(&arr[i], &arr[i - 1]);
        }
        if (i <= n - 1 && arr[i] > arr[i + 1])
        {
            Swap(&arr[i], &arr[i + 1]);
        }
    }
}
int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    waveSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}