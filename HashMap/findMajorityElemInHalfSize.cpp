
#include <bits/stdc++.h>
using namespace std;

int findMajorityEle(int arr[], int size)
{
    unordered_map<int, int> m;
    // sabhi element ka count store kar diya
    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
    }

    int count = 0;

    for (auto i : m)
    {
        if (i.second > size / 2)
        {
            count = 1;
            return i.first;
            break;
        }
    }

    if (count == 0)
        return -1;
}

int main()
{
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << "The majority element with size greater than the size of n/2 of the array is : " << findMajorityEle(arr, n) << endl
         << endl;

    return 0;
}
