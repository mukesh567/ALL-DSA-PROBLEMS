
#include <bits/stdc++.h>
using namespace std;

void SelecSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {5, 6, 2, 1, 3, 8};

    SelecSort(arr, 6);

    return 0;
}