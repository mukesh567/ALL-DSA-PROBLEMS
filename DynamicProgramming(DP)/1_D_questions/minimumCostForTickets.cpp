
#include <bits/stdc++.h>
using namespace std;

// //Method-1 Recursion
// int solve(vector<int> &days,vector<int> &cost,int index)
// {
//     //base case
//     if(index>=days.size())
//         return 0;

//     //1 day pass
//     int op1 = cost[0]+solve(days,cost,index+1);

//     //7 day pass
//     int i;
//     for(i=index;i<days.size() && days[i]<days[index]+7;i++);
//     int op2 = cost[1]+solve(days,cost,i);

//     //30 day pass
//     for(i=index;i<days.size() && days[i]<days[index]+30;i++);
//     int op3 = cost[2]+solve(days,cost,i);

//     return min(op1,min(op2,op3));
// }

// int minCost(vector<int> &days,vector<int> &cost)
// {
//     return solve(days,cost,0);
// }

// // Method-2 Recursion+memoization
// int solveMemo(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
// {
//     // base case
//     if (index >= days.size())
//         return 0;

//     if (dp[index] != -1)
//     {
//         return dp[index];
//     }

//     // 1 day pass
//     int op1 = cost[0] + solveMemo(n, days, cost, index + 1, dp);

//     // 7 day pass
//     int i;
//     for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
//         ;
//     int op2 = cost[1] + solveMemo(n, days, cost, i, dp);

//     // 30 day pass
//     for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
//         ;
//     int op3 = cost[2] + solveMemo(n, days, cost, i, dp);

//     return dp[index] = min(op1, min(op2, op3));
// }

// int minCost(vector<int> &days, vector<int> &cost)
// {
//     int n = days.size();
//     vector<int> dp(n + 1, -1);
//     return solveMemo(n, days, cost, 0, dp);
// }

// Method-3 Tabulation
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        // 1 day pass 
        int op1 = cost[0] + dp[k+1];

        // 7 day pass
        int i;
        for (i = k; i < days.size() && days[i] < days[k] + 7; i++);
        int op2 = cost[1] + dp[i];

        // 30 day pass
        for (i = k; i < days.size() && days[i] < days[k] + 30; i++);
        int op3 = cost[2] + dp[i];

       dp[k] = min(op1, min(op2, op3));
    }

    return dp[0];
}

int minCost(vector<int> &days, vector<int> &cost)
{
    int n = days.size();
    return solveTab(n, days, cost);
}

int main()
{
    vector<int> days = {1, 3, 4, 5, 7, 8, 10};

    // 1day 7day 30day  cost
    vector<int> cost = {2, 7, 20};

    cout << minCost(days, cost) << endl;
    return 0;
}