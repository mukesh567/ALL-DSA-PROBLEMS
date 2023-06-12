
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(string &str1, string &str2, int i, int j)
// {
//     // base case
//     if (i == str1.length() || j == str2.length())
//         return 0;

//     // char match then add 1 and call recursive
//     int ans = 0;
//     if (str1[i] == str2[j])
//     {
//         ans = 1 + solve(str1, str2, i + 1, j + 1);
//     }
//     // not match then ak baar i ko aage and ak baar j ko aage badhake
//     //  jo max hai return karne par
//     else
//     {
//         ans = max((solve(str1, str2, i + 1, j)), (solve(str1, str2, i, j + 1)));
//     }

//     return ans;
// }

// int lcSubseq(string str1, string str2)
// {
//     return solve(str1, str2, 0, 0);
// }

// Method-2 Recursion+memoization
// int solveMemo(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
// {
//     // base case
//     if (i == str1.length() || j == str2.length())
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // char match then add 1 and call recursive
//     int ans = 0;
//     if (str1[i] == str2[j])
//     {
//         ans = 1 + solveMemo(str1, str2, i + 1, j + 1, dp);
//     }
//     // not match then ak baar i ko aage and ak baar j ko aage badhake
//     //  jo max hai return karne par
//     else
//     {
//         ans = max((solveMemo(str1, str2, i + 1, j, dp)), (solveMemo(str1, str2, i, j + 1, dp)));
//     }

//     return dp[i][j] = ans;
// }

// int lcSubseq(string str1, string str2)
// {
//     vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
//     return solveMemo(str1, str2, 0, 0, dp);
// }

// Method-3 Tabulation
int solveTab(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = str1.length() - 1; i >= 0; i--)
    {
        for (int j = str2.length() - 1; j >= 0; j--)
        {
            // char match then add 1 and call recursive
            int ans = 0;
            if (str1[i] == str2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            // not match then ak baar i ko aage and ak baar j ko aage badhake
            //  jo max hai return karne par
            else
            {
                ans = max((dp[i + 1][j]), (dp[i][j + 1]));
            }

            dp[i][j] = ans;
        }
    }

   

    return dp[0][0];
}

int lcSubseq(string str1, string str2)
{
    return solveTab(str1, str2);
}

// Space optimize
// int solveSpa(string &str1, string &str2)
// {
//     vector<int> curr(str2.length() + 1, 0);
//     vector<int> next(str2.length() + 1, 0);

//     for (int i = str1.length() - 1; i >= 0; i--)
//     {
//         for (int j = str2.length() - 1; j >= 0; j--)
//         {
//             // char match then add 1 and call recursive
//             int ans = 0;
//             if (str1[i] == str2[j])
//             {
//                 ans = 1 + next[j + 1];
//             }
//             // not match then ak baar i ko aage and ak baar j ko aage badhake
//             //  jo max hai return karne par
//             else
//             {
//                 ans = max((next[j]), (curr[j + 1]));
//             }

//             curr[j] = ans;
//         }
//         next = curr;
//     }

//     return next[0];
// }

// int lcSubseq(string str1, string str2)
// {
//     return solveSpa(str1, str2);
// }

int main()
{
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";

    cout << lcSubseq(str1, str2) << endl;
    return 0;
}