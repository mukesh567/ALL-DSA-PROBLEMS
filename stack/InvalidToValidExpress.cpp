
#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfBracktesCountToMakeStringValid(string &str)
{
    // agar closing brackets or opening brackets odd ho (cb=3 ,ob = 2 total length=5)
    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    // valid part hatane par
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            // ch is closing bracket
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                // opening bracket huya he nhi
                st.push(ch);
            }
        }
    }

    // invalid expression ka count nikal k
    // a is the count of closeing brackets
    // b is the count of opening brackets
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str = "{{{{{}";

    cout << endl;
    int ans = minimumNumberOfBracktesCountToMakeStringValid(str);

    cout << "String ko valid banane k liye how many brackets ko reverse karna padega ...ans is : " << ans << endl;
    cout << endl;

    return 0;
}