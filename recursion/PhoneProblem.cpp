
#include <bits/stdc++.h>
using namespace std;

void printStr(string &digit, string mapping[], string &output, int index, vector<string> &ans)
{
    // base case
    if (index >= digit.length())
    {
        ans.push_back(output);
        return ;
    }

    // input string ka number nikalne par
    int number = digit[index] - '0';
    // ye number kisse mapp hai vo nikalne par
    string mapp = mapping[number];

    for (int i = 0; i < mapp.length(); i++)
    {
        output.push_back(mapp[i]);
        printStr(digit, mapping, output, index + 1, ans);
        output.pop_back();
    }
}

int main()
{
    string digit = "23";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output ;
    int index = 0;

    vector<string> ans;
    printStr(digit, mapping, output, index, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}