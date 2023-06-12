
#include <bits/stdc++.h>
using namespace std;
void reverseStr(string &str, int start, int end)
{
    // base case
    if (start > end)
    {
        return;
    }

    // ek case solve kiya
    swap(str[start], str[end]);
   

    // recursive call
    reverseStr(str, start+1, end-1);
}

int main()
{
    string name = "mukesh";

    reverseStr(name, 0, name.length() - 1);

    cout << name << endl;
    return 0;
}