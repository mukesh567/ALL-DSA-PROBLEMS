
#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int presum = sum(n - 1);
        return n + sum(n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    int result = sum(n);
    cout << result << endl;
    return 0;
}