
#include <bits/stdc++.h>
using namespace std;

// Method-1 Recursion
// int solve(int n)
// {
//     // base case
//     if (n <= 1)
//         return 1;

//     // think i as root node
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         ans += solve(i - 1) * solve(n - i);
//     }

//     return ans;
// }

// int uniqueBST(int n)
// {
//     return solve(n);
// }

// // Method-2 Recursion+memoization
// int solve(int n, vector<int> &dp)
// {
//     // base case
//     if (n <= 1)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];

//     // think i as root node
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         ans += solve(i - 1, dp) * solve(n - i, dp);
//     }

//     return dp[n] = ans;
// }

// int uniqueBST(int n)
// {
//     vector<int> dp(n + 1, -1);
//     return solve(n, dp);
// }

// Method-3 Tabulation
int solve(int n)
{

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;
     
     // i no. of nodes
    for (int i = 2; i <= n; i++)
    {
        // j root node
        for (int j = 1; j <= i; j++)
        {
            dp[i] += solve(j - 1) * solve(i - j);
        }
    }

    return dp[n];
}

int uniqueBST(int n)
{
    return solve(n);
}

int main()
{
    int n = 3;

    cout << "For n unique bst is : " << uniqueBST(n) << endl;

    return 0;
}