
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    // make pair and sort the data according to end Time
    vector<pair<int, int>> v;
    for (int i = 0; i < start.size(); i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    // sort according to end time
    sort(v.begin(), v.end(), cmp);

    // pehli meeting kar li hai then
    int count = 1;
    int ansEnd = v[0].second;

    for (int i = 1; i < start.size(); i++)
    {
        // agar pehli meeting ka ending time agli vaali se kam
        //  hai then update
        if (v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};

    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum meetings is : " << maxMeetings(start, end) << endl;

    return 0;
}