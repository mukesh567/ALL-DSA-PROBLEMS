
#include <bits/stdc++.h>
using namespace std;

int add(int a, int b)
{
    return (a % 1000000007 + b % 1000000007) % 1000000007;
}

int multi(int a, int b)
{
    return ((a % 1000000007) * 1LL * (b % 1000000007)) % 1000000007;
}

// Method-1 recursion
// int solve(int n, int k)
// {
//     // base case
//     if (n == 1)
//     {
//         return k;
//     }

//     if (n == 2)
//     {
//         return add(k,multi(k,k-1));
//     }

//     int ans = add(multi(solve(n-2,k),k-1),multi(solve(n-1,k),k-1));

//     return ans;
// }

// int NumberOfCountWays(int n, int k)
// {
//     return solve(n, k);
// }


//Method-2 recursion+memoization
// int solveMemo(int n, int k,vector<int> &dp)
// {
//     // base case
//     if (n == 1)
//     {
//         return k;
//     }

//     if (n == 2)
//     {
//         return add(k,multi(k,k-1));
//     }

//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }

//     dp[n] = add(multi(solveMemo(n-2,k,dp),k-1),multi(solveMemo(n-1,k,dp),k-1));

//     return dp[n];
// }

// int NumberOfCountWays(int n, int k)
// {
//     vector<int> dp(n+1,-1);
//     return solveMemo(n, k,dp);
// }


//Method-3 Tabulation
// int solveTab(int n, int k)
// {
//     vector<int> dp(n+1,0);

//     dp[1]=k;
//     dp[2]=add(k,multi(k,k-1));

//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=add(multi(dp[i-2],k-1),multi(dp[i-1],k-1));
//     }
    
//     return dp[n];
// }

// int NumberOfCountWays(int n, int k)
// {
    
//     return solveTab(n, k);
// }

//Method-4  space optimized
int solveSpa(int n, int k)
{
    int prev2=k;
    int prev1=add(k,multi(k,k-1));

    for(int i=3;i<=n;i++)
    {
        int ans=add(multi(prev2,k-1),multi(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }
    
    return prev1;
}

int NumberOfCountWays(int n, int k)
{
    
    return solveSpa(n, k);
}


int main()
{
    int n = 3;
    int k = 2;

    cout << NumberOfCountWays(n, k) << endl;
}