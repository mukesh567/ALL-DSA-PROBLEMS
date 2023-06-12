
#include <bits/stdc++.h>
using namespace std;

int findsetPos(int n)
{
    if (n == 0)
    {
        return -1;
    }
    
    if ((n & (n - 1)) == 0)
    {
        int count = 0;
        while (n)
        {
            count++;
            n = n >> 1;
        }

        return count;
    }

    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout << "enter a number : ";
    cin >> n;

    int ans = findsetPos(n);
    cout << "Set bit position is : " << ans << endl;
    return 0;
}