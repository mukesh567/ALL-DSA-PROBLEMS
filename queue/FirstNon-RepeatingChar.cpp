
#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeatingChar(string str)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // char ka count store karne par
        count[ch]++;

        // char ko queue me daal do
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating char hai
                q.pop();
            }
            else
            {
                // non-reapeating char hai
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{

    string str = "aabc";

    string ans = FirstNonRepeatingChar(str);
    cout << "New string is : " << ans << endl;
    return 0;
}