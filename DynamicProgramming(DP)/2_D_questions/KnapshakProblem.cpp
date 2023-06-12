
#include <bits/stdc++.h>
using namespace std;

// Method-1  recursion

// int solve(vector<int> &weight,vector<int> &value,int index ,int W)
// {
//     //base case
//     if(index==0)
//     {
//         if(weight[0]<=W)
//         {
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }

//     //include
//     int include = 0;
//     if(weight[index]<=W)
//     {
//         include = value[index]+ solve(weight,value,index-1,W-weight[index]);
//     }

//   //exclude
//   int exclude = 0+solve(weight,value,index-1,W);

//   int ans = max(exclude,include);

//   return ans;
// }

// int knapsackPro(vector<int> &weight,vector<int> &value,int n ,int W)
// {
//     return solve(weight,value,n-1,W);
// }

// Method-2 recursion + memoization
//  int solveMemo(vector<int> &weight,vector<int> &value,int index ,int W,vector<vector<int>> &dp)
//  {
//      //base case
//      if(index==0)
//      {
//          if(weight[0]<=W)
//          {
//              return value[0];
//          }
//          else{
//              return 0;
//          }
//      }

//     if(dp[index][W]!=-1)
//     {
//         return dp[index][W];
//     }

//     //include
//     int include = 0;
//     if(weight[index]<=W)
//     {
//         include = value[index]+ solveMemo(weight,value,index-1,W-weight[index],dp);
//     }

//     //exclude
//     int exclude = 0+solveMemo(weight,value,index-1,W,dp);

//     dp[index][W] = max(exclude,include);

//   return dp[index][W];
// }

// int knapsackPro(vector<int> &weight,vector<int> &value,int n ,int W)
// {
//     vector<vector<int>> dp(n,vector<int> (W+1,-1));
//     return solveMemo(weight,value,n-1,W,dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     // create dp array
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//     // base case analize
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             dp[0][w] = value[0];
//         }
//         else
//         {
//             dp[0][w] = 0;
//         }
//     }

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             // include
//             int include = 0;
//             if (weight[index] <= w)
//             {
//                 include = value[index] + dp[index - 1][w - weight[index]];
//             }

//             // exclude
//             int exclude = 0 + dp[index - 1][w];

//             dp[index][w] = max(exclude, include);
//         }
//     }

//     return dp[n - 1][capacity];
// }

// int knapsackPro(vector<int> &weight, vector<int> &value, int n, int W)
// {

//     return solveTab(weight, value, n, W);
// }


//Method-4 space optimize-1
// int solveSpa1(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<int> prev(capacity+1);
//     vector<int> curr(capacity+1);

//     // base case analize
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             prev[w] = value[0];
//         }
//         else
//         {
//             prev[w] = 0;
//         }
//     }

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             // include
//             int include = 0;
//             if (weight[index] <= w)
//             {
//                 include = value[index] + prev[w - weight[index]];
//             }

//             // exclude
//             int exclude = 0 + prev[w];

//             curr[w] = max(exclude, include);
//         }
//         prev=curr;
//     }

//     return prev[capacity];
// }

// int knapsackPro(vector<int> &weight, vector<int> &value, int n, int W)
// {

//     return solveSpa1(weight, value, n, W);
// }


//Method-5 space optimize-2
int solveSpa2(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> curr(capacity+1);

    // base case analize
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >=0; w--)
        {
            // include
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w - weight[index]];
            }

            // exclude
            int exclude = 0 + curr[w];

            curr[w] = max(exclude, include);
        }
    }

    return curr[capacity];
}

int knapsackPro(vector<int> &weight, vector<int> &value, int n, int W)
{

    return solveSpa2(weight, value, n, W);
}


int main()
{
    int n = 4;
    int W = 5;

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    cout << knapsackPro(weight, value, n, W) << endl;

    return 0;
}