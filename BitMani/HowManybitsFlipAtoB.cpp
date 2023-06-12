
#include <bits/stdc++.h>
using namespace std;

int countFlipBit(int a, int b)
{
    int value = a ^ b;
    int c = 0;
    while (value)
    {
        if (value & 1)
        {
            c++;
        }
        value = value >> 1;
    }
    return c;
}

int main()
{
    int a = 10; // 01010
    int b = 20; // 10100

    int ans = countFlipBit(a, b);
    cout << endl
         << "A to B convert karne me how many bits are flip : " << ans << endl
         << endl;
    return 0;
}