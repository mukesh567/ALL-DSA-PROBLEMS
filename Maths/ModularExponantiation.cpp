
#include <bits/stdc++.h>
using namespace std;

int modularExpo(int x, int n, int m)
{
    long long int res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // odd
            res = ((res) * (x) % m) % m;
        }

        x = ((x) % m * (x) % m) % m;

        //divide by 2
        n = n >> 1;
    }
    return res;
}

int main()
{
    int x;
    cout << "Enter base : ";
    cin >> x;

    int n;
    cout << "Enter power : ";
    cin >> n;

    int m;
    cout << "Enter m : ";
    cin >> m;

    cout << "" << modularExpo(x, n, m) << endl;
    return 0;
}