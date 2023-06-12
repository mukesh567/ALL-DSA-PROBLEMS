
#include <bits/stdc++.h>
using namespace std;

bool reduntantOrNot(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // agar ch ak closing bracket ho
            if (ch == ')')
            {
                bool isRedunt = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedunt = false;
                    }
                    st.pop();
                }
                if (isRedunt == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    // (+-*/)
    string str;
    cin >> str;

    if (reduntantOrNot(str))
    {
        cout << "Redunt bracket is present !" << endl;
    }
    else
    {
        cout << "Redunt bracket is Not present !" << endl;
    }
    return 0;
}