
// count distinct subSeq str2 in str1
#include <bits/stdc++.h>
using namespace std;

// Recursion+memoization
// int solveMemo(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
// {
//     // base case
//     // it means all char of str2 match in str1
//     if (j == 0)
//         return 1;

//     // str1 string completed and str2 remaining
//     if (i == 0)
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (str1[i - 1] == str2[j - 1])
//         // ak baar dono ko kam kiya and ak baar str1 ko kam kiya
//         return dp[i][j] = solveMemo(str1, str2, i - 1, j - 1, dp) + solveMemo(str1, str2, i - 1, j, dp);

//     else
//         // only str1 ko kam kiya
//         return dp[i][j] = solveMemo(str1, str2, i - 1, j, dp);
// }

// Tabulation
// int solveTab(string &str1, string &str2)
// {
//     int n = str1.size();
//     int m = str2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (str1[i - 1] == str2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     return dp[n][m];
// }

// Space optimized
int solveSpa(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1] + prev[j];

            else
                curr[j] = prev[j];
        }
        prev = curr;
    }

    return prev[m];
}

int countDistinctSubseq(string &str1, string &str2)
{
    // int n = str1.size();
    // int m = str2.size();

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return solveMemo(str1, str2, n, m, dp);

    // return solveTab(str1, str2);

    return solveSpa(str1,str2);
}

int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "ge";

    cout << countDistinctSubseq(str1, str2) << endl;

    return 0;
}