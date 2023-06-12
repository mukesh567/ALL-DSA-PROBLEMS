
#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// int solve(vector<int> &prices, int index, int opNo, int k)

// {

//     // base cases
//     if (index == prices.size())
//         return 0;

//     if (opNo == 2 * k)
//         return 0;

//     int profit = 0;

//     // for Buy
//     if (opNo % 2 == 0)
//     {
//         int buyKaro = -prices[index] + solve(prices, index + 1, opNo + 1, k);
//         int skipKaro = 0 + solve(prices, index + 1, opNo, k);
//         profit = max(buyKaro, skipKaro);
//     }

//     // for sell
//     else
//     {
//         int sellKaro = +prices[index] + solve(prices, index + 1, opNo + 1, k);
//         int skipKaro = 0 + solve(prices, index + 1, opNo, k);
//         profit = max(sellKaro, skipKaro);
//     }

//     return profit;
// }

// int maxProfit(vector<int> &prices, int k)
// {
//     return solve(prices, 0, 0, k);
// }

// Method-2 Recursion+memoization
// int solve(vector<int> &prices, int index, int opNo, int k, vector<vector<int>> &dp)
// {
//     // base cases
//     if (index == prices.size())
//         return 0;

//     if (opNo == 2 * k)
//         return 0;

//     if (dp[index][opNo] != -1)
//         return dp[index][opNo];

//     int profit = 0;

//     // for Buy
//     if (opNo % 2 == 0)
//     {
//         int buyKaro = -prices[index] + solve(prices, index + 1, opNo + 1, k, dp);
//         int skipKaro = 0 + solve(prices, index + 1, opNo, k, dp);
//         profit = max(buyKaro, skipKaro);
//     }

//     // for sell
//     else
//     {
//         int sellKaro = +prices[index] + solve(prices, index + 1, opNo + 1, k, dp);
//         int skipKaro = 0 + solve(prices, index + 1, opNo, k, dp);
//         profit = max(sellKaro, skipKaro);
//     }

//     return dp[index][opNo] = profit;
// }

// int maxProfit(vector<int> &prices, int k)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2*k, -1));
//     return solve(prices, 0, 0, k, dp);
// }

// Method-3 Tabulation
int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int opNo = 2 * k - 1; opNo >= 0; opNo--)
        {
            int profit = 0;

            // for Buy
            if (opNo % 2 == 0)
            {
                int buyKaro = -prices[index] + dp[index + 1][opNo + 1];
                int skipKaro = 0 + dp[index + 1][opNo];
                profit = max(buyKaro, skipKaro);
            }

            // for sell
            else
            {
                int sellKaro = +prices[index] + dp[index + 1][opNo + 1];
                int skipKaro = 0 + dp[index + 1][opNo];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][opNo] = profit;
        }
    }

    return dp[0][0];
}

int maxProfit(vector<int> &prices, int k)
{
    return solve(prices, k);
}

int main()

{
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    // 2 transactions k liye 4 opretions honge buy and sell buy and sell
    //  2*k   ...
    int k = 2;
    cout << maxProfit(prices, k) << endl;

    return 0;
}