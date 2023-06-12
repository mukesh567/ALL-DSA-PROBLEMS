
#include <bits/stdc++.h>
using namespace std;
// Bitonic means first increasing subseq and then deacresing
// Logic from longest increasing subseq
// calculate increasing subseq from both side

int solveTab(int n, vector<int> &arr)
{
    // forward increasing subseq
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }
    }

    // backword increasing subseq
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 1; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i])
            {
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }
    }

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int LBS(vector<int> &arr)
{
    int n = arr.size();
    return solveTab(n, arr);
}

int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

    cout << LBS(arr) << endl;

    return 0;
}