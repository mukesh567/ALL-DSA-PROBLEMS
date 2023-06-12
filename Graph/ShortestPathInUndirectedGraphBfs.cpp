

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m)
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

    // input of our src and dest
    int src;
    cout << "Enter source value :";
    cin >> src;

    int dest;
    cout << "Enter destination value :";
    cin >> dest;

    // Do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;

    // push the intial value in queue(src is our first value)
    q.push(src);

    // mark
    visited[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // for neighbour
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    // prepare our ans in parent vaale map se
    // start with destination node

    vector<int> ans;

    int currNode = dest;
    ans.push_back(dest);

    while (currNode != src)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    // reverse our answer
    reverse(ans.begin(), ans.end());

    // return the ans
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

    vector<int> ans = shortestPath(n, m);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    return 0;
}