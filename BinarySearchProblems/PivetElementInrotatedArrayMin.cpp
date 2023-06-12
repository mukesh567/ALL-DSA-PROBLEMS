

#include <bits/stdc++.h>
using namespace std;

int findPivet(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }

        else
        {
            end = mid;
        }
    }
    
    return start;
}

int main()
{
    int arr[7] = {8, 10, 5, 4, 3, 2, 1};

    cout << "Pivet element Index is : " << findPivet(arr, 7) << endl;

    return 0;
}