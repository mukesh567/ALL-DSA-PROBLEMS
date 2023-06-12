
#include <bits/stdc++.h>
using namespace std;

// Tabulation of LIS
void printLongestSubsequence(int n, vector<int> &arr)
{
    // create a single array
    vector<int> dp(n, 1);
    vector<int> v(n, -1);

    int maxi = 1;
    int lastIndex = -1;

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                v[i] = prev;

                if (dp[i] > maxi)
                {
                    dp[i] = maxi;
                    lastIndex = i;
                }
            }
        }
    }

    vector<int> temp;
    while (lastIndex != -1)
    {
        temp.push_back(arr[lastIndex]);
        lastIndex = v[lastIndex];
    }

    reverse(temp.begin(), temp.end());
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n = 16;

    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    printLongestSubsequence(n, arr);

    return 0;
}