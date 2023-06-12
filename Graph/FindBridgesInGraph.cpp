
#include <bits/stdc++.h>
using namespace std;
int timer = 1;


void dfs(int node, int parent, int tim[], int low[], vector<vector<int>> &bridges,
        vector<int> adj[], vector<int> &vis)
{
    // mark the true
    vis[node] = true;

    // starting me disc or low ka timer vo he hoga baad me increase
    tim[node] = low[node] = timer;
    timer++;

    // for neighbour
    for (auto neighbour : adj[node])
    {
        // agar dono same then ignore it
        if (neighbour == parent)
        {
            continue;
        }

        if (!vis[neighbour])
        {
            // dfs call for neighbour
            dfs(neighbour, node, tim, low, bridges, adj, vis);

            // call se vaapas aate samay update the low
            low[node] = min(low[node], low[neighbour]);

            // check is bridge or not
            if (low[neighbour] > tim[node])
                bridges.push_back({node,neighbour});
            
        }

        else
        {
            // already visited and not a parent then
            // back edge vala case
            low[node] = min(low[node], low[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n)
{
    // for adjacency list
    vector<int> adj[n];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // much need more data structure
    int tim[n];
    int low[n];
    vector<int> vis(n,0);

    // our main answer
    vector<vector<int>> bridges;
    
    //If number of compo is only  one
    // do dfs
    dfs(0,-1, tim, low, bridges, adj, vis);

    return bridges;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {2, 0},
                                 {1, 3}
                                 };

    vector<vector<int>> ans = findBridges(edges, n);
     
 
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}