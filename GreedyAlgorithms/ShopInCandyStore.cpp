
#include <bits/stdc++.h>
using namespace std;
// Now you have to answer two questions. Firstly, you have to find what is the minimum amount
// of money you have to spend to buy all the N different candies. Secondly, you have to find
// what is the maximum amount of money you have to spend to buy all the N different candies.

pair<int, int> candyStore(vector<int> &candies, int K)
{
    int N = candies.size();
    sort(candies.begin(), candies.end());

    // mini
    int mini = 0;
    int buy = 0;
    int free = N - 1;

    while (buy <= free)
    {
        mini = mini + candies[buy];
        buy++;
        free = free - K;
    }

    // maxi
    int maxi = 0;
    buy = N - 1;
    free = 0;

    while (free <= buy)
    {
        maxi = maxi + candies[buy];
        buy--;
        free = free + K;
    }

    return {mini, maxi};
}

int main()
{

    vector<int> candies = {3, 2, 1, 4};
    // You can buy a single candy from the store
    // and get at most K other candies ( all are different types ) for free.
    int k = 2;

    pair<int, int> ans = candyStore(candies, k);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}