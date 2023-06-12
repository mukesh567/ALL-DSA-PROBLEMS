
#include <bits/stdc++.h>
using namespace std;

bool isCyclicDfs(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    // visited mark the initialy node
    visited[src] = 1;

    // check for neighbour
    for (auto neighbour : adj[src])
    {
        if (!visited[neighbour])
        {
            bool cycleDe = isCyclicDfs(neighbour, src, visited, adj);
            if (cycleDe)
                return true;
        }

        else if (visited[neighbour] == true && neighbour != parent)
        {
            return true;
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
            bool ans = isCyclicDfs(i, -1, visited, adj);

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