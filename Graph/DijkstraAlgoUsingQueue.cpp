//   T.C => Elog(V);
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int n, int m)
{
    // create a adj list for weighted undirected graph
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // input the source node
    int src;
    cout << "Enter the source node where from you need to find out shortest dist : " << endl;
    cin >> src;

    //Make a distance array
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    //Create a priority queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    //first for src node
    dist[src] =0;

    //push dist and src node
    pq.push({0,src});

    while(!pq.empty())
    {
        int dis  = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node])
        {
            int adjWeight = it.second;
            int adjNode = it.first;

            if(dis + adjWeight < dist[adjNode])
            {
                dist[adjNode] = dis + adjWeight;
                pq.push({ dist[adjNode],adjNode});
            }
        }
    }

   return dist;
}



int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector<int> ans = shortestDistance(n, m);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}