
#include <bits/stdc++.h>
using namespace std;

long long int SquareRoot(int n)
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

int main()
{
    int n;
    cout << "Enter any number who you want to find squere root for that : ";
    cin >> n;

    cout << "Squere root : " << SquareRoot(n) << endl;
    return 0;
}
