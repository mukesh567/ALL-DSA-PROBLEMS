

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int node, unordered_map<int, bool> &visited,
              unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    // first mark visited
    visited[node] = 1;

    // function call visited
    dfsVisited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclic(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
                return true;
        }

        else if (visited[neighbour] == true && dfsVisited[neighbour] == true)
        {
            return true;
        }
    }

    // vaapas jate samay dfsvisited ko false karne par
    dfsVisited[node] = 0;

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
    }

    // for handle disconnected components (bus loop ko n tak chalana hai handle ho jayenge)
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclic(i, visited, dfsVisited, adj);

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

    if (cycleDetect(n, m))
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