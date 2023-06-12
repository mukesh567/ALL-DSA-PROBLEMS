#include <bits/stdc++.h>

using namespace std;

// Method-1  recursion
//  int countDerangement(int n)
// {
//     // base cases
//     if (n == 1)
//     {
//         return 0;
//     }

//     if (n == 2)
//     {
//         return 1;
//     }

//     int ans = (n - 1) * (countDerangement(n - 1) + countDerangement(n - 2));
//     return ans;
// }

// Method-2 recursion+memoization
//  int solveMemo(int n,vector<int> &dp)
//  {
//      //base cases
//      if(n==1)
//      {
//          return 0;
//      }

//     if(n==2)
// {
//     return 1;
// }

// if(dp[n]!=-1)
// {
//         return dp[n];
//     }

//     dp[n]=(n-1)*(solveMemo(n-1,dp)+solveMemo(n-2,dp));

//     return dp[n];
// }

// int countDerangement(int n)
// {
//     vector<int> dp(n+1,-1);

//     return solveMemo(n,dp);
// }

// Method-3 Tabulation
//  int solveTab(int n)
//  {
//      vector<int> dp(n+1,0);
//      dp[1]=0;
//      dp[2]=1;

//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
//     }

//     return dp[n];
// }

// int countDerangement(int n)
// {
//     return solveTab(n);
// }

// Method-4 space optimize
int spaceOpti(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int ans = (i - 1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int countDerangement(int n)
{
    return spaceOpti(n);
}

int main()
{
    int n;
    cout << "Enter a range !";
    cin >> n;

    cout << countDerangement(n) << endl;
    return 0;
}