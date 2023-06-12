
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(string &str, string &pat, int i, int j)
// {
//     // base cases
//     //  dono string puri travres ho jaye
//     if (i < 0 && j < 0)
//         return 1;

//     // string bachi ho and pattern vaali string puri ho jaye
//     if (i >= 0 && j < 0)
//         return 0;

//     // pattern vaali bachi ho or string puri ho jaye
//     // To there is two case
//     // first is ....agr pattern me last me *(Empty k sath replace) bacha ho to valid nhi to invalid
//     if (i < 0 && j >= 0)
//     {
//         for (int k = 0; k <= j; k++)
//         {
//             if (pat[k] != '*')
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

//     // Condition 1...Match
//     if (str[i] == pat[j] || pat[j] == '?')
//     {
//         return solve(str, pat, i - 1, j - 1);
//     }

//     // Condition 2...Pat me * ho there is two case
//     else if (pat[j] == '*')
//     {
//         //* replace with any char like *(any char)
//         //j pointer remain same but i pointer decrease beacuse match and decrease
//         int cond1= solve(str, pat, i - 1, j);

//         //* replace with empty char
//         //j pointer decrease and i pointer remain same beacuse not match till now
//         int cond2 =solve(str, pat, i, j - 1);

//         return cond1 || cond2;
//     }

//     //Condition 3...Not match
//     else
//     {
//         return 0;
//     }
// }

// int matchWildCard(string str, string pattern)
// {
//     return solve(str, pattern, str.length() - 1, pattern.length() - 1);
// }

// Method-2 Recursion+memoization
// int solveMemo(string &str, string &pat, int i, int j, vector<vector<int>> &dp)
// {
//     // base cases
//     //  dono string puri travres ho jaye
//     if (i == 0 && j == 0)
//         return 1;

//     // string bachi ho and pattern vaali string puri ho jaye
//     if (i > 0 && j == 0)
//         return 0;

//     // pattern vaali bachi ho or string puri ho jaye
//     // To there is two case
//     // first is ....agr pattern me last me *(Empty k sath replace) bacha ho to valid nhi to invalid
//     if (i == 0 && j > 0)
//     {
//         for (int k = 1; k <= j; k++)
//         {
//             if (pat[k - 1] != '*')
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // Condition 1...Match
//     if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
//     {
//         return dp[i][j] = solveMemo(str, pat, i - 1, j - 1, dp);
//     }

//     // Condition 2...Pat me * ho there is two case
//     else if (pat[j - 1] == '*')
//     {
//         //* replace with any char like *(any char)
//         // j pointer remain same but i pointer decrease beacuse match and decrease
//         int cond1 = solveMemo(str, pat, i - 1, j, dp);

//         //* replace with empty char
//         // j pointer decrease and i pointer remain same beacuse not match till now
//         int cond2 = solveMemo(str, pat, i, j - 1, dp);

//         return dp[i][j] = cond1 || cond2;
//     }

//     // Condition 3...Not match
//     else
//     {
//         return 0;
//     }
// }

// int matchWildCard(string str, string pattern)
// {
//     // for 1 base indexing
//     vector<vector<int>> dp(str.length() + 1, vector<int>(pattern.length() + 1, -1));
//     return solveMemo(str, pattern, str.length(), pattern.length(), dp);
// }

// Method-3 Tabulation
// int solveTab(string &str, string &pat)
// {
//     vector<vector<int>> dp(str.length() + 1, vector<int>(pat.length() + 1, 0));

//     // base cases anylisis
//     dp[0][0] = 1;

//     // pattern vaali bachi ho or string puri ho jaye
//     // To there is two case
//     // first is ....agr pattern me last me *(Empty k sath replace) bacha ho to valid nhi to invalid
//     for (int j = 1; j <= pat.length(); j++)
//     {
//         bool flag = 1;
//         for (int k = 1; k <= j; k++)
//         {
//             if (pat[k - 1] != '*')
//             {
//                 flag = 0;
//                 break;
//             }
//         }
//         dp[0][j];
//     }

//     // For remainning
//     for (int i = 1; i <= str.length(); i++)
//     {
//         for (int j = 1; j <= pat.length(); j++)
//         {
//             // Condition 1...Match
//             if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
//             {
//                 dp[i][j] = dp[i - 1][j - 1];
//             }

//             // Condition 2...Pat me * ho there is two case
//             else if (pat[j - 1] == '*')
//             {
//                 //* replace with any char like *(any char)
//                 // j pointer remain same but i pointer decrease beacuse match and decrease
//                 int cond1 = dp[i - 1][j];

//                 //* replace with empty char
//                 // j pointer decrease and i pointer remain same beacuse not match till now
//                 int cond2 = dp[i][j - 1];

//                 dp[i][j] = cond1 || cond2;
//             }

//             // Condition 3...Not match
//             else
//             {
//                 dp[i][j] = 0;
//             }
//         }
//     }

//     return dp[str.length()][pat.length()];
// }

// int matchWildCard(string str, string pattern)
// {
//     // for 1 base indexing
//     return solveTab(str, pattern);
// }

// Method-4 Space Opimize
int solveSpa(string &str, string &pat)
{

    vector<int> prev(pat.length() + 1, 0);
    vector<int> curr(pat.length() + 1, 0);
    // base cases anylisis
    prev[0] = 1;

    // pattern vaali bachi ho or string puri ho jaye
    // To there is two case
    // first is ....agr pattern me last me *(Empty k sath replace) bacha ho to valid nhi to invalid
    for (int j = 1; j <= pat.length(); j++)
    {
        bool flag = 1;
        for (int k = 1; k <= j; k++)
        {
            if (pat[k - 1] != '*')
            {
                flag = 0;
                break;
            }
        }
        prev[j];
    }

    // For remainning
    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 1; j <= pat.length(); j++)
        {
            // Condition 1...Match
            if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }

            // Condition 2...Pat me * ho there is two case
            else if (pat[j - 1] == '*')
            {
                //* replace with any char like *(any char)
                // j pointer remain same but i pointer decrease beacuse match and decrease
                int cond1 = prev[j];

                //* replace with empty char
                // j pointer decrease and i pointer remain same beacuse not match till now
                int cond2 = curr[j - 1];

                curr[j] = cond1 || cond2;
            }

            // Condition 3...Not match
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return prev[pat.length()];
}

int matchWildCard(string str, string pattern)
{
    // for 1 base indexing
    return solveSpa(str, pattern);
}

int main()
{
    string str = "baaabab";

    // ‘?’ – matches any single character
    // ‘*’ – Matches any sequence of characters(including the empty sequence)
    string pattern = "ba*a?";

    if (matchWildCard(str, pattern))
    {
        cout << "Pattern match with string !" << endl;
    }
    else
    {
        cout << "Not matching ! " << endl;
    }

    return 0;
}