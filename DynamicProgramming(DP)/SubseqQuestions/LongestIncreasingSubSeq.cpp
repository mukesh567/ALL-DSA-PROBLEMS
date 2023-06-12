
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(int n, vector<int> &arr, int currInd, int prevInd)
// {
//     // base case
//     if (currInd == n)
//         return 0;

//     // include
//     int include = 0;
//     if (prevInd == -1 || arr[currInd] > arr[prevInd])
//         include = 1 + solve(n, arr, currInd + 1, currInd);

//     // exclude
//     int exclude = 0 + solve(n, arr, cIurrnd + 1, prevInd);

//     return max(include, exclude);
// }

//  Function to find length of longest increasing subsequence.
// int longestSubsequence(int n, vector<int> &arr)
// {

//     return solve(n, arr, 0, -1);
// }

// Method-2 Recursion + memization
// int solveMemo(int n, vector<int> &arr, int currInd, int prevInd, vector<vector<int>> &dp)
// {
//     // base case
//     if (currInd == n)
//         return 0;

//     if (dp[currInd][prevInd + 1] != -1)
//         return dp[currInd][prevInd + 1];

//     // include
//     int include = 0;
//     if (prevInd == -1 || arr[currInd] > arr[prevInd])
//         include = 1 + solveMemo(n, arr, currInd + 1, currInd, dp);

//     // exclude
//     int exclude = 0 + solveMemo(n, arr, currInd + 1, prevInd, dp);

//     // -1 indx ko handle karne k liye prevInd + 1 karne par
//     return dp[currInd][prevInd + 1] = max(include, exclude);
// }

// // Function to find length of longest increasing subsequence.
// int longestSubsequence(int n, vector<int> &arr)
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return solveMemo(n, arr, 0, -1, dp);
// }

// // Method-3 Tabulation
// int solveTab(int n, vector<int> &arr)
// {
//     vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

//     for (int currInd = n - 1; currInd >= 0; currInd--)
//     {
//         for (int prevInd = currInd - 1; prevInd >= -1; prevInd--)
//         {
//             // include
//             int include = 0;
//             if (prevInd == -1 || arr[currInd] > arr[prevInd])
//                 include = 1 + dp[currInd + 1][currInd+1];

//             // exclude
//             // -1 indx ko handle karne k liye prevInd + 1 karne par
//             int exclude = 0 + dp[currInd+1][prevInd + 1];

//             dp[currInd][prevInd + 1] = max(include, exclude);
//         }
//     }

//     return dp[0][0];
// }

// // Function to find length of longest increasing subsequence.
// int longestSubsequence(int n, vector<int> &arr)
// {
//     return solveTab(n, arr);
// }

//Method- 3 O(n) Tabulation solution
// int solveTab(int n,vector<int> &arr)
// {
//     //create a single array
//     vector<int> dp(n,1);
    
//     int maxi = 1;
//     for(int i=0;i<n;i++)
//     {
//         for(int prev = 0;prev<i;prev++)
//         {
//             if(arr[prev]<arr[i])
//             {
//                 dp[i] = max(dp[i],1+dp[prev]);
//             }
//         }

//         maxi = max(maxi,dp[i]);
//     }

//   return maxi;
// }

// Method-4 Space optimize
// int solveSpa(int n, vector<int> &arr)
// {

//     vector<int> curr(n+1,0);
//     vector<int> next(n+1,0);

//     for (int currInd = n - 1; currInd >= 0; currInd--)
//     {
//         for (int prevInd = currInd - 1; prevInd >= -1; prevInd--)
//         {
//             // include
//             int include = 0;
//             if (prevInd == -1 || arr[currInd] > arr[prevInd])
//                 include = 1 + next[currInd+1];

//             // exclude
//             // -1 indx ko handle karne k liye prevInd + 1 karne par
//             int exclude = 0 + next[prevInd + 1];

//             curr[prevInd + 1] = max(include, exclude);
//         }

//         next = curr;
//     }

//     return next[0];
// }

// // Function to find length of longest increasing subsequence.
// int longestSubsequence(int n, vector<int> &arr)
// {
//     return solveSpa(n, arr);
// }

// Method-5 BinarySearch TC = O(nlogn) Sp = O(n)
int solveBin(int n, vector<int> &arr)
{
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            // find index of just bade element ka in ans array
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, vector<int> &arr)
{
    return solveBin(n, arr);
}

int main()
{
    int n = 16;

    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    cout << "Longest increasing subSeq length is : " << longestSubsequence(n, arr) << endl;

    return 0;
}