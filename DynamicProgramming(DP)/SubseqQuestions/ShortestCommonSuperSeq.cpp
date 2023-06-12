
#include <bits/stdc++.h>
using namespace std;

// Longest common subseq
int solveSpa(string &str1, string &str2)
{
    vector<int> curr(str2.length() + 1, 0);
    vector<int> next(str2.length() + 1, 0);

    for (int i = str1.length() - 1; i >= 0; i--)
    {
        for (int j = str2.length() - 1; j >= 0; j--)
        {
            // char match then add 1 and call recursive
            int ans = 0;
            if (str1[i] == str2[j])
            {
                ans = 1 + next[j + 1];
            }
            // not match then ak baar i ko aage and ak baar j ko aage badhake
            //  jo max hai return karne par
            else
            {
                ans = max((next[j]), (curr[j + 1]));
            }

            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int lcSubseq(string &str1, string &str2)
{
    return solveSpa(str1, str2);
}

int superSeqLength(string &str1, string &str2)
{
    int LongestCommSubseq = lcSubseq(str1, str2);

    int n = str1.length();
    int m = str2.length();

    return n + m - LongestCommSubseq;
}

int main()
{
    string str1 = "abcd";
    string str2 = "xycd";

    cout << superSeqLength(str1, str2) << endl;

    return 0;
}