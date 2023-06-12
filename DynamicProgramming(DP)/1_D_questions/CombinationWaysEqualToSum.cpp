
#include <bits/stdc++.h>
using namespace std;

// // Method-1 recursion
// int solve(vector<int> &arr, int target)
// {
//     // base case
//     if (target == 0)
//     {
//         return 1;
//     }

//     if (target < 0)
//     {
//         return 0;
//     }

//     int cnt = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cnt += solve(arr, target - arr[i]);
//     }

//     return cnt;
// }

// int findAllWays(vector<int> &arr, int target)
// {

//     return solve(arr, target);
// }

// // Method-2 recursion+memoization
// int solveMemo(vector<int> &arr, int target,vector<int> &dp)
// {
//     // base case
//     if (target == 0)
//     {
//         return 1;
//     }

//     if (target < 0)
//     {
//         return 0;
//     }

//     if(dp[target]!=-1)
//     {
//         return dp[target];
//     }

//     int cnt = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cnt += solveMemo(arr, target - arr[i],dp);
//     }

//     return dp[target]=cnt;
// }

// int findAllWays(vector<int> &arr, int target)
// {
    
//    vector<int> dp(target+1,-1);
//     return solveMemo(arr, target,dp);
// }


// Method-3 Tabulation
int solveTab(vector<int> &arr, int target)
{

    vector<int> dp(target+1,0);

    dp[0]=1;


    for(int i=1;i<=target;i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(i-arr[j]>=0)
              dp[i]+= dp[i-arr[j]];
        }
    }
   
    return dp[target];
}

int findAllWays(vector<int> &arr, int target)
{
    return solveTab(arr, target);
}

int main()
{
    vector<int> arr = {7,2,6,5};
    int target = 16;

    cout << "Count of the all the combination whose sum equal to given sum :" << findAllWays(arr, target) << endl;

    return 0;
}