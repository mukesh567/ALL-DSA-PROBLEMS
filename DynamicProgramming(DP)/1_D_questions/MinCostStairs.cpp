
#include <bits/stdc++.h>
using namespace std;

// Method-1
//  top-down (recursion + memoization)
//  int solve(vector<int> &cost, int n, vector<int> &dp)
//  {
//      // base cases
//      if (n == 0)
//      {
//          return cost[0];
//      }

//     if (n == 1)
//     {
//         return cost[1];
//     }

//     // step-3
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     // step-2
//      dp[n] = cost[n] + min(solve(cost, n - 1,dp), solve(cost, n - 2,dp));

//     return dp[n];
// }

// int minCostToreachNthStairs(vector<int> &cost)
// {
//     int n = cost.size();

//     // step-1
//     vector<int> dp(n + 1, -1);

//     int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

//     return ans;
// }

// Method-2
//  Bottom_up (tabulation)
//  int solve(vector<int> &cost, int n)
//  {
//      // create dp array
//      vector<int> dp(n + 1);

//     // base case analyze
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     // rest of the task
//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//     }

//     return min(dp[n - 1], dp[n - 2]);
// }

// int minCostToreachNthStairs(vector<int> &cost)
// {
//     int n = cost.size();

//     return solve(cost, n);
// }

// Method-3
// Space optimize
int solve(vector<int> &cost, int n)
{
    int prev1 = cost[1];
    int prev2 = cost[0];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int minCostToreachNthStairs(vector<int> &cost)
{
    int n = cost.size();

    return solve(cost, n);
}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    int ans = minCostToreachNthStairs(cost);
    cout << "Ans is : " << ans << endl;

    return 0;
}