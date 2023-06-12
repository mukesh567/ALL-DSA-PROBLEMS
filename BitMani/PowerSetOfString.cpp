
#include <bits/stdc++.h>
using namespace std;

vector<string> FindSubSeq(string str)
{
    vector<string> ans;

    int n = pow(2, str.length());

    // loop 2 ki power n -1 tak
    for (int i = 1; i < n; i++)
    {
        int x = i; // first number uthane par
        string s = "";

        int j = 0; // string ka index
        while (x)
        {
            if (x & 1)
            {
                s = s + str[j];
            }
            j++;
            x = x >> 1;
        }
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str = "abc";

    vector<string> ans = FindSubSeq(str);
    cout << "All possible power set is : " << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
    cout << endl;
    return 0;
}