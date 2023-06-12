
#include <bits/stdc++.h>
using namespace std;
// Using longest increasing subseq solution you can esily
// understood with this problem
vector<int> solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> v(n, -1);

    int maxi = 1;
    int lastIndex = -1;

    // This is the main part of this ques
    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                v[i] = prev;
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
    }

    vector<int> temp;

    while (lastIndex != -1)
    {
        temp.push_back(arr[lastIndex]);
        lastIndex = v[lastIndex];
    }

    return temp;
}

vector<int> printLDS(vector<int> &arr)
{
    return solveTab(arr);
}

int main()
{
    vector<int> arr = {1, 4, 7, 8, 16};

    vector<int> ans = printLDS(arr);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}