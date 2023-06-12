
#include <bits/stdc++.h>
using namespace std;
//Infinite transactions

// Method-1 Recursion
// int solve(int index, int buy, vector<int> &prices)
// {
//     // base case
//     if (index == prices.size())
//         return 0;

//     int profit = 0;

//     // buy allowed
//     if (buy)
//     {
//         // there is two case
//         //Buy karo
//         int buyKaro = -prices[index] + solve(index + 1, 0, prices);

//         //Skip karo
//         int skipKaro = 0 + solve(index + 1, 1, prices);
//         profit = max(buyKaro, skipKaro);
//     }
//     // buy not allowed
//     else
//     {
//         // there is two case
//         //Sell karo
//         int sellKaro = +prices[index] + solve(index + 1, 1, prices);

//         //skip karo
//         int skipKaro = 0 + solve(index + 1, 0, prices);
//         profit = max(sellKaro,skipKaro);
//     }

//     return profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     return solve(0, 1, prices);
// }

// Method-2 Recursion+memoization
// int solveMemo(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
// {
//     // base case
//     if (index == prices.size())
//         return 0;

//     if (dp[index][buy] != -1)
//         return dp[index][buy];

//     int profit = 0;

//     // buy allowed
//     if (buy)
//     {
//         // there is two case
//         //         //Buy karo
//         int buyKaro = -prices[index] + solveMemo(index + 1, 0, prices, dp);

//         //         //Skip karo
//         int skipKaro = 0 + solveMemo(index + 1, 1, prices, dp);
//         profit = max(buyKaro, skipKaro);
//     }
//     else
//     {
//         // there is two case
//         // sell karo
//         int sellKaro = +prices[index] + solveMemo(index + 1, 1, prices, dp);

//         // skip karo
//         int skipKaro = 0 + solveMemo(index + 1, 0, prices, dp);
//         profit = max(sellKaro, skipKaro);
//     }

//     return dp[index][buy] = profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, -1));
//     return solveMemo(0, 1, prices, dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//     for (int index = n - 1; index >= 0; index--)
//     {
//         for (int buy = 0; buy <= 1; buy++)
//         {

//             int profit = 0;

//             // buy allowed
//             if (buy)
//             {
//                 // buy karo
//                 int buyKaro = -prices[index] + dp[index + 1][0];

//                 // skip karo
//                 int skipKaro = 0 + dp[index + 1][1];
//                 profit = max(buyKaro, skipKaro);
//             }
//             else
//             {
//                 // sell karo
//                 int sellKaro = +prices[index] + dp[index + 1][1];

//                 // skip karo
//                 int skipKaro = 0 + dp[index + 1][0];
//                 profit = max(sellKaro, skipKaro);
//             }

//             dp[index][buy] = profit;
//         }
//     }

//     return dp[0][1];
// }

// int maxProfit(vector<int> &prices)
// {
//     return solveTab(prices);
// }

// Method-4 Space optimize
int solveSpa(vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {

            int profit = 0;

            // buy allowed
            if (buy)
            {
                // buy karo
                int buyKaro = -prices[index] + next[0];

                // skip karo
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }
            else
            {
                // sell karo
                int sellKaro = +prices[index] + next[1];

                // skip karo
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }

        next=curr;
    }

    return next[1];
}

int maxProfit(vector<int> &prices)
{
    return solveSpa(prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}