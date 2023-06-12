
#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
// {
//     // base case
//     if (i >= mat.size() || j >= mat[0].size())
//         return 0;

//     int right = solve(mat, i, j + 1, maxi);
//     int daigonal = solve(mat, i + 1, j + 1, maxi);
//     int down = solve(mat, i + 1, j, maxi);

//     if (mat[i][j] == 1)
//     {
//         int ans = 1 + min(right, min(daigonal, down));
//         maxi = max(maxi, ans);
//         return ans;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int largestSquare(vector<vector<int>> &mat)
// {
//     int maxi = 0;
//     solve(mat, 0, 0, maxi);
//     return maxi;
// }

// Method-2 Recursion+memoization
// int solveMemo(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
// {
//     // base case
//     if (i >= mat.size() || j >= mat[0].size())
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int right = solveMemo(mat, i, j + 1, maxi, dp);
//     int daigonal = solveMemo(mat, i + 1, j + 1, maxi, dp);
//     int down = solveMemo(mat, i + 1, j, maxi, dp);

//     if (mat[i][j] == 1)
//     {
//         dp[i][j] = 1 + min(right, min(daigonal, down));
//         maxi = max(maxi, dp[i][j]);
//         return dp[i][j];
//     }
//     else
//     {
//         return dp[i][j] = 0;
//     }
// }

// int largestSquare(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     int maxi = 0;
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     solveMemo(mat, 0, 0, maxi, dp);
//     return maxi;
// }

// Method-3 Tabulation
// int solveTab(vector<vector<int>> &mat, int &maxi)
// {
//     int n = mat.size();
//     int m = mat[0].size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = m - 1; j >= 0; j--)
//         {

//             int right = dp[i][j + 1];
//             int daigonal = dp[i + 1][j + 1];
//             int down = dp[i + 1][j];

//             if (mat[i][j] == 1)
//             {
//                 dp[i][j] = 1 + min(right, min(daigonal, down));
//                 maxi = max(maxi, dp[i][j]);
//             }
//             else
//             {
//                 dp[i][j] = 0;
//             }

//         }
//     }

//     return dp[0][0];
// }

// int largestSquare(vector<vector<int>> &mat)
// {
//     int maxi = 0;
//     solveTab(mat, maxi);
//     return maxi;
// }

// Method-4 space optimize O(m)
//  int solveSpa(vector<vector<int>> &mat, int &maxi)
//  {
//      int n = mat.size();
//      int m = mat[0].size();

//     vector<int> curr(m+1);
//     vector<int> next(m+1);

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = m - 1; j >= 0; j--)
//         {

//             int right = curr[j + 1];
//             int daigonal = next[j + 1];
//             int down = next[j];

//             if (mat[i][j] == 1)
//             {
//                 curr[j] = 1 + min(right, min(daigonal, down));
//                 maxi = max(maxi, curr[j]);
//             }
//             else
//             {
//                 curr[j] = 0;
//             }

//         }

//         next = curr;
//     }

//     return next[0];
// }

// int largestSquare(vector<vector<int>> &mat)
// {
//     int maxi = 0;
//     solveSpa(mat, maxi);
//     return maxi;
// }

// Method-5 space optimize O(1)
int solveSpace_optimiz(vector<vector<int>> &mat, int &maxi)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int right = j < m - 1 ? mat[i][j + 1] : 0;
            int diag = i < n - 1 && j < m - 1 ? mat[i + 1][j + 1] : 0;
            int down = i < n - 1 ? mat[i + 1][j] : 0;

            if (mat[i][j] == 1)
            {
                mat[i][j] = 1 + min(down, min(right, diag));
                maxi = max(mat[i][j], maxi);
            }
        }
    }

    return maxi;
}

int largestSquare(vector<vector<int>> &mat)
{
    int maxi = 0;
    solveSpace_optimiz(mat, maxi);
    return maxi;
}

int main()
{
    // matrix will be n*m
    vector<vector<int>> mat = {{1, 1}, {1, 1}};

    cout << largestSquare(mat) << endl;
    
    return 0;
}