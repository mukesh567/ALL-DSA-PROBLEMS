
#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter your range who you want to count in between prime numbers : ";
    cin >> n;

    cout << "Total prime numbers are : " << countPrimes(n) << endl;

    return 0;
}