
#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    // if (n == 0)
    // {
    //     return 0;
    // }
    // if (n == 1)
    // {
    //     return 1;
    // }
    if(n==0|| n==1 )
    {
        return n;
    }
    else
    {
        // int pre = fib(n - 1) + fib(n - 2);
        // return pre;
        return fib(n-1)+fib(n-2);
    }
}
int main()
{
    int n;
    cin >> n;
    int result = fib(n);
    cout << result << endl;
    return 0;
}