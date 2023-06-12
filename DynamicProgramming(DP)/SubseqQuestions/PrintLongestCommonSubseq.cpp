
#include <bits/stdc++.h>
using namespace std;

// DP array Length de dega
string solveTab(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[n][m];
    string ans = "";

    // asign dummy value
    for (int i = 0; i < length; i++)
    {
        ans += "$";
    }

    int ind = length-1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i-1] == str2[j-1])
        {
            ans[ind] = str1[i-1];
            ind--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
             i--;

        else
          j--;     
    }

    return ans;
}

int main()
{
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";

    string ans = solveTab(str1, str2);
    cout << ans << endl;

    return 0;
}