
#include <bits/stdc++.h>
using namespace std;

// //Method-1 Recursion
// int solve(vector<int> &satis, int index, int time)
// {
//     // base case
//     if (index == satis.size())
//         return 0;

//     // include
//     int include = satis[index] * (time + 1) + solve(satis, index + 1, time + 1);

//     // exclude
//     int exclude = 0 + solve(satis, index + 1, time);

//     return max(include, exclude);
// }

// int maxSatisfaction(vector<int> &satis)
// {
//     // sort the input array
//     sort(satis.begin(), satis.end());
//     return solve(satis, 0, 0);
// }

// Method-2 Recursion+memoization
// int solveMemo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
// {
//     // base case
//     if (index == satisfaction.size())
//         return 0;

//     if (dp[index][time] != -1)
//         return dp[index][time];

//     int include = satisfaction[index] * (time + 1) + solveMemo(satisfaction, index + 1, time + 1, dp);

//     int exclude = 0 + solveMemo(satisfaction, index + 1, time, dp);

//     return dp[index][time] = max(include, exclude);
// }

// int maxSatisfaction(vector<int> &satisfaction)
// {
//     int n = satisfaction.size();
//     vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));

//     sort(satisfaction.begin(), satisfaction.end());

//     return solveMemo(satisfaction, 0, 0, dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &satisfaction)
// {
//     int n = satisfaction.size();
//     // create dp array
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int index = n - 1; index >= 0; index--)
//     {
//         for (int time = index; time >= 0; time--)
//         {
//             int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];

//             int exclude = 0 + dp[index + 1][time];

//             dp[index][time] = max(include, exclude);
//         }
//     }

//     return dp[0][0];
// }

// int maxSatisfaction(vector<int> &satisfaction)
// {
//     // Initialy sort the array
//     sort(satisfaction.begin(), satisfaction.end());

//     return solveTab(satisfaction);
// }

//Method-4 Space optimize
int solveSpa(vector<int> &satisfaction)
{
    int n = satisfaction.size();

   vector<int> curr(n+1,0);
   vector<int> next(n+1,0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + next[time + 1];

            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }
        
        next=curr;
    }

    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    // Initialy sort the array
    sort(satisfaction.begin(), satisfaction.end());

    return solveSpa(satisfaction);
}

int main()

{
    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}