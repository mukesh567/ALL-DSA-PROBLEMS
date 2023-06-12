
#include<bits/stdc++.h>
using namespace std;

// //Method-1 Recursion
// int solve(int n)
// {
//     //base case
//     if(n==0)
//     {
//         return 0;
//     }

//     //jo bhi perfect squares honge vo n se chote honge
//     int ans = n;
//     for(int i=1;i*i<=n;i++)
//     {
//        ans = min(ans,1+solve(n-i*i));
//     }

//     return ans;
// }

// int minSqu(int n)
// {
//     return solve(n);
// }

//Method-2 Recursion+memoization
// int solveMemo(int n,vector<int> &dp)
// {
//     //base case
//     if(n==0)
//     {
//         return 0;
//     }

//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }

//     //jo bhi perfect squares honge vo n se chote honge
//     int ans = n;
//     for(int i=1;i*i<=n;i++)
//     {
//        ans = min(ans,1+solveMemo(n-i*i,dp));
//     }

//     return dp[n] = ans;
// }

// int minSqu(int n)
// {
//     vector<int> dp(n+1,-1);
//     return solveMemo(n,dp);
// }

//Method-3 Tabulation
int solveTab(int n)
{
     vector<int> dp(n+1,INT_MAX);

     dp[0]=0;

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j*j<=n;j++)
        {
            if(i-j*j>=0)
              dp[i]=min(dp[i],1+dp[i-j*j]);
        }
     }

    return  dp[n];
}

int minSqu(int n)
{
    return solveTab(n);
}

int main()
{
    int n = 5;

    cout<<"How many perfect squares are required for n is : "<<minSqu(n)<<endl;

    return 0;
}