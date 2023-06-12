
#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.second == b.second.second)
    {
        return a.first < b.first;
    }

    return a.second.second < b.second.second;
}

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    // return index number array where meeting is possible
    vector<int> ans;

    vector<pair<int, pair<int, int>>> v;

    for (int i = 0; i < N; i++)
    {
        v.push_back({i + 1, {S[i], F[i]}});
    }

    sort(v.begin(), v.end(), cmp);

    ans.push_back(v[0].first);
    int ansEnd = v[0].second.second;

    for (int i = 1; i < N; i++)
    {
        if (v[i].second.first > ansEnd)
        {
            ans.push_back(v[i].first);
            ansEnd = v[i].second.second;
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};

    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> ans = maxMeetings(N, start, end);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
