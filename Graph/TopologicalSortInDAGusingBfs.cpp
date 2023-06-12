
// using Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, int m)
{
    // create the adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indgree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indgree[j]++;
        }
    }

    // zero indegree vaalo ko queue me push kar do
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indgree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do Bfs
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // check for neighbour
        for (auto neighbour : adj[frontNode])
        {
            indgree[neighbour]--;
            if (indgree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector<int> ans = topologicalSort(n, m);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}