
#include <bits/stdc++.h>
using namespace std;

class graph
{

public:
    // for adj list with weight
    unordered_map<int, list<pair<int, int>>> adj;

    void addEge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    // print our list with weight
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "],";
            }
            cout << endl;
        }
    }

    // for find topological sort
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        // first we mark the visited
        visited[node] = 1;

        // for neighbour
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, s);
            }
        }

        // vaapas jate samay stack me add kar do
        s.push(node);
    }

    // for getshortest path
    void getShortestPath(int src, vector<int> &dist, stack<int> &s)
    {
        // initialized distance of src
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            // agar distance !=infinite
            if (dist[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEge(0, 1, 5);
    g.addEge(0, 2, 3);
    g.addEge(1, 2, 2);
    g.addEge(1, 3, 6);
    g.addEge(2, 3, 7);
    g.addEge(2, 4, 4);
    g.addEge(2, 5, 2);
    g.addEge(3, 4, -1);
    g.addEge(4, 5, -2);

    g.printAdj();

    // we must need number of nodes
    int n = 6;

    // for topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    // for which source
    int src = 1;

    // our distance array
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    // call our main function
    g.getShortestPath(src, dist, s);

    cout << "Our shortest path is : " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}