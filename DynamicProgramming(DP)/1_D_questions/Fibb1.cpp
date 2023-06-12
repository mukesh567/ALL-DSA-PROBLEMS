


#include <bits/stdc++.h>
using namespace std;

// Top-down approach (recursion + memoization)
int fibb(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    // if already you have answer then simply return
    //  step-3
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step-2
    dp[n] = fibb(n - 1, dp) + fibb(n - 2, dp);

    return dp[n];
}

// bottom-up Approach (tabulation)

// int fibb(int n)
// {
//     //  step-1
//     vector<int> dp(n + 1);

//     // step-2  base case observe karne par
//     dp[0] = 0;
//     dp[1] = 1;

//     // step-3  rest of k liye
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }


//Space-Optimize
// int fibb(int n)
// {
//     // create only 2 variables
//     int prev1 = 1;
//     int prev2 = 0;

//     // rest of task
//     for (int i = 2; i <= n; i++)
//     {
//         int curr = prev1 + prev2;

//         // shifting
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     // return the ans
//     return prev1;
// }

int main()
{
    int n;
    cout << "Enter the number which is you want to find nth fibbonacci number : ";
    cin >> n;

    // create a dp array to store prev ans and intilized with -1
    //  step-1
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    int fib = fibb(n, dp);

    cout << "Answer is : " << fib << endl;

    return 0;
}