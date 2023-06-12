
#include <bits/stdc++.h>
using namespace std;
// Prerequsite buy and sell II
//Recursion
// int solve(int index, int buy, vector<int> &prices,int fee)
// {
//     // base case
//     if (index == prices.size())
//         return 0;

//     int profit = 0;

//     // buy allowed
//     if (buy)
//     {
//         // there is two case
//         // Buy karo
//         int buyKaro = -prices[index] + solve(index + 1, 0, prices,fee);

//         // Skip karo
//         int skipKaro = 0 + solve(index + 1, 1, prices,fee);
//         profit = max(buyKaro, skipKaro);
//     }
//     // buy not allowed
//     else
//     {
//         // there is two case
//         // Sell karo
//         int sellKaro = +prices[index]-fee + solve(index + 1, 1, prices,fee);

//         // skip karo
//         int skipKaro = 0 + solve(index + 1, 0, prices,fee);
//         profit = max(sellKaro, skipKaro);
//     }

//     return profit;
// }

// int maxProfit(vector<int> &prices, int fee)
// {
//     return solve(0,1,prices, fee);
// }

// Method-2 Recursion+memoization
int solveMemo(int index, int buy, vector<int> &prices,int fee, vector<vector<int>> &dp)
{
    // base case
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;

    // buy allowed
    if (buy)
    {
        // there is two case
        //         //Buy karo
        int buyKaro = -prices[index] + solveMemo(index + 1, 0, prices,fee, dp);

        //         //Skip karo
        int skipKaro = 0 + solveMemo(index + 1, 1, prices,fee, dp);
        profit = max(buyKaro, skipKaro);
    }
    else
    {
        // there is two case
        // sell karo
        int sellKaro = +prices[index]-fee + solveMemo(index + 1, 1, prices,fee, dp);

        // skip karo
        int skipKaro = 0 + solveMemo(index + 1, 0, prices,fee, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices,int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveMemo(0, 1, prices,fee, dp);
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};

    // Har ak transaction k baad fee deni padegi profit - fee
    int fee = 2;

    cout << maxProfit(prices, fee) << endl;
    return 0;
}