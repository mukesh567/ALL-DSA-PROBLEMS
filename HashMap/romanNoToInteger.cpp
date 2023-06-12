
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string &str)
{
    int count = 0;
    int prevInt = 0;

    // map all the roman with integer
    unordered_map<char, int> con = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    // iterate string from the right most
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];

        // es char k corresponding value is
        int currInt = con[ch];

        if (currInt >= prevInt)
        {
            count += currInt;
        }
        else
        {
            count -= currInt;
        }

        prevInt = currInt;
    }
    return count;
}

int main()
{
    // 10 + 10 + 5 = 25
    string str = "XXV";

    cout << "Converted integer value is : " << romanToInt(str) << endl;
    return 0;
}