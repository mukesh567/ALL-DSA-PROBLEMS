
#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// long long solve(int faces, int dice, int target)
// {
//     // base cases
//     if (target < 0)
//         return 0;

//     if (dice != 0 && target == 0)
//         return 0;

//     if (dice == 0 && target != 0)
//         return 0;

//     if (dice == 0 && target == 0)
//         return 1;

//     long long ans = 0;
//     for (int i = 1; i <= faces; i++)
//     {
//         ans = ans + solve(faces, dice - 1, target - i);
//     }

//     return ans;
// }

// long long noOfWays(int faces, int dice, int target)
// {

//     return solve(faces, dice, target);
// }

// // Method-2 Recursion+memoization
// int solveMemo(int faces, int dice, int target,vector<vector<int>> &dp)
// {
//     // base cases
//     if (target < 0)
//         return 0;

//     if (dice != 0 && target == 0)
//         return 0;

//     if (dice == 0 && target != 0)
//         return 0;

//     if (dice == 0 && target == 0)
//         return 1;

//     if(dp[dice][target]!=-1)
//         return dp[dice][target];

//     int ans = 0;
//     for (int i = 1; i <= faces; i++)
//     {
//         ans = ans + solveMemo(faces, dice - 1, target - i,dp);
//     }

//     return dp[dice][target] =  ans;
// }

// int noOfWays(int faces, int dice, int target)
// {
//   vector<vector<int>> dp(dice+1,vector<int> (target+1,-1));
//     return solveMemo(faces, dice, target,dp);
// }

// Method-3 tabulation
// int solveTab(int faces, int d, int t)
// {
//     vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));

//     // base cases analysis
//     dp[0][0] = 1;

//     for (int dice = 1; dice <= d; dice++)
//     {
//         for (int target = 1; target <= t; target++)
//         {
//             int ans = 0;
//             for (int i = 1; i <= faces; i++)
//             {
//                 if(target-i >=0)
//                   ans = ans + dp[dice - 1][target - i];
//             }

//             dp[dice][target] = ans;
//         }
//     }
    
//     return dp[d][t];
// }

// int noOfWays(int faces, int dice, int target)
// {

//     return solveTab(faces, dice, target);
// }


//Method-4 Space optimize
int solveSpa(int faces, int d, int t)
{
   vector<int> prev(t+1,0);
   vector<int> curr(t+1,0);

    // base cases analysis
    prev[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            int ans = 0;
            for (int i = 1; i <= faces; i++)
            {
                if(target-i >=0)
                  ans = ans + prev[target - i];
            }

            curr[target] = ans;
        }
        prev = curr;
    }
    
    return prev[t];
}

int noOfWays(int faces, int dice, int target)
{
    return solveSpa(faces, dice, target);
} 

int main()
{
    int dice = 3;
    int faces = 6;
    int target = 12;

    cout << noOfWays(faces, dice, target) << endl;

    return 0;
}