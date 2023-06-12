
#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    // base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    // recursive call
    int ans = power(a, b / 2);

    if (b & 1)
    {
        // b is odd
        return a * ans * ans;
    }
    else
    {
        // b is even
        return ans * ans;
    }
}

int main()
{
    int a, b;

    cout << "Enter base : ";
    cin >> a;

    cout << "Enter power : ";
    cin >> b;

    cout << power(a, b) << endl;
    return 0;
}