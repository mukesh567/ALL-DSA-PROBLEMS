
#include <bits/stdc++.h>
using namespace std;

// Method 1....Recursion

// int solve (vector<int> &num,int target)
// {
//     //base case
//     if(target==0)
//     {
//         return 0;
//     }

//     if(target<0)
//     {
//         return INT_MAX;
//     }

//     int mini = INT_MAX;

//     for(int i=0;i<num.size();i++)
// {
//     int ans = solve(num,target-num[i]);
//     if(ans!=INT_MAX)
//     {
//        mini = min(mini,1+ans);
//          }
//      }
//      return mini;
//  }

// int minCoins(vector<int> &num,int target)
// {
//     int ans = solve(num,target);
//     if(ans==INT_MAX)
//     {
//         return -1;
//     }
//     return ans;
// }

// Method 2....Recursion + memoization
// int solveMemo(vector<int> &num, int target, vector<int> &dp)
// {
//     // base case
//     if (target == 0)
//     {
//         return 0;
//     }

//     if (target < 0)
//     {
//         return INT_MAX;
//     }

//     if (dp[target] != -1)
//     {
//         return dp[target];
//     }

//     int mini = INT_MAX;

//     for (int i = 0; i < num.size(); i++)
//     {
//         int ans = solveMemo(num, target - num[i], dp);
//         if (ans != INT_MAX)
//         {
//             mini = min(mini, 1 + ans);
//         }
//     }
//     dp[target] = mini;
//     return mini;
// }

// int minCoins(vector<int> &num, int target)
// {
//     vector<int> dp(target + 1, -1);

//     int ans = solveMemo(num, target, dp);
//     if (ans == INT_MAX)
//     {
//         return -1;
//     }
//     return ans;
// }

// Method 3...Tabulation
int solveTab(vector<int> &num,int target)
{
     vector<int> dp(target+1,INT_MAX);
     dp[0]=0;

     for(int i=1;i<=target;i++)
     {

        for(int j=0;j<num.size();j++)
        {
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
     }

     if(dp[target]==INT_MAX)
     {
        return -1;
     }
     else
     {
        return dp[target];
     }
}

int minCoins(vector<int> &num,int target)
{
    return solveTab(num,target);
}

int main()
{
    vector<int> num = {1, 2, 3};
    int target = 7;

    cout << minCoins(num, target) << endl;

    return 0;
}