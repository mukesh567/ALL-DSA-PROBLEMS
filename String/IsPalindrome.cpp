
#include <bits/stdc++.h>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool isPalindrome(char ch[], int n)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        if (ch[start] != ch[end])
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

int main()
{
    char ch[20];
    cout << "Enter your string who you want : ";
    cin >> ch;

    int n = getLength(ch);

    if (isPalindrome(ch, n))
    {
        cout << "String is palindromic !" << endl;
    }
    else
    {
        cout << "String is not palindromic !" << endl;
    }
    return 0;
}