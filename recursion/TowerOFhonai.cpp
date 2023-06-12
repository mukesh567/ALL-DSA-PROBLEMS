
#include <bits/stdc++.h>
using namespace std;
void towertohonai(int n, char src, char des, char helper)
{
    if (n == 0)
    {
        return;
    }
    towertohonai(n - 1, src, helper, des);
    cout << "move from" << src << "to" << des<<endl;
    towertohonai(n - 1, helper, des, src);
}
int main()
{
    towertohonai(3, 'A', 'C', 'B');
    return 0;
}