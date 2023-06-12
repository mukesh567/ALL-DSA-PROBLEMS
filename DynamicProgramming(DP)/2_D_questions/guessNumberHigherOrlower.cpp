
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(int start, int end)
// {
//     // base case
//     if (start >= end)
//         return 0;

//     int ans = INT_MAX;
//     for (int i = start; i <= end; i++)
//     {
//         ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
//     }

//     return ans;
// }

// int getMoneyAmount(int n)
// {

//     return solve(1, n);
// }

// // Method-2 Recursion+memoizaton
// int solveMemo(int start, int end, vector<vector<int>> &dp)
// {
//     // base case
//     if (start >= end)
//         return 0;

//     if (dp[start][end] != -1)
//         return dp[start][end];

//     int ans = INT_MAX;
//     for (int i = start; i <= end; i++)
//     {
//         ans = min(ans, i + max(solveMemo(start, i - 1, dp), solveMemo(i + 1, end, dp)));
//     }

//     return dp[start][end] = ans;
// }

// int getMoneyAmount(int n)
// {

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//     return solveMemo(1, n, dp);
// }

// Method-3 Tabulation
int solveTab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
                continue;

            else
            {
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }

                dp[start][end] = ans;
            }
        }
    }

    return dp[1][n];
}

int getMoneyAmount(int n)
{
    return solveTab(n);
}

int main()
{
    int n = 10;

    cout << "Minimum amount when you got the wrong answer : " << getMoneyAmount(n) << endl;

    return 0;
}