
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int x = i;

        while (x)
        {
            if (x & 1)
            {
                count++;
            }
            x = x >> 1;
        }
    }

    return count;
}

int main()
{
    int n = 4;

    cout << countSetBits(n) << endl;

    return 0;
}