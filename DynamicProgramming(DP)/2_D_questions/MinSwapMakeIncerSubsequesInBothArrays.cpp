
#include <bits/stdc++.h>
using namespace std;

// // Method-1 Recursion
// int solve(vector<int> &arr1, vector<int> &arr2, int index, bool swapped)
// {
//     // base case
//     if (index == arr1.size())
//         return 0;

//     // assign prev value
//     int prev1 = arr1[index - 1];
//     int prev2 = arr2[index - 1];

//     int ans = INT_MAX;

//     // Logic
//     if (swapped)
//         swap(prev1, prev2);

//     // Already in incresing order then
//     // No swap
//     if (arr1[index] > prev1 && arr2[index] > prev2)
//         ans = solve(arr1, arr2, index + 1, 0);

//     // swap logic
//     if (arr1[index] > prev2 && arr2[index] > prev1)
//         ans = min(ans, 1 + solve(arr1, arr2, index + 1, 1));

//     return ans;
// }

// int minSwap(vector<int> &arr1, vector<int> &arr2)
// {
//     // Put -1 in both arrays in beignning
//     arr1.insert(arr1.begin(), -1);
//     arr2.insert(arr2.begin(), -1);

//     return solve(arr1, arr2, 1, 0);
// }

// // Method-2 Recursion+memoization
// int solveMemo(vector<int> &arr1, vector<int> &arr2, int index, bool swapped, vector<vector<int>> &dp)
// {
//     // base case
//     if (index == arr1.size())
//         return 0;

//     // already store ans then return it
//     if (dp[index][swapped] != -1)
//         return dp[index][swapped];

//     // assign prev value
//     int prev1 = arr1[index - 1];
//     int prev2 = arr2[index - 1];

//     int ans = INT_MAX;

//     // Logic
//     if (swapped)
//         swap(prev1, prev2);

//     // Already in incresing order then
//     // No swap
//     if (arr1[index] > prev1 && arr2[index] > prev2)
//         ans = solveMemo(arr1, arr2, index + 1, 0, dp);

//     // swap logic
//     if (arr1[index] > prev2 && arr2[index] > prev1)
//         ans = min(ans, 1 + solveMemo(arr1, arr2, index + 1, 1, dp));

//     return dp[index][swapped] = ans;
// }

// int minSwap(vector<int> &arr1, vector<int> &arr2)
// {
//     // Put -1 in both arrays in beignning
//     arr1.insert(arr1.begin(), -1);
//     arr2.insert(arr2.begin(), -1);

//     vector<vector<int>> dp(arr1.size(), vector<int>(2, -1));
//     return solveMemo(arr1, arr2, 1, 0, dp);
// }

// Method-3 Tabulation
// int solveTab(vector<int> &arr1, vector<int> &arr2)
// {
//     int n = arr1.size();

//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//     for (int index = n - 1; index >= 1; index--)
//     {
//         for (int swapped = 1; swapped >= 0; swapped--)
//         {
//             // assign prev value
//             int prev1 = arr1[index - 1];
//             int prev2 = arr2[index - 1];

//             int ans = INT_MAX;

//             // Logic
//             if (swapped)
//                 swap(prev1, prev2);

//             // Already in incresing order then
//             // No swap
//             if (arr1[index] > prev1 && arr2[index] > prev2)
//                 ans = dp[index + 1][0];

//             // swap logic
//             if (arr1[index] > prev2 && arr2[index] > prev1)
//                 ans = min(ans, 1 + dp[index + 1][1]);

//             dp[index][swapped] = ans;
//         }
//     }

//     return dp[1][0];
// }

// int minSwap(vector<int> &arr1, vector<int> &arr2)
// {
//     // Put -1 in both arrays in beignning
//     arr1.insert(arr1.begin(), -1);
//     arr2.insert(arr2.begin(), -1);

//     return solveTab(arr1, arr2);
// }

// Method-4 space optimiz O(1);
int solveTab(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();

    int swap = 0;
    int noswap = 0;
    int currswap = 0;
    int currnoswap = 0;

    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            // assign prev value
            int prev1 = arr1[index - 1];
            int prev2 = arr2[index - 1];

            int ans = INT_MAX;

            // Logic
            if (swapped)
            {
                int temp = prev2;
                prev2 = prev1;
                prev1 = temp;
            }

            // Already in incresing order then
            // No swap
            if (arr1[index] > prev1 && arr2[index] > prev2)
                ans = noswap;

            // swap logic
            if (arr1[index] > prev2 && arr2[index] > prev1)
                ans = min(ans, 1 + swap);

            if (swapped)
                currswap = ans;
            else
                currnoswap = ans;
        }

        swap = currswap;
        noswap = currnoswap;
    }

    return min(swap, noswap);
}

int minSwap(vector<int> &arr1, vector<int> &arr2)
{
    // Put -1 in both arrays in beignning
    arr1.insert(arr1.begin(), -1);
    arr2.insert(arr2.begin(), -1);

    return solveTab(arr1, arr2);
}

int main()
{
    // 4 or 7 ko swap kar de to ans
    vector<int> arr1 = {1, 3, 5, 4};
    vector<int> arr2 = {1, 2, 3, 7};

    cout << "Minimum swap to make increasing subseq : " << minSwap(arr1, arr2) << endl;

    return 0;
}