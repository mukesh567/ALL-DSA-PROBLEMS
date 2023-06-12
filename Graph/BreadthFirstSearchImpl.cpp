
#include <bits/stdc++.h>
using namespace std;

void solveBfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
              vector<int> &ans, int node)
{
    // mark visited
    visited[node] = 1;

    // than push in queue
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // push into the ans
        ans.push_back(frontNode);

        // frontNodes neighboures traverseing
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int n, int m)
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
            solveBfs(adj, visited, ans, i);
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

    vector<int> ans = BFS(n, m);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}