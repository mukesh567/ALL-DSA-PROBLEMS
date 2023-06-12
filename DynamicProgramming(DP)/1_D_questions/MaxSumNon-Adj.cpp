
#include <bits/stdc++.h>
using namespace std;

// Method-1....recursion
//  int solve(vector<int> &nums,int n)
//  {
//       //base case
//       if(n<0)
//       {
//          return 0;
//       }

//      if(n==0)
//      {
//         return nums[0];
//      }

//      int include = solve(nums,n-2)+nums[n];
//      int exclude = solve(nums,n-1)+0;

//      return max(include,exclude);
// }

// int maxSum(vector<int> &nums,int n)
// {
//      int ans = solve(nums,n-1);

//      return ans;
// }

// Method - 2 .....Recursion + memoization
//  int solveMemo(vector<int> &nums,int n,vector<int> &dp)
//  {
//      //base case
//      if(n<0)
//      {
//          return 0;
//      }

//     if(n==0)
//     {
//     return nums[0];
// }

// if(dp[n]!=-1)
// {
//     return dp[n];
// }

// int incu = solveMemo(nums,n-2,dp)+nums[n];
// int excl = solveMemo(nums,n-1,dp)+0;

// dp[n]=max(incu,excl);

// return dp[n];

// }

// int maxSum (vector<int> &nums,int n)
// {
//     vector<int> dp(n+1,-1);

//     int ans = solveMemo(nums,n-1,dp);
//     return ans;
// }

// Method-3 ......Tabulation
//  int solveTab(vector<int> &nums)
//  {
//      int n = nums.size();

//      vector<int> dp(n,0);

//      dp[0]=nums[0];

//      for(int i=1;i<n;i++)
//  {
//     int incl = dp[i-2]+nums[i];
//     int excl = dp[i-1]+0;

//     dp[i]=max(incl,excl);
//  }

//  return dp[n-1];
// }

// int maxSum(vector<int> &nums,int n)
// {
//    return solveTab(nums);
// }

// Method-4 .....Space optimize
int solveOp(vector<int> &nums)
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maxSum(vector<int> &nums, int n)
{
    return solveOp(nums);
}
67
int main()
{
    vector<int> nums = {9, 9, 8, 2};

    int n = nums.size();

    cout << maxSum(nums, n) << endl;
    return 0;
}