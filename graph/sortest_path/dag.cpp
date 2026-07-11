#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<pair<int, int>>> &adj,
         vector<int> &vis, stack<int> &st)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (!vis[v.first])
            dfs(v.first, adj, vis, st);
    }
    st.push(u);
}
vector<int> shortestPathDAG(int V, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(V);
    for (auto e : edges)
        adj[e[0]].push_back({e[1], e[2]});
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, adj, vis, st);
    vector<int> dist(V, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (dist[u] == 1e9)
            continue;
        for (auto v : adj[u])
        {
            dist[v.first] = min(dist[v.first],
                                dist[u] + v.second);
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;
    return dist;
}
