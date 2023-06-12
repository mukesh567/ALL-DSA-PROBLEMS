
#include <bits/stdc++.h>
using namespace std;

// //Method-1 Recursion
// int solve(vector<int> &obstacles, int currLan, int pos)
// {
//     int n = obstacles.size() - 1;
//     // base case
//     if (pos == n)
//         return 0;

//     // agar same lan me agli pos par koi obstacles nhi hai
//     if (obstacles[pos + 1] != currLan)
//         return solve(obstacles, currLan, pos + 1);

//     // obstacles ho to side ways possible hai ....or dono choice ho side ways ki to min lenge
//     else
//     {
//         int ans = INT_MAX;
//         // track for all lan
//         for (int i = 1; i <= 3; i++)
//         {
//             if (currLan != i && obstacles[pos] != i)
//                 ans = min(ans, 1 + solve(obstacles, i, pos));
//         }
//         return ans;
//     }
// }

// int minSideJumps(vector<int> &obstacles)
// {

//     return solve(obstacles, 2, 0);
// }

// Method-2 Recursion + memoization
// int solveMemo(vector<int> &obstacles, int currLan, int pos, vector<vector<int>> &dp)
// {
//     int n = obstacles.size() - 1;
//     // base case
//     if (pos == n)
//         return 0;

//     if (dp[currLan][pos] != -1)
//         return dp[currLan][pos];

//     // agar same lan me agli pos par koi obstacles nhi hai
//     if (obstacles[pos + 1] != currLan)
//         return solveMemo(obstacles, currLan, pos + 1, dp);

//     // obstacles ho to side ways possible hai ....or dono choice ho side ways ki to min lenge
//     else
//     {
//         int ans = INT_MAX;
//         // track for all lan
//         for (int i = 1; i <= 3; i++)
//         {
//             if (currLan != i && obstacles[pos] != i)
//                 ans = min(ans, 1 + solveMemo(obstacles, i, pos, dp));
//         }

//         return dp[currLan][pos] = ans;
//     }
// }

// int minSideJumps(vector<int> &obstacles)
// {
//     vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
//     return solveMemo(obstacles, 2, 0,dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &obstacles)
// {
//     int n = obstacles.size() - 1;

//     // create dp array
//     vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));

//     // Base case analisys
//     dp[0][n] = 0;
//     dp[1][n] = 0;
//     dp[2][n] = 0;
//     dp[3][n] = 0;

//     // rest of the task
//     for (int pos = n - 1; pos >= 0; pos--)
//     {
//         for (int currLan = 1; currLan <= 3; currLan++)
//         {
//             if (obstacles[pos + 1] != currLan)
//                 dp[currLan][pos] = dp[currLan][pos + 1];

//             else
//             {
//                 int ans = 1e9;

//                 for (int i = 1; i <= 3; i++)
//                 {
//                     if (currLan != i && obstacles[pos] != i)
//                         ans = min(ans, 1 + dp[i][pos + 1]);
//                 }
//                 dp[currLan][pos] = ans;
//             }
//         }
//     }

//     return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
// }

// int minSideJumps(vector<int> &obstacles)
// {
//     return solveTab(obstacles);
// }

int solveSpa(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    // rest of the task
    for (int pos = n - 1; pos >= 0; pos--)
    {
        for (int currLan = 1; currLan <= 3; currLan++)
        {
            if (obstacles[pos + 1] != currLan)
                curr[currLan] = next[currLan];

            else
            {
                int ans = 1e9;

                for (int i = 1; i <= 3; i++)
                {
                    if (currLan != i && obstacles[pos] != i)
                        ans = min(ans, 1 + next[i]);
                }
                curr[currLan] = ans;
            }
        }

        next = curr;
    }

    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int> &obstacles)
{
    return solveSpa(obstacles);
}

int main()
{
    vector<int> obstacles = {0, 2, 1, 0, 3, 0};

    cout << minSideJumps(obstacles) << endl;
}