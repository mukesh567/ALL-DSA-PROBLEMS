
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size)
{
    // base case

    if (size == 0 || size == 1)
    {
        return true;
    }

    // only one case solve baaki recursive call kar degi
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    { // recursive call
        return isSorted(arr + 1, size - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, size))
    {
        cout << "Array is sorted ! " << endl;
    }
    else
    {
        cout << "Array is unsorted ! " << endl;
    }
    return 0;
}