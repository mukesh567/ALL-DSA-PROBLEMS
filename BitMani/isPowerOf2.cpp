
#include <bits/stdc++.h>
using namespace std;
bool isPowerOf2(int n)
{
    if(n==0)
    {
        return false;
    }
    if((n & (n-1) )==0)
    {
        return true;
    }
    return false;
}
int main()
{
    cout << isPowerOf2(4) << endl;
    return 0;
}