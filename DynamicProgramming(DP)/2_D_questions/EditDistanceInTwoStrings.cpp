// string 1 ko string 2 convert karne k liye kitne min operation lagenge
//  operation insert,delete,replace

#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// int solve(string word1, string word2, int i, int j)
// {
//     // base cases
//     // word1 chota hai word2 se then word2 k remainning char ans hoga
//     if (i == word1.length())
//         return word2.length() - j;

//     // word2 chota hai word1 se then word1 k remainning char ans hoga
//     if (j == word2.length())
//         return word1.length() - i;

//     int ans = 0;
//     // char match then
//     if (word1[i] == word2[j])
//     {
//         return solve(word1, word2, i + 1, j + 1);
//     }
//     else
//     {
//         // insert
//         int insertAns = 1 + solve(word1, word2, i, j + 1);

//         // delete
//         int deleteAns = 1 + solve(word1, word2, i + 1, j);

//         // replace
//         int replaceAns = 1 + solve(word1, word2, i + 1, j + 1);

//         ans = min(insertAns, min(deleteAns, replaceAns));
//     }

//     return ans;
// }

// int minDistance(string word1, string word2)
// {
//     return solve(word1, word2, 0, 0);
// }

// Method-2 Recursion+memoization
// int solveMemo(string word1, string word2, int i, int j, vector<vector<int>> &dp)
// {
//     // base cases
//     // word1 chota hai word2 se then word2 k remainning char ans hoga
//     if (i == word1.length())
//         return word2.length() - j;

//     // word2 chota hai word1 se then word1 k remainning char ans hoga
//     if (j == word2.length())
//         return word1.length() - i;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int ans = 0;
//     // char match then
//     if (word1[i] == word2[j])
//     {
//         return solveMemo(word1, word2, i + 1, j + 1, dp);
//     }
//     else
//     {
//         // insert
//         int insertAns = 1 + solveMemo(word1, word2, i, j + 1, dp);

//         // delete
//         int deleteAns = 1 + solveMemo(word1, word2, i + 1, j, dp);

//         // replace
//         int replaceAns = 1 + solveMemo(word1, word2, i + 1, j + 1, dp);

//         ans = min(insertAns, min(deleteAns, replaceAns));
//     }

//     return dp[i][j] = ans;
// }

// int minDistance(string word1, string word2)
// {
//     vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
//     return solveMemo(word1, word2, 0, 0, dp);
// }

// Method-3 Tabulation
// int solveTab(string &word1, string &word2)
// {
//     // create vector
//     vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

//     // base case anylissssss
//     for (int j = 0; j < word2.length(); j++)
//     {
//         dp[word1.length()][j] = word2.length() - j;
//     }
//     for (int i = 0; i < word1.length(); i++)
//     {
//         dp[i][word2.length()] = word1.length() - i;
//     }

//     // for remainning
//     for (int i = word1.length() - 1; i >= 0; i--)
//     {
//         for (int j = word2.length() - 1; j >= 0; j--)
//         {
//             int ans = 0;
//             // char match then
//             if (word1[i] == word2[j])
//             {
//                 ans = dp[i + 1][j + 1];
//             }
//             else
//             {
//                 // insert
//                 int insertAns = 1 + dp[i][j + 1];

//                 // delete
//                 int deleteAns = 1 + dp[i + 1][j];

//                 // replace
//                 int replaceAns = 1 + dp[i + 1][j + 1];

//                 ans = min(insertAns, min(deleteAns, replaceAns));
//             }

//             dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }

// int minDistance(string word1, string word2)
// {
//     return solveTab(word1, word2);
// }

int solveSpa(string &word1, string &word2)
{
    // create vector
    vector<int> curr(word2.length() + 1, 0);
    vector<int> next(word2.length() + 1, 0);

    // base case anylissssss
    for (int j = 0; j < word2.length(); j++)
    {
        next[j] = word2.length() - j;
    }

    // for remainning
    for (int i = word1.length() - 1; i >= 0; i--)
    {
        for (int j = word2.length() - 1; j >= 0; j--)
        {
            // ak base case ko yaha handle karne par
            curr[word2.length()] = word1.length() - i;

            int ans = 0;
            // char match then
            if (word1[i] == word2[j])
            {
                ans = next[j + 1];
            }
            else
            {
                // insert
                int insertAns = 1 + curr[j + 1];

                // delete
                int deleteAns = 1 + next[j];

                // replace
                int replaceAns = 1 + next[j + 1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            curr[j] = ans;
        }
    }
    return next[0];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();

    if (word2.length() == 0)
        return word1.length();

    return solveSpa(word1, word2);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2) << endl;

    return 0;
}