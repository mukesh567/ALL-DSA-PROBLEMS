
#include <bits/stdc++.h>
using namespace std;

char getMaxOcc(string s)
{
    int arr[26] = {0};

    // create an array to count characters

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    // find maximum occurence charater
    int max = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            ans = i;
            max = arr[i];
        }
    }
    
    return 'a' + ans;
}

int main()
{

    string s;
    cout << "Enter your string : ";
    cin >> s;

    cout << "Maximum occurence character is : " << getMaxOcc(s) << endl;
    return 0;
}