
#include <bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        st.push(ch);
    }

    string ans = "";
    while (!st.empty())
    {
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout << "Reverse string is : " << ans << endl;
}

int main()
{
    string s = "Mukesh";
    cout << "Before reversing the string : " << s << endl;
    reverse(s);
    return 0;
}