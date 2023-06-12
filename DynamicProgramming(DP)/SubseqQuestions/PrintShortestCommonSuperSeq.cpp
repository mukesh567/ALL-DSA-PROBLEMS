
#include <bits/stdc++.h>
using namespace std;

// Logic  from Print Longest common subSeq
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

    // int length = dp[n][m];
    string ans = "";

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += str1[i - 1];
            i--;
        }

        else
        {
            ans += str2[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string superSeqPrint(string &str1, string &str2)
{
    return solveTab(str1, str2);
}

int main()
{
    string str1 = "abcd";
    string str2 = "xycd";

    string ans = superSeqPrint(str1, str2);

    cout << "Shortest common SuperSeq is : " << ans << endl;

    return 0;
}