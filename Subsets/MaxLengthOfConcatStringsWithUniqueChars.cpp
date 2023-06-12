
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &selected, string &currStr)
{
    vector<int> selfCheck(26, 0);

    for (int i = 0; i < currStr.size(); i++)
    {
        if (selfCheck[currStr[i] - 'a'] == 1)
            return false;
        selfCheck[currStr[i] - 'a'] = 1;
    }

    for (int i = 0; i < currStr.size(); i++)
    {
        if (selected[currStr[i] - 'a'] == 1)
            return false;
    }

    return true;
}

int helper(int i, vector<string> &arr, vector<int> &selected, int len)
{
    if (i == arr.size())
        return len;


    string currStr = arr[i];

    if (compare(selected, currStr) == false)
    {
        //agar like aise ccw string ho to skip this string only repeating char vaali
        return helper(i + 1, arr, selected, len);
    }
    else
    {
        // picked
        for (int j = 0; j < currStr.size(); j++)
        {
            selected[currStr[j] - 'a'] = 1;
        }

        len += currStr.size();

        int op1 = helper(i + 1, arr, selected, len);

        // skip
        for (int j = 0; j < currStr.size(); j++)
        {
            selected[currStr[j] - 'a'] = 0;
        }

        len -= currStr.size();

        int op2 = helper(i + 1, arr, selected, len);

        return max(op1, op2);
    }
}

int maxLength(vector<string> &arr)
{
    vector<int> selected(26, 0);

    return helper(0, arr, selected, 0);
}

int main()
{
    vector<string> arr = {"un", "qe", "uk"};

    // max unique string is unqe with length 4
    int length = maxLength(arr);

    cout << endl
         << "Maximum length to concat strings with unique characters is : " << length << endl
         << endl;

    return 0;
}