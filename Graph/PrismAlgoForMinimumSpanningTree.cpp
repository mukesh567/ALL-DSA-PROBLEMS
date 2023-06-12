
// graph se aisa tree banao jisme n nodes ho or edges n-1 ho this is spanning tree
// minimum spanning tree is jiske weight ka sum sabse minimum ho
// prism algorithm

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> minimumSpanningTree(int n, int m)
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

    // we are need three data structure
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    // sabhi ko intialized karne par
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // lets start the prism algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // find the min node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // our answer is ready in parent array
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector<pair<pair<int, int>, int>> ans = minimumSpanningTree(n, m);

    for(auto i : ans)
    {
        cout<<i.first.first<<"-"<<i.first.second<<" "<<i.second<<endl;
    }
    cout << endl;
    return 0;
}

// n = 5 m =14
// 1 2 2
// 1 4 6
// 2 1 2
// 2 3 3
// 2 4 8
// 2 5 5
// 3 2 3
// 3 5 7
// 4 1 6
// 4 2 8
// 4 5 9
// 5 2 5
// 5 3 7
// 5 4 9