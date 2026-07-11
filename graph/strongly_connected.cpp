#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, stack<int> &st, int node, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto c : adj[node])
        {
            if (!vis[c])
                dfs(adj, st, c, vis);
        }
        st.push(node);
    }
    void dfs2(vector<vector<int>> &adj, int node, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto c : adj[node])
        {
            if (!vis[c])
                dfs2(adj, c, vis);
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        stack<int> st;
        int n = adj.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(adj, st, i, vis);
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto &c : adj[i])
            {
                graph[c].push_back(i);
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                dfs2(graph, node, vis);
                ans++;
            }
        }
        return ans;
    }
};