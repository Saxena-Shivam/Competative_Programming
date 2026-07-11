
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPathBFS(int V, vector<vector<int>> &adj, int src)
{
    vector<int> dist(V, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
