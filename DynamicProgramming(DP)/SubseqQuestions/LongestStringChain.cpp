
#include <bits/stdc++.h>
using namespace std;

bool checkPossibleStrings(string &str1, string &str2)
{
    // check length
    // always length .....1+ of str2 length
    if (str1.length() != str2.length() + 1)
        return false;

    // for first string
    int i = 0;

    // for second string
    int j = 0;

    while (i < str1.size())
    {
        if (j < str2.size() && str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    if (i == str1.size() && j == str2.size())
        return true;

    return false;
}

bool cmp(string &s1,string &s2)
{
    return s1.size() < s2.size();
}

// Logic from longest increasing subSeq
int solveTab(int n, vector<string> &arr)
{
    //sort according to size of strings
    sort(arr.begin(),arr.end(),cmp);

    // create a single array
    vector<int> dp(n, 1);

    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossibleStrings(arr[i], arr[prev]))
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int longestStringChain(vector<string> &words)
{
    int n = words.size();
    return solveTab(n, words);
}

int main()
{
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout << longestStringChain(words) << endl;
    return 0;
}