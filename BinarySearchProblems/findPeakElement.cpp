
// Mountain array solution

#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
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
    int arr[6] = {11, 12, 13, 9, 8};

    cout << "Peak element Index in this array is : " << peakElement(arr, 6) << endl;

    return 0;
}