
#include <bits/stdc++.h>
using namespace std;
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        int prepower = power(n, p - 1);
        return n * prepower;
    }
}
int main()
{
    int n, p;
    cin >> n >> p;
    int result = power(n, p);
    cout<<result<<endl;
    return 0;
}