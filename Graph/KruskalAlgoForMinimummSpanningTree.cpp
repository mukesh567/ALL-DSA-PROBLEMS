

#include <bits/stdc++.h>
using namespace std;

// sort basis of weight ....weight is in column third
bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}

void make_set(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// for function to find parent array
// with path compression
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

// find union
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // dono k parent nikal diye
    u = findParent(parent, u);
    v = findParent(parent, v);

    // compare ranks
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // we sort the entire edges vector with u,v and w
    // in the basis of weight
    sort(edges.begin(),edges.end(),cmp);


    // vector for create parent array
    vector<int> parent(n);

    // vector for define rank
    vector<int> rank(n);

    // intialized both of array
    make_set(parent, rank,n);

// sum of weight
   int minWeight = 0;

    //****************kruskal algo logic ************
    for(int i=0;i<edges.size();i++)
    {
        // do nodes uthayenge or inke parent nikalenge 
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);

        // weight
        int wt = edges[i][2];

        // agar dono nodes same nhi hai then 
        // union kar denge
        if(u !=v)
        {
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
    }

    //return the answer
    return minWeight;
}

int main()
{
    // number of nodes
    int n = 4;

    // first column = u, second column = v,third is weight
    vector<vector<int>> edges = {{0, 1, 3},
                                 {0, 3, 5},
                                 {1, 2, 1},
                                 {2, 3, 8}};

    int weightSum = minimumSpanningTree(edges, n);

    cout << endl
         << "Minimum spanning tree jo bana hai uska weight sum : " << weightSum << endl
         << endl;

    return 0;
}
