
#include <bits/stdc++.h>
using namespace std;

void findDuplicates(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {4, 2, 3, 4, 2, 7, 8, 8, 3};

    int size = sizeof(arr) / sizeof(arr[0]);
    findDuplicates(arr, size);

    return 0;
}