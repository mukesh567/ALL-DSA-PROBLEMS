// only Sort 0,1,2 arrays
#include <bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dnfSort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            Swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            Swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    dnfSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}