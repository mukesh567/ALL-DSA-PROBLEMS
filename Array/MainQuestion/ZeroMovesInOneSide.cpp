
#include <bits/stdc++.h>
using namespace std;

void MovesZero(int arr[], int n)
{
    int NonZero = n-1;

    for (int i = n-1; i >=0; i--)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[NonZero]);
            NonZero--;
        }
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
    int arr[5]={0,1,4,0,2};

    MovesZero(arr, 5);

    printArray(arr, 5);

    return 0;
}