
#include <bits/stdc++.h>
using namespace std;
int longestSubsequence(vector<int> &arr, int difference)
{

    unordered_map<int, int> dp;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // piche es diff vala koi ans pada hai kya
        int temp = arr[i] - difference;
        int tempAns = 0;
        if (dp.count(temp))
            tempAns = dp[temp];

        // Current ans ko update
        dp[arr[i]] = 1 + dp[temp];

        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int diff = -2;

    cout << longestSubsequence(arr, diff) << endl;
    
    return 0;
}