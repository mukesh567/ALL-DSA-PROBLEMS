// find common count and union

#include <bits/stdc++.h>
using namespace std;

vector<int> findSimilirites(vector<int> v, int n, vector<int> r, int m)
{
    vector<int> ans;
    int common = 0;
    // create a map and push the v elements
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    // r elements present in map or not
    // if present than count++;
    for (int i = 0; i < m; i++)
    {
        if (mp.find(r[i]) != mp.end())
        {
            common++;
        }
    }

    // for union
    int uni = n + m - common;

    ans.push_back(common);
    ans.push_back(uni);
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = v.size();
    vector<int> r = {6, 7, 4, 3, 8, 9};
    int m = r.size();

    vector<int> ans = findSimilirites(v, n, r, m);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}