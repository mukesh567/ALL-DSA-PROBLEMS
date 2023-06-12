
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction ==0  , undirected graph
        // direction==1  , directed graph
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    // creating a graph obj
    graph g;

    // creating edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // insert the edges
        g.addEdge(u, v, 0);
    }

    cout << endl
         << "All Nodes according their edges : " << endl;
    g.printAdjList();

    return 0;
}