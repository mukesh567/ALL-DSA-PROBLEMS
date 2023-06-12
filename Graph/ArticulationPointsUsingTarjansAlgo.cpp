

#include <bits/stdc++.h>
using namespace std;
int timer = 1;


void dfs(int node, int parent, int tim[], int low[], vector<int> &Ap,
        vector<int> adj[], vector<int> &vis)
{
    // mark the true
    vis[node] = true;

    // starting me disc or low ka timer vo he hoga baad me increase
    tim[node] = low[node] = timer;
    timer++;

    // jab first node k liye hai jab child 1 se jyada ho to
    //  vo ak Ap hai
    int child = 0;

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
            dfs(neighbour, node, tim, low, Ap, adj, vis);

            // call se vaapas aate samay update the low
            low[node] = min(low[node], low[neighbour]);

            // check is bridge or not
            // check is Ap or not
            if (low[neighbour] >= tim[node] && parent != -1)
            {
                Ap[node] = 1;
            }
            child++;
        }

        else
        {
            // already visited and not a parent then
            // back edge vala case
            low[node] = min(low[node], tim[neighbour]);
        }
    }

    // agar root node he Ap ho then
    if (parent == -1 && child > 1)
    {
        Ap[node] = 1;
    }
}


vector<int> findAp(vector<vector<int>> &edges, int n)
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
    vector<int> Ap(n,0);
    
    //If number of compo is only  one
    // do dfs
    dfs(0,-1, tim, low, Ap, adj, vis);

    return Ap;
}

int main()
{
    // 4 in this example
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    vector<vector<int>> edges = {
        {4, 3},
        {0, 1},
        {4, 2},
        {1, 4},
        {3, 2}};

    vector<int> Ap = findAp(edges, n);

    cout << "Articulation points are : ";
    for (int i = 0; i < Ap.size(); i++)
    {
        if (Ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}