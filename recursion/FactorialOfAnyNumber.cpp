
#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int prefac = factorial(n - 1);
        return n * prefac;
    }
}
int main()
{
    int n;
    cin >> n;
    int result = factorial(n);
    cout << result << endl;
    return 0;
}