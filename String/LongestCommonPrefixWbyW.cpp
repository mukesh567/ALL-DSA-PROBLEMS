
#include <bits/stdc++.h>
using namespace std;

string commonPrefix(vector<string> &arr, int n)
{
    // ans string banane par
    string ans = "";
    // for first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        // first string ka first char uthane par
        char ch = arr[0][i];

        // assume that
        bool match = true;

        // for remaining string me compair karne par
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"geeksforgeeks", "geeks", "geek",
                          "geezer"};
    int n = arr.size();

    string ans = commonPrefix(arr, n);
    

    cout << "The common longest prefix is : " << ans << endl;

    return 0;
}