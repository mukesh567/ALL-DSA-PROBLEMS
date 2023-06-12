
#include <bits/stdc++.h>
using namespace std;

void MergeTwoArray(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n)
    {
        arr3[k++] = arr1[j++];
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
    int arr1[6] = {1, 3, 5, 7, 9, 11};
    int arr2[5] = {2, 4, 6, 8, 10};
    int arr3[11] = {0};

    MergeTwoArray(arr1, 6, arr2, 5, arr3);
    printArray(arr3, 11);
    return 0;
}