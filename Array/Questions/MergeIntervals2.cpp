
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());

    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[idx].second >= a[i].first)
        {
            // Merge previous and current Intervals
            a[idx].second = max(a[idx].second, a[i].second);
            a[idx].first = min(a[idx].first, a[i].first);
        }
        else
        {
            idx++;
            a[idx] = a[i];
        }
    }

    for (int i = 0; i <= idx; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}