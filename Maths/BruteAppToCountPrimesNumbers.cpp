
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countNumbers(int n)
{
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter your range who you want to count in between prime numbers : ";
    cin >> n;

    cout << "Total prime numbers are : " << countNumbers(n) << endl;

    return 0;
}