#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto v : adj[u])
        {
            if (dist[v.first] > d + v.second)
            {
                dist[v.first] = d + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    return dist;
}
