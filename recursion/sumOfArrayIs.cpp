
#include <bits/stdc++.h>
using namespace std;

int getSum(int *arr, int size)
{
    // base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    int sum = arr[0] + getSum(arr + 1, size - 1);

    return sum;
}

int main()
{
    int arr[] = {3, 4, 5, 2, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The sum of that array is : " << getSum(arr, size) << endl;
    return 0;
}