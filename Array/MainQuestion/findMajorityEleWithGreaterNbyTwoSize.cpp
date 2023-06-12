

#include <bits/stdc++.h>
using namespace std;

int findMjorityEle(int *arr, int n)
{

    int maxCount = 0;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        // sab elements ka count nikala jo equl hai
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        // update count with maxCount and update index with i (present element jiska count sabse jyada hai)
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }

        // array k n/2 size se badha ho to vo majority element hoga
        if (maxCount > n / 2)
        {
            return arr[index];
        }
    }
}

int main()
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << "The majority element with size greater than the size of n/2 of the array is : " << findMjorityEle(arr, n) << endl
         << endl;

    return 0;
}