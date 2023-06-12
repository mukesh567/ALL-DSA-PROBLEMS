
#include <bits/stdc++.h>
using namespace std;

int getInv(int *arr, int n)
{
    int inv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inv++;
            }
        }
    }
    return inv;
}

int main()
{
    int arr[] = {1, 3, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inversions is : " << getInv(arr, n) << endl;
}