#include <bits/stdc++.h>
using namespace std;
vector<int> zeroOneBFS(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    deque<int> dq;
    vector<int> dist(V, INT_MAX);
    dq.push_front(src);
    dist[src] = 0;
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        for (auto v : adj[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                if (v.second == 0)
                    dq.push_front(v.first);
                else
                    dq.push_back(v.first);
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}
