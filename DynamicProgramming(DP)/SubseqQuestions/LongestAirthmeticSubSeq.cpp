
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(int index, int diff, vector<int> &arr)
// {
//     // base case
//     if (index < 0)
//         return 0;

//     int ans = 0;
//     for (int j = index - 1; j >= 0; j--)
//     {
//         if (arr[index] - arr[j] == diff)
//             ans = max(ans, 1 + solve(j, diff, arr));
//     }
//     return ans;
// }

// int maxLength(vector<int> &arr, int n)
// {
//     if (n <= 2)
//         return n;

//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ans = max(ans, 2 + solve(i, arr[j] - arr[i], arr));
//         }
//     }
//     return ans;
// }

// Method-2 Recursion+memoization
// int solveMemo(int index, int diff, vector<int> &arr, unordered_map<int, int> dp[])
// {
//     // base case
//     if (index < 0)
//         return 0;

//     if (dp[index].count(diff))
//     {
//         return dp[index][diff];
//     }

//     int ans = 0;
//     for (int j = index - 1; j >= 0; j--)
//     {
//         if (arr[index] - arr[j] == diff)
//             ans = max(ans, 1 + solveMemo(j, diff, arr, dp));
//     }
//     return dp[index][diff] = ans;
// }

// int maxLength(vector<int> &arr, int n)
// {
//     if (n <= 2)
//         return n;

//     // har index par bahut saare diff honge or unki length (diff,length)
//     unordered_map<int, int> dp[n + 1];
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ans = max(ans, 2 + solveMemo(i, arr[j] - arr[i], arr, dp));
//         }
//     }
//     return ans;
// }

//Method-3 Tabulation
int maxLength(vector<int> &arr, int n)
{
    if (n <= 2)
        return n;

    // har index par bahut saare diff honge or unki length (diff,length)
    unordered_map<int, int> dp[n + 1];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
           int diff = arr[i]-arr[j];
           int count=1;

           //check if ans already present
           if(dp[j].count(diff))
             count = dp[j][diff];

             dp[i][diff]=1+count;

             ans = max(ans,dp[i][diff]);
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {1, 7, 10, 13, 14, 19};
    int n = arr.size();

    cout << "Longest arithmetic subSeq length is : " << maxLength(arr, n) << endl;
}