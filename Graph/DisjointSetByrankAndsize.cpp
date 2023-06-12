
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUparent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ul_parent_u = findUparent(u);
        int ul_parent_v = findUparent(v);

        if (ul_parent_u == ul_parent_v)
            return;

        if (rank[ul_parent_u] < rank[ul_parent_v])
            parent[ul_parent_u] = ul_parent_v;

        else if (rank[ul_parent_u] > rank[ul_parent_v])
            parent[ul_parent_v] = ul_parent_u;

        else
        {
            parent[ul_parent_v] = ul_parent_u;
            rank[ul_parent_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ul_parent_u = findUparent(u);
        int ul_parent_v = findUparent(v);

        if (ul_parent_u == ul_parent_v)
            return;

        if (size[ul_parent_u] < size[ul_parent_v])
        {
            parent[ul_parent_u] = ul_parent_v;
            size[ul_parent_v] += size[ul_parent_u];
        }

        else
        {
            parent[ul_parent_v] = ul_parent_u;
            size[ul_parent_u] += size[ul_parent_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // check
    // 3 and 7 in same component or not
    if (ds.findUparent(3) == ds.findUparent(7))
        cout << "In same component" << endl;

    else
        cout << "Not in same component" << endl;

    ds.unionByRank(3, 7);

    if (ds.findUparent(3) == ds.findUparent(7))
        cout << "In same component" << endl;

    else
        cout << "Not in same component" << endl;

    return 0;
}