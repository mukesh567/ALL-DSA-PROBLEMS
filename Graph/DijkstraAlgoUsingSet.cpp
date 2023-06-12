
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int n, int m)
{
    // create a adj list for weighted undirected graph
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // input the source node
    int src;
    cout << "Enter the source node where from you need to find out shortest dist : " << endl;
    cin >> src;

    // create a distance array with size n and sabhi ko infinite mark karne par
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    // create a set  (nodeDistance,topNode)
    set<pair<int, int>> s;

    // intialized src with zero distance and insert into set with zero distance
    dist[src] = 0;

    s.insert(make_pair(0, src));

    // while set not empty
    while (!s.empty())
    {
        // fetch top record
        auto top = *(s.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record from set
        s.erase(s.begin());

        // for neighbour
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found on set than erase it
                if (record != s.end())
                {
                    s.erase(record);
                }

                // update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // than insert new pair
                s.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector<int> ans = shortestDistance(n, m);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}