#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    for (int i = 1; i < V; i++)
    {
        for (auto e : edges)
        {
            if (dist[e[0]] != 1e9 &&
                dist[e[1]] > dist[e[0]] + e[2])
            {
                dist[e[1]] = dist[e[0]] + e[2];
            }
        }
    }
    for (auto e : edges)
    {
        if (dist[e[0]] != 1e9 &&
            dist[e[1]] > dist[e[0]] + e[2])
        {
            return {-1};
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;

    return dist;
}
