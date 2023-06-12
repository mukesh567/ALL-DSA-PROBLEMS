
// using Kahn's Algorithm
#include <bits/stdc++.h>
using namespace std;

int cycleDetect(int n, int m)
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
    int cnt = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // increase the cnt
        cnt++;

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

    if (cnt == n)
    {
        // means it is the topological sort(Acyclic directed graph)
        return 0;
    }
    else
    {
        return 1;
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

    if (cycleDetect(n, m))
    {
        cout << " cycle is  present ! " << endl
             << endl;
    }
    else
    {
        cout << " cycle is not present ! " << endl
             << endl;
    }

    return 0;
}