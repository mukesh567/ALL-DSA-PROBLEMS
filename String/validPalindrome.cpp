
#include <bits/stdc++.h>
using namespace std;

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string str)
{
    int start = 0, end = str.length() - 1;

    while (start <= end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        else
        {
            start++, end--;
        }
    }
    return 1;
}

bool isValidPalindrome(string s)
{
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }
    return checkPalindrome(temp);
}

int main()
{
    string s = "A man, a plan, a canal:panama";

    if (isValidPalindrome(s))
    {
        cout << "String is palindromic !" << endl;
    }
    else
    {
        cout << "String is not palindromic !" << endl;
    }

    return 0;
}