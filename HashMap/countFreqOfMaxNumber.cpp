
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> count;

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    int maxi = INT_MIN;
    int ans = -1;

    for (auto i : count)
    {
        if (maxi < i.second)
        {
            maxi = i.second;
            ans = i.first;
        }
    }

    cout << "Maximum frequency element is : " << ans << endl;
    return 0;
}