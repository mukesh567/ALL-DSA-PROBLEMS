
#include <bits/stdc++.h>
using namespace std;

int FindDuplicate(int arr[], int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans ^= arr[i];
    }
    for (int i = 1; i < size; i++)
    {
        ans ^= i;
    }

    return ans;
}


int main()
{
    int arr[5] = {1, 2, 3, 4, 3};

    cout << FindDuplicate(arr, 5) << endl;

    return 0;
}