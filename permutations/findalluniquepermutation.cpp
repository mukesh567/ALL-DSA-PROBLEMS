
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void Alluniquepermutation(vector<int> &a, int idx)
{

    if (idx >= a.size())
    {
        ans.push_back(a);
        return;
    }

    unordered_set<int> s;
    for (int i = idx; i < a.size(); i++)
    {
        if (s.find(a[i]) != s.end())
            continue;
            
        s.insert(a[i]);

        swap(a[i], a[idx]);
        Alluniquepermutation(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

int main()
{

    vector<int> a = {1, 2, 1};

    Alluniquepermutation(a, 0);

    for (auto v : ans)
    {
        for (auto i : v)

            cout << i << " ";
        cout << endl;
    }

    return 0;
}