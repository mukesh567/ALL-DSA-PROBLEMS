
// strongly connected components means .....aisa component jiski kisi bhi node ko pakad k uski saari
// nodes ko traverse kar sake

// kosaraju algo step
//  step-1
// sort all the nodes on basis on their finishing time(topological sort)

// step-2
//  transpose graph (means 1->2 then 2<-1)

// step-3
// step-1 par dfs lagake count strongly connected components

#include <bits/stdc++.h>
using namespace std;

void dfsTopSort(int node, stack<int> &st, unordered_map<int, bool> &visited,
                unordered_map<int, list<int>> &adj)
{
    // mark visited
    visited[node] = true;

    // for neighbours
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfsTopSort(nbr, st, visited, adj);
        }
    }

    // call se vaaps aate samay push
    st.push(node);
}

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    // mark visited
    visited[node] = true;

    // for neighbours
    for (auto nbr : transpose[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, visited, transpose);
        }
    }
}

int stronglyConnectedCompo(vector<vector<int>> &edges, int n)
{
    // create adj list for edges
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // step-1 ...topological sort
    stack<int> st;
    unordered_map<int, bool> visited;

    for (int i = 0; i< n; i++)
    {
        if (!visited[i])
        {
            dfsTopSort(i, st, visited, adj);
        }
    }

    // step-2 ....create a tranpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // step-3...dfs call on topo sort and count SCC
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!visited[top])
        {
            count++;
            dfs(top, visited, transpose);
        }
    }

    //return our count answer
    return count;
}

int main()
{
    // number of nodes
    int n = 5;

    vector<vector<int>> edges = {{1, 0},
                                 {0, 2},
                                 {2, 1},
                                 {0, 3},
                                 {3, 4}};

    int ans = stronglyConnectedCompo(edges, n);

    cout << endl
         << "How many components which is strongly connected answer is : " << ans << endl
         << endl;

    return 0;
}