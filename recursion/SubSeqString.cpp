
#include <bits/stdc++.h>
using namespace std;
void subseq(string str, string ans)
{
    if (str.length() == 0)
    {

        cout << ans << endl;
        return;
    }
    char ch = str[0];
    string ros = str.substr(1);

    // exclude case
    subseq(ros, ans);

    // include case
    subseq(ros, ans + ch);
}
int main()
{
    string str = "gfg";
    subseq(str, "");
    return 0;
}