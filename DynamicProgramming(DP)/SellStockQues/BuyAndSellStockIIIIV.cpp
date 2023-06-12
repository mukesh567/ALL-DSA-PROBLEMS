
#include <bits/stdc++.h>
using namespace std;
// AtMost two transactions
//  Prerequsite in this question is buy and sell stock II problem

// Method-1 Recursion
// int solve(int index, int buy, int limit, vector<int> &prices)
// {
//     // base case
//     if (index == prices.size())
//         return 0;

//     if (limit == 0)
//         return 0;

//     int profit = 0;

//     // buy allowed
//     if (buy)
//     {
//         // there is two case
//         // Buy karo
//         int buyKaro = -prices[index] + solve(index + 1, 0, limit, prices);

//         // Skip karo
//         int skipKaro = 0 + solve(index + 1, 1, limit, prices);
//         profit = max(buyKaro, skipKaro);
//     }
//     // buy not allowed
//     else
//     {
//         // there is two case
//         // Sell karo
//         // here sell and buy complate one tran complete then limit dec by one
//         int sellKaro = +prices[index] + solve(index + 1, 1, limit - 1, prices);

//         // skip karo
//         int skipKaro = 0 + solve(index + 1, 0, limit, prices);
//         profit = max(sellKaro, skipKaro);
//     }

//     return profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     return solve(0, 1, 2, prices);
// }

// Method-2 Recursion+Memoization
// int solveMemo(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
// {
//     // base case
//     if (index == prices.size())
//         return 0;

//     if (limit == 0)
//         return 0;

//     if (dp[index][buy][limit] != -1)
//         return dp[index][buy][limit];

//     int profit = 0;

//     // buy allowed
//     if (buy)
//     {
//         // there is two case
//         // Buy karo
//         int buyKaro = -prices[index] + solveMemo(index + 1, 0, limit, prices, dp);

//         // Skip karo
//         int skipKaro = 0 + solveMemo(index + 1, 1, limit, prices, dp);
//         profit = max(buyKaro, skipKaro);
//     }
//     // buy not allowed
//     else
//     {
//         // there is two case
//         // Sell karo
//         // here sell and buy complate one tran complete then limit dec by one
//         int sellKaro = +prices[index] + solveMemo(index + 1, 1, limit - 1, prices, dp);

//         // skip karo
//         int skipKaro = 0 + solveMemo(index + 1, 0, limit, prices, dp);
//         profit = max(sellKaro, skipKaro);
//     }

//     return dp[index][buy][limit] = profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return solveMemo(0, 1, 2, prices, dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//     for (int index = n - 1; index >= 0; index--)
//     {
//         for (int buy = 0; buy <= 1; buy++)
//         {
//             for (int limit = 1; limit <= 2; limit++)
//             {
//                 int profit=0;
//                 // buy allowed
//                 if (buy)
//                 {
//                     // there is two case
//                     // Buy karo
//                     int buyKaro = -prices[index] + dp[index + 1][0][limit];

//                     // Skip karo
//                     int skipKaro = 0 + dp[index + 1][1][limit];
//                     profit = max(buyKaro, skipKaro);
//                 }
//                 // buy not allowed
//                 else
//                 {
//                     // there is two case
//                     // Sell karo
//                     // here sell and buy complate one tran complete then limit dec by one
//                     int sellKaro = +prices[index] + dp[index + 1][1][limit - 1];

//                     // skip karo
//                     int skipKaro = 0 + dp[index + 1][0][limit];
//                     profit = max(sellKaro, skipKaro);
//                 }

//                 dp[index][buy][limit] = profit;
//             }
//         }
//     }

//     return dp[0][1][2];
// }

// int maxProfit(vector<int> &prices)
// {
//     return solveTab(prices);
// }

// Method-4 Space Optimize
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                // buy allowed
                if (buy)
                {
                    // there is two case
                    // Buy karo
                    int buyKaro = -prices[index] + next[0][limit];

                    // Skip karo
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                // buy not allowed
                else
                {
                    // there is two case
                    // Sell karo
                    // here sell and buy complate one tran complete then limit dec by one
                    int sellKaro = +prices[index] + next[1][limit - 1];

                    // skip karo
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }

                curr[buy][limit] = profit;
            }
        }
        
        next = curr;
    }

    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}

int main()

{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}