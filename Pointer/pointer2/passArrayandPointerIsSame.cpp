
#include <bits/stdc++.h>
using namespace std;

// int arr[] and int *arr is same .........dono  as a pointer pass hote hai

int getSum(int *arr, int n)
{

    cout << endl
         << "Size of : " << sizeof(arr) << endl;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Sum is : " << getSum(arr, 7) << endl;

    return 0;
}