
#include <bits/stdc++.h>
using namespace std;

int firstOccu(int arr[], int n, int key)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] < key)
            start = mid + 1;

        else
            end = mid - 1;
    }
    
    return ans;
}

int lastOccu(int arr[], int n, int key)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 3, 2};

    cout << "First occurrence of this element is : " << firstOccu(arr, 6, 3) << endl;

    cout << "Last occurrence of this element is : " << lastOccu(arr, 6, 3) << endl;

    return 0;
}