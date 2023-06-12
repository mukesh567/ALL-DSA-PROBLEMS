
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int boards[], int n, long long mid, int k)
{
    int painterCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (boardSum + boards[i] <= mid)
        {
            boardSum += boards[i];
        }
        else
        {
            painterCount++;
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }
            boardSum = boards[i];
        }
    }

    return true;
}

long long paintersPartition(int boards[], int n, int k)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    long long low = 0, high = sum;
    long long ans = -1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isPossible(arr, n, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {5, 10, 30, 20, 15};
    int n = 5;
    int m = 3;

    cout << "Minimum time to paint boards : " << paintersPartition(arr, n, m) << endl;
    return 0;
}