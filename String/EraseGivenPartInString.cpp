
#include <bits/stdc++.h>
using namespace std;

string removePart(string str, string part)
{
    while (str.length() != 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }
    return str;
}

int main()
{
    string str = "abcdabcabc";
    string part;
    cout << "Enter string who you want to delete it :";
    cin >> part;
    cout << "New string is : " << removePart(str, part) << endl;
    return 0;
}