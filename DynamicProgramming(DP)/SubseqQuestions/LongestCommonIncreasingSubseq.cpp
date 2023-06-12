
#include <bits/stdc++.h>
using namespace std;

int solveMemo(int i, int j, int pre, int arr[], int arr2[], vector<vector<vector<int>>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    int ans1 = 0;
    int ans2 = 0;

    if (dp[i][j][pre + 1] != -1)
        return dp[i][j][pre + 1];

    if (arr[i] == arr2[j] && (pre == -1 || arr[i] < arr[pre]))
    {
        ans1 = 1 + solveMemo(i - 1, j - 1, i, arr, arr2, dp);
    }

    ans2 = max(solveMemo(i - 1, j, pre, arr, arr2, dp), solveMemo(i, j - 1, pre, arr, arr2, dp));

    return dp[i][j][pre + 1] = max(ans1, ans2);
}

int LCIS(int arr1[], int m, int arr2[], int n)
{
    // code here
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + 1, -1)));

    return solveMemo(m - 1, n - 1, -1, arr1, arr2, dp);
}

int main()
{
    int m = 4;
    int arr1[m] = {3, 4, 9, 1};

    int n = 7;
    int arr2[n] = {5, 3, 8, 9, 10, 2, 1};

    cout << LCIS(arr1, m, arr2, n) << endl;

    return 0;
}