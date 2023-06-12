
// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
// Currently, it’s Monday, and she needs to survive for the next S days.
// Find the minimum number of days on which you need to buy food from the
// shop so that she can survive the next S days, or determine that it isn’t possible to survive.

#include <bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M)
{
    // sunday nikal do
    int sunday = S / 7;

    int buyDays = S - sunday;

    int TotalFood = S * M;

    int ans = 0;
    if (TotalFood % N == 0)
    {
        ans = TotalFood / N;
    }
    else
    {
        ans = TotalFood / N + 1;
    }

    if (ans <= buyDays)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // Number of days to survive
    int S = 10;

    // Number of food you buy a each day
    int N = 16;

    // unit of food each day to survive
    int M = 2;

    cout << minimumDays(S, N, M) << endl;
    return 0;
}