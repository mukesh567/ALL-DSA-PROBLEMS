
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int start, int end)
{
    // base case
    if (start > end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        return checkPalindrome(str, start + 1, end - 1);
    }
}

int main()
{

    string name = "sass";

    if (checkPalindrome(name, 0, name.length() - 1))
    {
        cout << "String is palindromic ! " << endl;
    }
    else
    {
        cout << "String is not palindromic !" << endl;
    }
    return 0;
}