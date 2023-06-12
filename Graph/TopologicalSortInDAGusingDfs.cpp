
#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    // first we mark visited
    visited[node] = 1;

    // for neighbour
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, s, adj);
        }
    }

    // function call se vaapas jate samay stack me push kar do value
    s.push(node);
}

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

    // store our answer
    vector<int> ans;

    // for visited mark
    unordered_map<int, bool> visited;

    // function call se vaapas jate samay stack me push kar do value
    stack<int> s;

    // for handle all the components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    // answer store in stack
    // than push our answer in ans vector
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    // return our final answer
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