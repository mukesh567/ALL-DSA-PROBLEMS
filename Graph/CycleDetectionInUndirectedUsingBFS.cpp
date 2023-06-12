
#include <bits/stdc++.h>
using namespace std;

bool isCyclicBfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    // create parent map to handle parent ele
    unordered_map<int, int> parent;

    // initialy src ka koi parent nhi hoga to  set -1
    parent[src] = -1;

    // visited true karne par
    visited[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }

            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour] = frontNode;
            }
        }
    }

    return false;
}

bool cycleDetect(int n, int m)
{
    // create the adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for handle disconnected components (bus loop ko n tak chalana hai handle ho jayenge)
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBfs(i, visited, adj);

            if (ans == true)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;



    if (cycleDetect(n,m))
    {
        cout << " cycle is present ! " << endl
             << endl;
    }

    else
    {
        cout << " cycle is not present ! " << endl
             << endl;
    }

    return 0;
}