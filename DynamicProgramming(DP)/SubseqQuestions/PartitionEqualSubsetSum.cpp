
#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// int solve(int index, vector<int> &arr, int n, int target)
// {
//     // base case
//     if (index >= n)
//         return 0;

//     if (target < 0)
//         return 0;

//     if (target == 0)
//         return 1;

//     int include = solve(index + 1, arr, n, target - arr[index]);
//     int exclude = solve(index + 1, arr, n, target);

//     return include || exclude;
// }

// int partEqualSum(vector<int> &arr, int n)
// {
//     // total sum calculate
//     int totalSum = 0;
//     for (int i = 0; i < n; i++)
//         totalSum += arr[i];

//     // total sum is odd then return false
//     if (totalSum % 2 != 0)
//         return 0;

//     int target = totalSum / 2;

//     return solve(0, arr, n, target);
// }

// // Method-2 Recursion+memoization
// int solveMemo(int index, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
// {
//     // base case
//     if (index >= n)
//         return 0;

//     if (target < 0)
//         return 0;

//     if (target == 0)
//         return 1;

//     if (dp[index][target] != -1)
//         return dp[index][target];

//     int include = solveMemo(index + 1, arr, n, target - arr[index], dp);
//     int exclude = solveMemo(index + 1, arr, n, target, dp);

//     return dp[index][target] = include || exclude;
// }

// int partEqualSum(vector<int> &arr, int n)
// {
//     // total sum calculate
//     int totalSum = 0;
//     for (int i = 0; i < n; i++)
//         totalSum += arr[i];

//     // total sum is odd then return false
//     if (totalSum % 2 != 0)
//         return 0;

//     int target = totalSum / 2;

//     // create vector
//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//     return solveMemo(0, arr, n, target, dp);
// }

// // Method-3 Tabulation
// int solveTab(vector<int> &arr, int n, int t)
// {
//     // create vector
//     vector<vector<int>> dp(n+1, vector<int>(t + 1, 0));

//     // base case analysis
//     for (int i = 0; i <= n; i++)
//         dp[i][0] = 1;

//     for (int index = n - 1; index >= 0; index--)
//     {
//         for (int target = 0; target <= t; target++)
//         {
//             int include = dp[index + 1][target - arr[index]];
//             int exclude = dp[index + 1][target];

//              dp[index][target] = include || exclude;
//         }
//     }

//     return dp[0][t];
// }

// int partEqualSum(vector<int> &arr, int n)
// {
//     // total sum calculate
//     int totalSum = 0;
//     for (int i = 0; i < n; i++)
//         totalSum += arr[i];

//     // total sum is odd then return false
//     if (totalSum % 2 != 0)
//         return 0;

//     int target = totalSum / 2;

//     return solveTab(arr, n, target);
// }

// Method-4 Space optimize
int solve(vector<int> &arr, int n, int t)
{
    // create vector
    vector<int> curr(t+1,0);
    vector<int> next(t+1,0);
     
     curr[0]=1;
     next[0]=1;


    for (int index = n - 1; index >= 0; index--)
    {
        for (int target = 0; target <= t; target++)
        {
            int include = next[target - arr[index]];
            int exclude = next[target];

             curr[target] = include || exclude;
        }

        next = curr;
    }

    return next[t];
}

int partEqualSum(vector<int> &arr, int n)
{
    // total sum calculate
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // total sum is odd then return false
    if (totalSum % 2 != 0)
        return 0;

    int target = totalSum / 2;

    return solve(arr, n, target);
}


int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int n = arr.size();

    if (partEqualSum(arr, n))
        cout << "partition of equal sum is possible !" << endl;

    else
        cout << "Not possible !" << endl;

    return 0;
}