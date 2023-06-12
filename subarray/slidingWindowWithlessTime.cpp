
#include <bits/stdc++.h>

using namespace std;

void maxSubarraySum(int arr[], int n, int k)
{
    int sum = 0, ans = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    // if (sum < x)
    // {
    //     ans = sum;
    // }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k];
        sum = sum + arr[i];

        if (sum >=ans)
        {
            ans = sum;
        }
    }
    cout << ans <<endl;
}

int main()
{
    int arr[] = {1,2,7,7,4,3,6};
    int k = 3;
    int n = 6;

    maxSubarraySum(arr, n, k);

    return 0;
}