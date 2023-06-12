
#include <bits/stdc++.h>
using namespace std;

void reverseString(string s)
{
    vector<string> temp;
    string str = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp.push_back(str);
            str = "";
        }
        else
        {
            str += s[i];
        }
    }

    // last vala word ko bhi daalo
    temp.push_back(str);

    // print the string
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main()
{

    string s = "My name is mukesh kumar";

    cout << endl;

    reverseString(s);

    cout << endl;

    return 0;
}