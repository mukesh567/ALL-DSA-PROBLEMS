
#include <bits/stdc++.h>

using namespace std;

int primesieve(int n)
{
    int prime[n] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++)
    {

        if (prime[i] == 0)
        {
            // cout<<i<<" ";
            count++;
        }
    }
    // cout<<endl;
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << "Total number of prime numbers in between n : " << primesieve(n) << endl;
    return 0;
}