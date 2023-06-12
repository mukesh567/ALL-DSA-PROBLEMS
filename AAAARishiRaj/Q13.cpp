
// Q 13. write a program to print Fibonacci sequence up to n terms using recursion.

#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}
int main()
{
    int n;
    cout<<"Enter the n terms : ";
    cin >> n;
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        cout << fib(i) << " ";
        i++;
    }
    return 0;
}