
#include <bits/stdc++.h>
using namespace std;

void solveDfs( unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)

{
    // store the ans
    ans.push_back(node);

    // mark visited
    visited[node] = 1;

    // her connected node k liye recursive call
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            solveDfs(adj, visited, ans, i);
        }
    }
}


vector<int> DFS(int n, int m)

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

    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            solveDfs(adj, visited, ans, i);
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

    vector<int> result = DFS(n, m);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}