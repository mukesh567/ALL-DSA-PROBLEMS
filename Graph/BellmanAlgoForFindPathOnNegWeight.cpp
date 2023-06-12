
// Apply only directed negative weight but their is no negative cycle is present
// Or agar Undirected graph ho then convert kar do directed me fir same process apply
// if negative cycle present then we have not eligble to find shortest path 😥
// but their is no negative cycle then eligble 😍

#include <bits/stdc++.h>
using namespace std;

// return src or dest k shortest path k weight - karne par
int shortestPath(int n, int src, int dest, vector<vector<int>> &edges)
{
    // create dist array (indexing 1 base )
    vector<int> dist(n + 1, 1e9);

    // dist of source
    dist[src] = 0;

    // traverse n-1 nodes
    for (int i = 1; i <= n; i++)
    {
        // traverse all edges
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + w) < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative cycle
    bool flag = 0;
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + w) < dist[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        // no negative cycle
        return dist[dest];
    }

    // Nagetive cycle present
    return -1;
}

int main()
{
    // number of nodes
    int n = 5;

    // int src to dest
    int src = 1;
    int dest = 3;

    vector<vector<int>> edges = {{1, 2, 2},
                                 {1, 3, 2},
                                 {2, 3, -1}};

    int ans = shortestPath(n, src, dest, edges);

    cout << endl
         << "Answer is : " << ans << endl
         << endl;

    return 0;
}