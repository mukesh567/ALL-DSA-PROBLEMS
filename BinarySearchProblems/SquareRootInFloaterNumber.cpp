

#include <bits/stdc++.h>
using namespace std;

long long int SquareRootInt(int n)
{
    int start = 0, end = n;

    long long int ans = -1;
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        long long int Square = mid * mid;

        if (Square == n)
        {
            return mid;
        }
        if (Square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

double morePrecision(int n, int intSol, int precision)
{
    double factor = 1;
    double ans = intSol;

    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter any number who you want to find squere root for that : ";
    cin >> n;

    int intSol = SquareRootInt(n);

    cout << "Squere root : " << morePrecision(n, intSol, 3) << endl;
    return 0;
}
