
#include <bits/stdc++.h>
using namespace std;

// T-C O(n)
// S-C O(1)

int minCost(vector<int> &days, vector<int> &cost)
{
    int ans = 0;

    // create queue days,cost
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        // step-1 remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // step-2 add cost for current day
        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));

        // step-3 update the answer
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int main()
{
    vector<int> days = {1, 3, 4, 5, 7, 8, 10};

    // 1day 7day 30day  cost
    vector<int> cost = {2, 7, 20};

    cout << minCost(days, cost) << endl;
    return 0;
}