
#include <bits/stdc++.h>
using namespace std;

void inserSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];

        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            // else
            // {
            //     break;
            // }
        }
        arr[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {10, 1, 7, 4, 8, 2};

    cout << "Sorted array is : ";
    inserSort(arr, 6);
    return 0;
}