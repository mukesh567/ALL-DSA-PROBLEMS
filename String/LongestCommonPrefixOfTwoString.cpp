
#include <bits/stdc++.h>
using namespace std;

vector<int> commonPrefix(string str1, string str2)
{
    int currInd = 0;
    int indexEnd = 0;

    for (int i = 0; i < str2.length(); i++)
    {
        if (str2[i] == str1[currInd])
        {
            currInd++;
            if (currInd > indexEnd)
            {
                indexEnd = currInd;
            }
        }
        else if (currInd != 0)
        {
            currInd = 0;
            i--;
        }
    }

    if (indexEnd == 0)
    {
        return {-1, -1};
    }
    else
    {
        return {0, --indexEnd};
    }
}

int main()
{
    string str1 = "geek";
    string str2 = "dgeek";

    vector<int> ans = commonPrefix(str1, str2);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}