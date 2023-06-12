
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int minFar = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        minFar = min(minFar, prices[i]);
        int profit = prices[i] - minFar;
        maxProfit = max(maxProfit, profit);
    }

    cout << maxProfit << endl;

    return 0;
}